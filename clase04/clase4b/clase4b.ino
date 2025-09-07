int tiempo = 0;
int potPin = A0;
int ledPin = 7;
int intervalo = 1000;
int valorPot = 0;
int potMapeado = 0;
bool estadoLed = 0;

unsigned long tiempoActual = 0;
unsigned long tiempoAnterior = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
tiempoActual = millis();
valorPot = analogRead(potPin);
potMapeado = map(valorPot, 0, 1023, 100, 2000);

if (tiempoActual - tiempoAnterior > intervalo){
  estadoLed = !estadoLed;
  Serial.println("se cumplió la condición");
  tiempoAnterior = tiempoActual;
}
digitalWrite(ledPin, estadoLed);

}
