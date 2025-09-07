int potPin = A0;
int ledPin = 7;
int valorPot = 0;
int potMapeado = 0; //variable para cambiar el rango
int tiempoParpadeo = 100; //variable para controlar el tiempo de parpadeo 

void setup() {
  Serial.begin(9600);
(ledPin, OUTPUT);
}

void loop() {

  tiempoParpadeo = potMapeado;

//VAMOS A HACER EL BLINK AQUÍ 
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);

  valorPot = analogRead(potPin);
 potMapeado = map(valorPot, 0, 1023, 0, 2000);
 Serial.println(tiempoParpadeo);
 
}
