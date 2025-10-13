// ola soy un pseudocodigo / clase07

// declarar variables, definir donde voy a guardar la información

// ¿qué se necesita para declarar una variable?
// el tipo de variable
// (número pequeño, grande, sí o no, palabra, caracter, etc)
// si tiene comas, debo usar float
// si son palabras, String
// si son sí o no, bool 

// es saludable iniciar las variables en algún número / contador que parta de 0
// en general se hace ANTES del setup ()
// ámbito


int contador = 0; 
// setup y loop lo van a poder usar 

int pinLed = 9; // pin donde se conectaría un led
int pinPot = A0; // pin donde hay un potenciómetro

int informacion = 0; // variable donde se guardará la info del mundo


void setup() {
  // inicializar, preparar lo que luego será utilizado

  // inicializamos que queremos trabajar con el serial 
  Serial.begin(9600); 

  // decidimos si los pines van a ser inputs u outputs
  // si escribo información hacia afuera ¿dónde se escribe?

  pinMode(pinLed, OUTPUT);

  //los analogIn no deben ser inicializados como entradas 
  

}

void loop() {
  
  // usar variable para guardar la información del mundo :o 
  informacion = analogRead(A0);

  // ahora información conoce el mundo (en este caso, 0 a 1023)

  // actualizar, operar, preguntar a la info que estoy recibiendo

  // ¿es mayor o menor que otra cosa?
  // ¿quiero que sea proporcional a otro rango?
  // ¿quiero saber en qué lugar está?

comparar();

  // finalmente, uso la información
  // por ejemplo, muestra el contador en una pantallita

  display.Pantallita(informacion);
  
  // o quiero que un led se prenda según la información
  digitalWrite(pin del led, informacion);

}

void comparar();

  // quiero saber si es mayor o menor que un umbral
  int umbral = 100;
  if (informacion >= umbral){
    // haz algo
    // por ejemplo, que un contador crezca
    contador = contador + 1;
  } else {
    // haz otra cosa
    // (que el contador baje)
    contador = contador - 1;
  
  }
  





