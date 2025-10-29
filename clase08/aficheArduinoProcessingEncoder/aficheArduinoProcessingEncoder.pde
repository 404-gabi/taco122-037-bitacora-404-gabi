import processing.serial.*;

Serial arduino;
float radio = 0; // valor inicial q es recibido desde Arduino
PGraphics afiche; // capa de gráficos
PGraphics mascara; // " " q funciona como máscara para q se revele el texto
// pgraphics waossssssss

void setup() {
  size(600, 700);
  noStroke(); // sin contorno
  background(0);

  // comunicación serial con arduino
  printArray(Serial.list());
  arduino = new Serial(this, Serial.list()[0], 9600);
  arduino.bufferUntil('\n');

  // config. afiche en una capa de gráficos
  // repetir el afiche..............................
  afiche = createGraphics(width, height);
  afiche.beginDraw();
  afiche.background(255); // blanco
  afiche.fill(0);         // texto negro
  afiche.textSize(30);
  afiche.text("El verdadero realismo consiste", 17, 40);
  afiche.textSize(80);
  afiche.text("en revelar", 150, 100);
  afiche.textSize(30);
  afiche.text("las cosas sorprendentes", 280, 160);
  afiche.text("que la costumbre", 350, 180);
  afiche.text("mantiene ocultas", 230, 270);
  afiche.text("y nos impide", 140, 370);
  afiche.textSize(60);
  afiche.text("ver", 40, 450);
  afiche.endDraw();
// shoutout Jean Cocteau 

  // config. máscara
  mascara = createGraphics(width, height);
}

void draw() {
  background(0); // negro (oculta todo)

  // la creación d la máscara
  mascara.beginDraw();
  mascara.background(0);   // todo negro (lo oculto)
  mascara.noStroke();
  mascara.fill(255);      // área blanca  (lo visible)
  mascara.ellipse(width/2, height/2, radio * 2, radio * 2); // círculo blanco centrado
  mascara.endDraw();

  PImage revelado = afiche.get(); // se obtiene la imagen waos obselva 
  revelado.mask(mascara.get()); // aquí solo se ve la parte blanca del circulo 

  // q se revele waos
  image(revelado, 0, 0);
}

void serialEvent(Serial p) {
  String data = trim(p.readStringUntil('\n'));
  if (data != null && data.length() > 0) {
    try {
      radio = float(data);
      println("Radio recibido: " + radio);
    } catch(Exception e) {
      println("Error leyendo dato serial: " + data);
    }
  }
}
