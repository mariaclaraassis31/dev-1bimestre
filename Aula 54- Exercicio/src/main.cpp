#include <Arduino.h>
struct CorRGB
{
  int R;
  int G;
  int B;
};

CorRGB lilas;
CorRGB amarelo;
CorRGB marrom;

void setup()
{
  Serial.begin(9600);
  //*Lilas
  lilas.R = 141;
  lilas.G = 89;
  lilas.B = 143;

 //*Amarelo
  amarelo.R =244;
  amarelo.G =222;
  amarelo.B = 41;
 
 //*Marrom
  marrom.R =94;
  marrom.G =34;
  marrom.B =15;

Serial.printf("A cor lilas tem %d de vermelho", lilas.R);
Serial.printf(" tambem tem %d de verde", lilas.G);
Serial.printf(" e por ultimo %d de azul\n\r", lilas.B);

Serial.printf("A cor amarelo tem %d de vermelho", amarelo.R);
Serial.printf(" tambem tem %d de verde", amarelo.G);
Serial.printf(" e por ultimo %d de azul\n\r", amarelo.B);

Serial.printf("A cor marrom tem %d de vermelho", marrom.R);
Serial.printf(" tambem tem %d de verde", marrom.G);
Serial.printf(" e por ultimo %d de azul\n\r", marrom.B);
}

void loop() 
{
 
}

