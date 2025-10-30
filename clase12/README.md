IDEA 1 ⋆⭒˚｡⋆ 

concepto: generar sonido a partir de movimiento del agua/luz mediante LDR (arduino) y una onda sinusoidal desde processing 


diagrama de flujo: 

// pendiente diagramar en mermaid chart

luz prendida x default 

motores se mueven > el agua se mueve > se proyectan sombras y luz > LDRs reciben esto > se procesan > se envían a processing > onda sinusoidal suena según las variaciones de los ldr (amplitud, frecuencia, etc) 


materialidades: madera (pino cepillado?, acrílico, LDR, Arduino, ampolleta, cables (omgggg)

Hardware: Arduino Uno (x2) uno para controlar los motores y otro el multiplexor

2 motores

 Multiplexor CD74hc 4067
 
 Salida de audio
 
Software: Arduino IDE, Processing o Pure data 

Boceto de montaje: [bocetodemontaje](https://github.com/404-gabi/taco122-037-bitacora-404-gabi/blob/d45b898252e6cb106dcfa17d38da2796205decb9/clase12/imagenes/IMG_1558.jpeg)









IDEA 2 ⋆⭒˚｡⋆ (intermedio)
concepto: que la estridulación de los grillos haga haikus, bajo la premisa de que son un motivo recurrente de estos poemas, pero qué pasaría si el motivo es el que suscita estos versos desde los rincones de la urbanización

// a partir de observaciones en el cerro san Cristóbal, donde a partir de cierta hora solo se escuchan grillos 

ref: Computerized Japanese Haiku / cybernetic serendipity

diagrama de flujo: 
grabación de sonidos de grillos (cri cri) > procesamiento del sonido en arduino, puede convertirse en números? en base a amplitud, ritmo > se generan haikus a partir de esos datos/sonido mediante palabras aleatorias guardadas en arduino > aparecen en el LCD > tmb salida de audio (audifonos?) 

x default pantalla OLED con un grillo pixelado

materialidades: madera terciada (caja de 20x27x10cm) 
                (ó acrílico) 
                pantalla OLED (1) 
                pantalla LCD 16 x 2
                cables 

Hardware: Arduino uno, módulo de micrófono?, módulo de mp3?, pantalla OLED, pantalla LCD, salida de audio 

Software: Arduino IDE

Boceto de montaje:




IDEA 3 ⋆⭒˚｡⋆ (fácil?)
concepto: trabajar en base a una cita de un libro, imaginando desde las palabras, qué es algo y qué es nada

dice:
“Una rueda que pueda girar sin que nada se mueva con ella, no forma parte del mecanismo”
para luego decir: 
> “¡No es un algo, pero no es una nada tampoco!” Ludwig Wittgenstein, Investigaciones filosóficas 1998, citado en “aceleracionismo: estrategias para una transición hacia el postcapitalismo” p. 169

diagrama de flujo:

materialidades: madera terciado
                hilo corrido zincado
                cables
                pantalla LCD 16x2 
                Motor + rueda
                circuito análogo 555 + 4017
                sensor ultrasónico 

Hardware: Arduino UNO ó nano
          Motor
          Circuito análogo
          Pantalla LCD 
          Sensor ultrasónico

Software: Arduino IDE

Boceto de montaje:


