int ldrPin1 = A0;  // ldr 1
int ldrPin2 = A1;  // ldr 2

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int ldrValor1 = analogRead(ldrPin1); // ldr que va a controlar la frecuencia
  int ldrValor2 = analogRead(ldrPin2); // ldr que va a controlar la amplitud
  
  // enviar valores
  Serial.print(ldrValor1);
  Serial.print(",");
  Serial.println(ldrValor2);
  
  delay(50);  // para evitar saturar el puerto
}
