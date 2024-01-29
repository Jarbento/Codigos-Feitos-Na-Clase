/*
 *Programa que mapea a entrada de un potenciometro a 5 cores.
 *Os leds seleccionados seran controlados apartires dunha entrada
 *analóxica, sendo esta un potenciómetro.
 *As saidas seran un numero determinado de niveis, que simularemos con
 *diferentes LEDs.
*/

//Definimos as variables de salida dixitais.
#define RED 6 
#define BLUE 5
#define GREEN 3

//Definimos as variables de entrada analóxicas.
#define POT A0


//Declaramos variables.
int tempo = 200;
int pot = 0;
int nivel = 0;
int nNiveis = 5; //Numero máximo de valores que toma a variable nivel.
unsigned long nCores = (unsigned long) 256*256*256-1;
unsigned long cor = -1;
byte r, g, b = -1;

// Cores RGB: 256*256*256 = 16 777 216
// Separar colores en R G B
// r = cor >> 16;
// g = cor >> 8;
// b = cor;

// Alternativa redundante
// r = (cor & 0xff0000);
// g = (cor & 0x00ff00);
// b = (cor & 0x0000ff);

void setup(){
  //As entradas digitales non se declaran.
  Serial.begin(9600);
}

void loop() {
  pot = analogRead(POT);
  nivel = map(pot, 0, 1023, 0, nNiveis-1);
  cor = map(nivel, 0, 5, 0, nCores);
  
  Serial.print("Cor:"), Serial.print(cor); 
  Serial.print(" HEX:"), Serial.print(cor,HEX);
  Serial.print(" BIN:"), Serial.println(cor,BIN);
}

/*
void loop() {
  pot = analogRead(POT);
  nivel = map(pot, 0, 1023, 0, nNiveis);
  
  switch(nivel) {
    case 0:
     setVermello();
     break;
    case 1:
     setAmbar();
     break;
    case 2:
     setVerde();
     break;
    case 3:
     setAzul();
     break;
    case 4:
     setBlanco();
     break;
  
  }
}
  
  //Funcións auxiliares.
  void setVermello() {
   setColor(255,0,0);
  }
  void setVerde() {
   setColor(0,255,0);
  }
  void setAzul() {
   setColor(0,0,255);
  }
  void setAmbar() {
   setColor(255,191,0);
  }
  void setBlanco() {
   setColor(255,255,255);
  }
  void setOff() {
   setColor(0,0,0);
  }
  void setColor(int R, int G, int B) {
   analogWrite(RED, R);
   analogWrite(GREEN, G);
   analogWrite(BLUE, B);
  }

/*
void loop(){
  //Ler o valor do potenciómetro, creamos unha variable para a lectura.
  pot = analogRead(POT);
  Serial.print("Valor leido:"); Serial.println(pot);
  Serial.print("Valor de tension:"); Serial.println(pot = 4.887585);
  Serial.println("mV");
  delay(tempo);
  
  //Asignar un nivel (unha cor) (cinco niveis).
  //Escribir o valor no led rgb.
  if(pot >= 0 && pot < 204) {
    //Encenda en vermello.
    setVermello();
  }
  else if(pot <= 204 && pot <408) {
    //Encenda en amarelo.
    setAmbar();
  }
  else if(pot <= 408 && pot <612) {
    //Encenda en verde.
    setVerde();
  }
  else if(pot <= 612 && pot <816) {
    //Encenda en azul.
    setAzul();
  }
  else {
    //Encenda en blanco.
    setBlanco();
  }

void loop() {
  pot = analogRead(POT);
  nivel = map(pot, 0, 1023, 0, 4);
  
  //Asignar un nivel (unha cor) (cinco niveis).
  //Escribir o valor no led rgb.
  if(nivel == 1) {
    //Encenda en vermello.
    setVermello();
  }
  else if(nivel == 2) {
    //Encenda en amarelo.
    setAmbar();
  }
  else if(nivel == 3) {
    //Encenda en verde.
    setVerde();
  }
  else if(nivel == 4) {
    //Encenda en azul.
    setAzul();
  }
  else {
    //Encenda en blanco.
    setBlanco();
  }
  */
