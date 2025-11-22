/*
 proyecto grillos recitando haikus !

 ⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢻⣿⡗⢶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣄
⠀⢻⣇⠀⠈⠙⠳⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⠶⠛⠋⣹⣿⡿
⠀⠀⠹⣆⠀⠀⠀⠀⠙⢷⣄⣀⣀⣀⣤⣤⣤⣄⣀⣴⠞⠋⠉⠀⠀⠀⢀⣿⡟⠁
⠀⠀⠀⠙⢷⡀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠋⠀⠀
⠀⠀⠀⠀⠈⠻⡶⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣠⡾⠋⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣼⠃⠀⢠⠒⣆⠀⠀⠀⠀⠀⠀⢠⢲⣄⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢰⡏⠀⠀⠈⠛⠋⠀⢀⣀⡀⠀⠀⠘⠛⠃⠀⠀⠀⠈⣿⡀⠀⠀⠀⠀
⠀⠀⠀⠀⣾⡟⠛⢳⠀⠀⠀⠀⠀⣉⣀⠀⠀⠀⠀⣰⢛⠙⣶⠀⢹⣇⠀⠀⠀⠀
⠀⠀⠀⠀⢿⡗⠛⠋⠀⠀⠀⠀⣾⠋⠀⢱⠀⠀⠀⠘⠲⠗⠋⠀⠈⣿⠀⠀⠀⠀
⠀⠀⠀⠀⠘⢷⡀⠀⠀⠀⠀⠀⠈⠓⠒⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠁⠀⠀⠀

*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h> // esto sirve para almacenar datos en PROGMEM

#define OLED_RESET -1
#define BUTTON_PIN 2
#define BUZZER_PIN 8  // pin donde conectar el buzzer

Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);
LiquidCrystal_I2C lcd(0x27, 16, 2); // dirección típica del LCD


/*

versos en estructura métrica del haiku 5-7-5
 PROGMEM es para guardar datos en la memoria flash en lugar de la RAM, es ideal para datos que no cambian
 (versos generados por chatyipiti, quizás haga una búsqueda en haikus)
*/

const char verso1[][20] PROGMEM = {
  "Luz entre hojas",
  "Sopla la brisa",
  "Canta el grillo",
  "Rosa dormida",
  "Tierra mojada",
  "Sombra de luna",
  "Lago sin eco",
  "Piedra que sueña",
  "Vuela la hoja",
  "Campo vacio"
};

const char verso2[][25] PROGMEM = {
  "Noche que respira",
  "Sombra que camina",
  "Río sin luna",
  "Ecos del viento",
  "Sueños que tiemblan",
  "Vuela el silencio",
  "Cruza la neblina",
  "Brilla el rocío",
  "Ojos del bosque",
  "Tiempo sin nombre"
};

const char verso3[][20] PROGMEM = {
  "Sueña la tierra",
  "Silencio tibio",
  "Todo descansa",
  "Nada se queda",
  "Todo regresa",
  "Luz que se apaga",
  "Cae la estrella",
  "Brilla el olvido",
  "Fin de la lluvia",
  "Vuelve la calma"
};

const int total1 = sizeof(verso1) / sizeof(verso1[0]);
const int total2 = sizeof(verso2) / sizeof(verso2[0]);
const int total3 = sizeof(verso3) / sizeof(verso3[0]);

char buffer[30]; // buffer temporal para leer desde PROGMEM

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  randomSeed(analogRead(A0)); // semilla aleatoria para que los haikus no se repitan siempre igual

  lcd.setCursor(0, 0);
  lcd.print("projeito grillo");
  lcd.setCursor(0, 1);
  lcd.print("presionar boton :)");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    reproducirGrillos();
    mostrarHaiku();
    animarOLED();

    delay(7000);
    lcd.clear();
    display.clearDisplay();
    lcd.setCursor(0, 0);
    lcd.print("presiona boton");
  }
}

/*
 configuración más funcional
 reproducirGrillos (buzzer) + mostrarHaikus + leer verso 
 (falta ver detalles de animación OLED)
*/

void reproducirGrillos() {
  for (int i = 0; i < 10; i++) {
    int tono = random(3500, 5000); // tonos agudos:v
    tone(BUZZER_PIN, tono, 50);
    delay(random(80, 200));
  }
  noTone(BUZZER_PIN);
}


void mostrarHaiku() {
  lcd.clear();

//  aki se eligen versos al azar
  int i1 = random(total1);
  int i2 = random(total2);
  int i3 = random(total3);

  lcd.clear();
  lcd.setCursor(0, 0);
  leerVerso(verso1[i1]);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  leerVerso(verso2[i2]);
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 0);
  leerVerso(verso3[i3]);
}

void leerVerso(const char *verso) {
  strcpy_P(buffer, verso);
  lcd.print(buffer);
}


// aki iría la animación OLED si tuviera una jejej

void animarOLED() {
  for (int i = 0; i < 12; i++) {
    display.clearDisplay();
    display.fillCircle(20 + i * 8, 40 - (i % 2) * 6, 4, WHITE);
    display.display();
    delay(150);
  }
  display.clearDisplay();
  display.display();
}

