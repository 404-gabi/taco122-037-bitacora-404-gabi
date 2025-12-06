/*
 proyecto grillos grillando haikus ! 
 
 neoHaikus
 reinvención de haikus 
 ¿qué pasaría si uno de los motivos recurrentes del haiku es el que los suscita?
 (la idea original era trabajar a partir de una recopilación de sonidos de grillos, grabados en el cerro)

 al encontrar sonidos de grillos online, surge esto de ahora se pueden escuchar los grillos mediante internet waos!! :O
 y muchas cosas más, marcando una diferencia entre la relación que tenemos con la naturaleza / tecnología

*/
 
 // librerías
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <avr/pgmspace.h>
#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

#define OLED_RESET -1 
#define BUTTON_PIN 2

LiquidCrystal_I2C lcd(0x27, 16, 2); // dirección típica del lc

SoftwareSerial Serial1(4, 5);
DFRobotDFPlayerMini myDFPlayer;

/*
versos en estructura métrica del haiku 5-7-5
 PROGMEM es para guardar datos en la memoria flash en lugar de la RAM, es ideal para datos que no cambian
 (versos generados por chatyipiti, quizás haga una búsqueda en haikus)

 *NOTA: para la evaluación, no sucedía la acción de aleatorizar, puede haber sido un problema de conexión
  del botón o la semilla random 
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
  "Rio sin luna",
  "Ecos del viento",
  "Sueños que tiemblan",
  "Vuela el silencio",
  "Cruza la neblina",
  "Brilla el rocio",
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

  lcd.init();
  lcd.backlight();

  randomSeed(analogRead(A0)); // semilla aleatoria 

// dfPlayerMini
  Serial1.begin(9600);
  myDFPlayer.begin(Serial1);
  delay(2000);

  myDFPlayer.volume(20);

// lcd
  lcd.setCursor(0, 0);
  lcd.print("neoHaikus! :)");
  lcd.setCursor(0, 1);
  lcd.print("presiona boton");
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    reproducirGrillos();
    mostrarHaiku();
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("presiona boton:)");
  }
}

/*
 configuración más funcional
 reproducirGrillos (DFPlayerMini) + mostrarHaikus + leer verso 
 (falta ver detalles de animación OLED o simplemente eliminarla la vd)

 para DFPlayer mini, la tarjeta SD tiene que estar formateada a FAT16
 tiene que tener una carpeta llamada 01 y dentro los archivos de audio tienen que estar en formato mp3
 y categorizados como "001","002"... etc
 idealmente no tienen que durar más de 10 segundos, los haikus duran aprox eso

  https://www.tecneu.com/blogs/tutoriales-de-electronica/como-utilizar-el-dfplayer-mini-con-arduino-para-proyectos-de-audio?srsltid=AfmBOoqOb4sVc41Fz0oilgc8QG67CMCdjiMMJ5aY49VQuRTp9I9ftgL5
  página que me fue útil para aprender a utilizar el módulo

*/

void reproducirGrillos() {
  int pista = random(1, 4);
  myDFPlayer.playFolder(1, pista);
  delay(3000);
}

void mostrarHaiku() {
  int i1 = random(total1);
  int i2 = random(total2);
  int i3 = random(total3);

  lcd.clear();
  escribirMaquina(verso1[i1]);
  delay(1500);

  lcd.clear();
  escribirMaquina(verso2[i2]);
  delay(1500);

  lcd.clear();
  escribirMaquina(verso3[i3]);
}

// nueva adición waos!!

void escribirMaquina(const char *verso) {
  strcpy_P(buffer, verso);
  
  int cursor = 0; // posición del cursor en la línea
  lcd.setCursor(0, 0);
  
  for (int i = 0; buffer[i] != '\0'; i++) {
    lcd.print(buffer[i]); // se imprime un carácter del verso
    cursor++; // para saber cuantos carácteres hay escritos
    
    // si llegamos al límite de la primera línea (16 caracteres)
    if (cursor == 16) { // si se llega al límite de la primera línea del lcd (16) esto permite que no se corte la frase y se cambie a la segunda línea
      lcd.setCursor(0, 1); 
    }

    delay(120); 
  }
  
  // esta configuración hace este tipo "parpadeo"
  for (int j = 0; j < 3; j++) {
    lcd.cursor();  
    delay(200);
    lcd.noCursor(); 
    delay(200);
  }
}
