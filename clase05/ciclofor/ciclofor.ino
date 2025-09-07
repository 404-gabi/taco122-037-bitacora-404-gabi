int numerosLost[] = { 4, 8, 15, 16, 23, 42 };
// int ledPins [] = {3, 5, 6, 9, 10, 11}
// nos ahorramos ledpin 0 = 3

String lineasPoema[] =
 {

  "señor", // 0
  "la jaula se ha vuelto pájaro", // 1
  "y se ha volado", // 2
  "y mi corazón está loco", // 3
  "porque aulla a la muerte", // 4
  "y sonríe detrás del viento", // 5
  "a mis delirios", // 6
 };


 void setup() {
  Serial.begin(9600);

  // para usar la variable en un array
  // debo ir a buscarlo con nombreArray[indice]

  Serial.println(numerosLost[0]);

  //Serial.println(numerosLost[1]);
  //Serial.println(numerosLost[2]);
  // evitamos este tedio usando un ciclo for / iterativo, va a repetir de un punto a otro
  // repite el mismo proceso para las variables

  // para declarar un ciclo for, tenemos que tener claras 3 cosas
  // 1. donde inicia → 0 → para esto se crea una variable local
  // 2. donde termina → 5
  // 3. como varia → de 1 en 1

  Serial.println("empezando ciclo for");
  for (int i = 0; i <= 5; i++) {  // i++ significa más un

    Serial.println(numerosLost[i]);
    delay(1000);
    Serial.println("salí del ciclo for");

    // se puede hacer que una variable vaya de uno en uno, que tire una moneda, etc
  }
}

void loop() {

  // este ciclo for sale cuando el i sea mayor o igual a 7

  Serial.println("empezando ciclo for");

  for (int i = 0; i <= 7; i++) {  // i++ significa más un
    Serial.println(lineasPoema[i]);
    delay(1000);

  }
 Serial.println("salí del ciclo for");

};
