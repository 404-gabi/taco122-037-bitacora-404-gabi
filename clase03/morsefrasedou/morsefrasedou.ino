int ledPin = 13;
//tiempos
int tiempoPunto = 100;
int separador = 50;
int tiempoRaya = 500;
int finCaracter = 100;
int espacio = 500;

void setup()
{
    pinMode(ledPin,OUTPUT);
    //9600 tasa de baudios
    Serial.begin(9600);
}

void loop()
{
// se acavoid

  e(); l(); 
  v(); e(); r(); d(); a(); d(); e(); r(); o(); 
  r(); e(); a(); l(); i(); s(); m(); o();
  c(); o(); n(); s(); i(); s(); t(); e(); 
  e(); n();
  r(); e(); v(); e(); l(); a(); r(); 
  l(); a(); s();
  c(); o(); s(); a(); s(); 
  s(); o(); r(); p(); r(); e(); n(); d(); e(); n(); t(); e(); s(); 
  q(); u(); e(); 
  l(); a(); 
  c(); o(); s(); t(); u(); m(); b(); r(); e(); 
  m(); a(); n(); t(); i(); e(); n(); e(); 
  o(); c(); u(); l(); t(); a(); s(); 
  y(); 
  n(); o(); s(); 
  i(); m(); p(); i(); d(); e();
  v(); e(); r(); 
  

    delay(finCaracter);
    Serial.println(" cierre");
}


void punto(){
    digitalWrite(ledPin,HIGH);
    Serial.println("punto");
    delay(tiempoPunto);
    digitalWrite(ledPin,LOW);
    delay(separador);
}

void raya(){
    digitalWrite(ledPin,HIGH);
    Serial.println("raya");
    delay(tiempoRaya);
    digitalWrite(ledPin,LOW);
}

void a(){
 punto(); raya();
}
void e(){
 punto();
}
void i(){
 punto(); punto();
}
void o(){
 raya(); raya(); raya();
}
void u(){
 punto(); punto(); raya();
}
void l(){
 punto(); raya(); punto(); punto();
}
void v(){
 punto(); punto(); punto(); raya();
}
void r(){
 punto(); raya(); punto();
}
void d(){
 raya(); punto(); punto();
}
void s(){
 punto(); punto(); punto();
}
void n(){
 raya(); punto();
}
void y(){
 raya(); punto(); raya(); raya();
}
void q(){
 raya(); raya(); punto(); raya();
}
void m(){
 raya(); raya();
}
void c(){
 raya(); punto(); raya(); punto();
}
void p(){
 punto(); raya(); raya(); punto();
}
void t(){
 raya(); 
}
void b(){
 raya(); punto(); punto(); punto();

}
//El verdadero realismo consiste en revelar las cosas sorprendentes que la costumbre mantiene ocultas y nos impide ver
// . .-.. / ...- . .-. -.. .- -.. . .-. --- / .-. . .- .-.. .. ... -- --- / -.-. --- -. ... .. ... - . /
// . -. / .-. . ...- . .-.. .- .-. / .-.. .- ... / -.-. --- ... .- ... / ... --- .-. .--. .-. . -. -.. . -. - . ... 
// --.- ..- . / .-.. .- / -.-. --- ... - ..- -- -... .-. . / -- .- -. - .. . -. . / --- -.-. ..- .-.. - .- ... 
// -.-- / -. --- ... / .. -- .--. .. -.. . / ...- . .-.