int ldrPin = A0;
int valorLdr = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  valorLdr = analogRead(ldrPin);
  Serial.println(valorLdr);
  delay(100);

}
