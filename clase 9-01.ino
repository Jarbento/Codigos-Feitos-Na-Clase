/*
 *Programa para crear un semáforo.
 *Usaremos un LED RGB para a simulación, controlando o brillo de cada LED mediante unha
 * salida analóxica.
 *
 * Autor: Francisco Mos.
 * Data: Xaneiro de 2024.
 * Actualización:
*/

//Declaración de salidas analóxicas.
#define RED 6 
#define BLUE 5
#define GREEN 3

//Declaracion de variables.
int TEMPO = 2000;

void setup(){
  //Non se declaran as salidas analóxicas.
  
}

void loop() {
  //Encenda en verde un tempo determinado.
  //Encende en ambar 1/3 do verde.
  //Encende en verde o mismo que en vermello.
  setColor(30,165,240);
  
}
  
void setColor(int R, int G, int B) {
  analogWrite(RED, R);
  analogWrite(GREEN, G);
  analogWrite(BLUE, B);
  
}
  
 
  
 
/*
  digitalWrite(RED,255);
  delay(TEMPO);
  digitalWrite(RED,0);
  digitalWrite(GREEN,255);
  delay(TEMPO);
  digitalWrite(GREEN,190);
  digitalWrite(RED,255);
  delay(TEMPO/3);
  digitalWrite(GREEN,0);
  */
