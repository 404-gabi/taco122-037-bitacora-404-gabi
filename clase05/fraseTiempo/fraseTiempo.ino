// usé de guía el código de terroiblea en github, mezclado con lo visto
// en clases

//bibliotecas
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
// #define OLED_RESET -1
#define OLED_ADDR 0x3C  // dirección I2C

Adafruit_SSD1306 pantallita(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire);

//pin potenciómetro
const int pinPot = A0;

// frase random 
// array palabras, texto fijo 
const char* palabras[] = {
  "lo onirico",
  "deviene",
  "al",
  "caos,",
  "inminente-mente",
  "al",
  "colapso",
  "[de",
  "la",
  "naturaleza]",
};

// array de frases
const int totalPalabras = sizeof(palabras) / sizeof(palabras[0]);

void setup() {
  // iniciar la pantalla
  if (!pantallita.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.begin(9600);
    Serial.println(F("No se encontró pantalla SSD1306")) ;
    for(;;);  // se detiene??dou
  }
  pantallita.clearDisplay();                     // limpiar buffer
  pantallita.setTextSize(2);                     // tamaño del texto
  pantallita.setTextColor(SSD1306_WHITE);        // color del texto
  pantallita.setCursor(0, 0);  // posición (x,y)
  pantallita.println("iniciando...");                 // escribir texto
  pantallita.display();                          // mostrar en pantalla
  delay(1000);
}


void loop() {
  int valorPot = analogRead(pinPot); // para leer el potenciómetro

  int potMapeado = map(valorPot, 0, 1023, 0, totalPalabras - 1);

  pantallita.clearDisplay();
  pantallita.setCursor(0, 20);
  pantallita.setTextSize(2);
  pantallita.println(palabras[potMapeado]);
  pantallita.display();
  delay(1000);
}


