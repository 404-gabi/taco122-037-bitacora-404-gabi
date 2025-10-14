/**
 * código Getting Started with Capture + APUNTES 
 */

import processing.video.*; // librería (paquete de código)

Capture cam; // no es una variable pero se parece, es una Clase de tipo "capture"
// que estamos inicializando con el nombre "cam"


// creamos una variable de color
color c = color(255, 100, 0);

void setup() {
  size(640, 480); // tamaño de lienzo

  String[] cameras = Capture.list();

  if (cameras == null) {
    println("Failed to retrieve the list of available cameras, will try the default...");
    cam = new Capture(this, 640, 480);
  } else if (cameras.length == 0) {
    println("There are no cameras available for capture.");
    exit();
  } else {
    println("camaras disponibles");
    printArray(cameras);

   
    cam = new Capture(this, cameras[0]); // cantidad de cámaras disponible
;
  }

  // dalenoma 
  cam.start();
}

void draw() {
  if (cam.available() == true) {
    cam.read();
  }
  image(cam, 0, 0, width, height);
  // al omitir esta linea, queda la elipse "detectando" color / idea de sensor
  
  // vamos a actualizar la variable del color
  // que sea relativa a la posición del mouse
  
  // le doy la coordenada del pixel que marque el mouse
  // me devuelve el color en ese pixel 
  
  c = cam.get(mouseX,mouseY);
  
  // relleno del circulo
  // con el color de la variable c
  
  fill(c);
  ellipse(width/2, height/2, 300, 300);
  // se puede regular el tamaño d esto
  
  println(c);
  
}

// geo obs daniel cruz 
