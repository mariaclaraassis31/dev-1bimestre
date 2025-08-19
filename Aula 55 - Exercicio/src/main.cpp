#include <Arduino.h>

String palavra = "";

void setup()
{
  Serial.begin(9600);
  Serial.println("Escolha o led 1, 2, 3 e");
}

void loop()
{
  while (Serial.available())
  {
    char caractere = Serial.read();
  }
}