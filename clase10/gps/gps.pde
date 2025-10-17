// mi primer GPS/SensorLogger

Table recorridoGabi; // creamos una instancia de la clase tabla

// variables para recorrer la tabla
int contadorX = 0;
int contadorY = 0;

// donde voy a ubicar cada coordenada
float posicionX = 0;
float posicionY = 0;

float posicionXMap= map(posicionX,0,100,0,width);
float posicionYMap= map(posicionY,0,100,0,height);


void setup () {
  size(300,300);
  background(255);
  
  // header dice que ignore la primera fila
  recorridoGabi = loadTable("hojaProcesada.csv", "header");
  
  
  // me dice cuantas filas hay
  println("filas y columnas:");
  println(recorridoGabi.getRowCount());
  println(recorridoGabi.getColumnCount());
  
  // para saber que valores hay en una fila especifica
  print("en la celda (0,0) está el valor: ");
  println(recorridoGabi.getFloat(0,0));
  
  print("en la celda (0,1) está el valor: ");
  println(recorridoGabi.getFloat(0,1));

}

void draw() {
  contadorX++; // incrementa el contador X en 1
  contadorY++; // incrementa el contador Y en 1
  
  // actualizar posicion X e Y según la tabla y el contador
  posicionX = recorridoGabi.getFloat(contadorX, 1);
  posicionY = recorridoGabi.getFloat(contadorY, 0);
  
  // vamos a intentar depslegar la imagen de manera estática 
  circle(posicionX, posicionY, 2);
  
}
