// configuración encoder
#define CLK 2
#define DT 3
#define SW 4

int lastStateCLK; // ult estado leído de CLK (aquí m ayudo chatyipiti)
int radio = 100;   // valor que controlará el círculo en processing
bool pulsador = false; // controla el botón

// límites del valor del radio
const int RADIO_MIN = 0;
const int RADIO_MAX = 1000;

void setup() {
  // config. pines encoder como entradas
  pinMode(CLK, INPUT_PULLUP); // aki igual
  pinMode(DT, INPUT_PULLUP);
  pinMode(SW, INPUT_PULLUP);

  lastStateCLK = digitalRead(CLK);

  Serial.begin(9600); // com. serial con processing 
}

void loop() {
  int currentStateCLK = digitalRead(CLK);

  // se detecta la rotación del encoder
  if (currentStateCLK != lastStateCLK && currentStateCLK == HIGH) {
    if (digitalRead(DT) != currentStateCLK) { // determina la dirección
      radio -= 10; // reducir radio a la izq
    } else {
      radio += 10; // aumentar radio a la derecha
    }

    //  rango 
    if (radio < RADIO_MIN) radio = RADIO_MIN;
    if (radio > RADIO_MAX) radio = RADIO_MAX;


    Serial.println(radio); // enviar valor a processing
  }

  lastStateCLK = currentStateCLK;

  // con el pulsador se reinicia el radio
  if (digitalRead(SW) == LOW && !pulsador) {
    radio = 100; // radio inicial
    Serial.println(radio);
    pulsador = true;
  } else if (digitalRead(SW) == HIGH) {
    pulsador = false;
  }

  delay(2); // pausa para q el encoder no se canse 
}
