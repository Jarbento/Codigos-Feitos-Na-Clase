// C++ code
//
 /*
  * Sricpt para controlar un motor dun ventilador mediante un sensor de temperatira
  * TPM36.
  *
  * O sensor de temperatura medirá valores entre (14,34) ºC de medida que o motor se 
  * áccionará a partir dos 19º con velocvidade ascendente en función dun número de umbral
  * de temperatura.
  *
  * O sensor TPM36 o rango de temperatura e:
  *  20  (en valores enteiros) 97   (mV) a -40ºC
  *  358 (en valores enteiros) 1749 (mV) a +125ºC
  *
  * Autor: Francisco Mos.
  * Data: 29/01/2024.
  *
  */

// Definicións de pins E/S.
#define TMP A0
#define MOTOR 11

// Declaración de variables globales.
int tempo = 500;
int entrada = -1; //Valor enteiro.
int vin = -1; //Valor de tensión de entrada calculado.
int tmp = -1; //Temperatura a partir da tensión de entrada.
int saida = -1; //Nivel de saida entre 0 e nNiveis-1.
int veloc = -1; //Velocidade do motor.
int nNiveis = 4; //Niveis ou umbrais de saida.
int vMin = 25; //Velocidade mínima do motor.
int vMax = 255; //Velocidade máxima do motor.

void setup(){
 Serial.begin(9600);  
}

void loop(){
  //Lectura de entrada.
  entrada = analogRead(TMP);
  vin = map(entrada, 20, 358, 97, 1749); //Calibración da entrada.
  tmp = map(vin, 97, 1749, -40, 125); // Calibración do sensor TMP36.
  tmp = constrain(tmp, 14, 34); //Eliminación valores superfluos.
  
  //Impresión dos valores de entrada polo monitor serie.
  Serial.print("Entrada: "); Serial.print(entrada);
  Serial.print(" | Vin: "); Serial.print(vin); Serial.print(" mV");
  Serial.print(" | Tmp: "); Serial.print(tmp); Serial.println(" ºC");
  
  //Asignación dos valores de saída.
  if(tmp >=19) {
    saida= map(tmp, 19, 34, 0, nNiveis-1);
    veloc = map(saida, 0, nNiveis-1, vMin, vMax);
  }
  else {
    saida = 0;
  }
  
  //Asignación de valores do motor.
  analogWrite(MOTOR, saida);
  Serial.print("Velocidade motor:"); Serial.println(veloc);
  
  delay (tempo);
}
  
  
  
  
  
  
  /*  
  if(tmp >= 19 && tmp < 24) {
   analogWrite(MOTOR, 0); 
  }
  else if(tmp >= 24 && tmp < 29) {
   analogWrite(MOTOR, 85); 
  }
  else if(tmp >= 29 && tmp < 34) {
   analogWrite(MOTOR, 170);
  }
  else if(tmp >= 34) {
   analogWrite(MOTOR, 255); 
  }
  
  delay(tempo);
}
*/
