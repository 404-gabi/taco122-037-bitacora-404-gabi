import processing.serial.*;

Serial miPuerto;   // objeto para la conexión
String datos;      
int valor;

void setup() {
  size(400, 200);
  println(Serial.list());         // lista d puertos
  miPuerto = new Serial(this, "COM3", 9600); // puerto compu 
  miPuerto.bufferUntil('\n');          
}

void draw() {
  
 // utilizar variable valor
  background(200);
  fill(50);
  ellipse(width/2, height/2, valor,valor);   
}

void serialEvent(Serial miPuerto) {
  datos = miPuerto.readStringUntil('\n');  // lee la línea completa
  if (datos != null) {
    datos = trim(datos);                   // limpia espacios
    valor = int(datos);                    // convierte a número
  }
  println(valor);
  
  
}

// al iluminar el ldr se achica douuuuuuuuuuuuu}
