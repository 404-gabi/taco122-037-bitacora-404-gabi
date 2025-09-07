#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Definir tamaño del display
#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64

// Dirección I2C típica (0x3C o 0x3D)
#define OLED_ADDR 0x3C  

// Crear objeto display // esclave dou
Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire); 

int posicionVertical = 0; 

void setup() {
  // Iniciar la pantalla
  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.begin(9600);
    Serial.println(F("No se encontró pantalla SSD1306"));
    for(;;); // se queda detenido
  }

  display.clearDisplay();             // limpiar buffer
  display.setTextSize(2);             // tamaño del texto
  display.setTextColor(SSD1306_WHITE);// color del texto
  display.setCursor(10, 25);          // posición (x,y)
  display.println("se acabo");      // escribir texto
  display.display();                  // mostrar en pantalla ES CLAVE 
}

void loop() {
  posicionVertical++; // q pV cambie en uno 
   display.clearDisplay();             // limpiar buffer
  display.setTextSize(2);             // tamaño del texto
  display.setTextColor(SSD1306_WHITE);// color del texto
  // el componente vertical dependa de posicion vertical 
  display.setCursor(ANCHO_PANTALLA/2, posicionVertical);          // posición (x,y)
  display.println("dou");      // escribir texto
  display.display();      

  if (posicionVertical > ALTO_PANTALLA){
    posicionVertical = 0;
  }
  delay(100);
}

