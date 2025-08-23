
void setup() {
  size(600, 700); // tamaño do lienzo
  colorMode(RGB);
  noStroke();
}

void draw () {
  // y aquí otras cosas
  // con el color al inicio del draw borro el fondo
  background(46, 46, 46);

  //255, 252, 220
  fill(255, 252, 220);
  rect(10, 10, 580, 680);
  
  fill(46, 46, 46);
  triangle(600, 400, 600, 250, 244, 500);
  
  fill(mouseX, mouseY, 90);
  circle(300, 700, 582);

  fill(46, 46, 46);
  triangle(0, 170, 0, 50, 244, 220);

fill(46, 46, 46);
circle(mouseX, mouseY, 100);

  fill(48, 48, 48);
  textSize(30);
  text("El verdadero realismo consiste", 17, 40);

  fill(48, 48, 48);
  textSize(80);
  text("en revelar", 150, 100);

  fill(255, 252, 220);
  textSize(30);
  text("las cosas sorprendentes", 280, 160);

  fill(255, 252, 220);
  textSize(30);
  text("que la costumbre", 350, 180);

  fill(255, 252, 220);
  textSize(30);
  text("mantiene ocultas", 230, 270);

  fill(255, 252, 220);
  textSize(30);
  text("y nos impide", 140, 370);

  fill(48, 48, 48);
  textSize(60);
  text("ver", 40, 450);

 fill(255, 117, 90);
  textSize(30);
  text("ola", 270, 550);
  // el verdadero realismo consiste en revelar las cosas
  // sorprendentes que la costumbre mantiene ocultas
  // y nos impide ver
}
