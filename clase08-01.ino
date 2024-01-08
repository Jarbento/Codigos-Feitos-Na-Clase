/*Programa que ilumina con diferentes intensidades un led,
 *
 *O programa deve definir un número limitado de niveles
 *de luminosidade empezando desde 0, subir de intensidade.
 *Ao chegar ao máximo debe disminuir a intensidade ata 0.
 *
 *Criterios acercac do código:
 *Ten que ser lexible
 *O mantemento debe ser omais sinxelo posible
 
*/

#define LED 11 //Saida analóxica

int tempo = 500;
int nivel = 0;
int incremento = 17;

void setup(){
  // As entradas analóxicas non se declaran no setup()
  nivel = 0;
  
  
}

void loop(){
  Serial.print("Nivel de luminosidade: ");
  Serial.println(nivel);
  analogWrite(LED, nivel);
  delay(tempo);
  
  if(nivel + incremento < 0 || nivel + incremento > 255) {
    incremento = -incremento;
  }
  nivel += incremento;
}
  
  /*
  if (nivel + incremento > 255) {
    incremento = -incremento;
  }
  
  else if (nivel + incremento < 0) {
    incremento = -incremento;
  }
 
  nivel += incremento;
  
}
*/
  
  
  /*
  if (nivel > 255) {
    incremento = -51;
  }
  else if (nivel < 0) {
    incremento = 51;
  } 
  nivel += incremento; // nivel = nivel + incremento
  Serial.print("Nivel de luminosidade: ");
  Serial.print(nivel);
  
} 
*/
  


/*
int tempo = 200;

//Declaración de niveis
int nivel00 = 0;
int nivel01 = 51;
int nivel02 = 102;
int nivel03 = 153;
int nivel04 = 204;
int nivel05 = 255;
  
void setup(){
  // As entradas analóxicas non se declaran no setup()
  
}

void loop () {
  analogWrite(LED, nivel00);
  delay(tempo);
  analogWrite(LED, nivel01);
  delay(tempo);
  analogWrite(LED, nivel02);
  delay(tempo);
  analogWrite(LED, nivel03);
  delay(tempo);
  analogWrite(LED, nivel04);
  delay(tempo);
  analogWrite(LED, nivel05);
  delay(tempo);
  analogWrite(LED, nivel04);
  delay(tempo);
  analogWrite(LED, nivel03);
  delay(tempo);
  analogWrite(LED, nivel02);
  delay(tempo);
  analogWrite(LED, nivel01);
  delay(tempo);
  analogWrite(LED, nivel00);
  delay(tempo);            
             
  
}
*/
