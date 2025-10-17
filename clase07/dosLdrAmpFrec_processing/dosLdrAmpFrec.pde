import processing.serial.*;
import processing.sound.*;

SinOsc sine;
Serial myPort; 
int ldrValue1 = 0;  // ldr para frecuencia
int ldrValue2 = 0;  // ldr para amplitud

void setup() {
  size(640, 360);
  background(255);
  
  // OSCILADOR
  sine = new SinOsc(this);
  sine.play();
  
  String portName = Serial.list()[0]; // en mi caso es el COM3, en el listado sale que corresponde al 0 tmb depende de q pc esté usando
  myPort = new Serial(this, portName, 9600);
}

void draw() {
  if (myPort.available() > 0) {
    String input = myPort.readStringUntil('\n'); // leer datos hasta el salto de línea
    if (input != null) {
      input = trim(input);  
      String[] values = split(input, ',');  

      if (values.length == 2) {
        
        ldrValue1 = int(values[0]);  //  frecuencia
        ldrValue2 = int(values[1]);  // amplitud
      }
    }
  }

  // mapear el valor del ldr2 para la amplitud entre 0.0 y 1.0
  float amplitude = map(ldrValue2, 0, 1023, 1.0, 0.0); // map respectivo a valores del ldr 0, 1023
  sine.amp(amplitude);

  // mapear el valor del ldr1 para la frecuencia entre 80Hz y 1000Hz
  float frequency = map(ldrValue1, 0, 1023, 80.0, 1000.0);
  sine.freq(frequency);
}
