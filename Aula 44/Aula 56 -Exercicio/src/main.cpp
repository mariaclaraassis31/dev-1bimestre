#include <Arduino.h>
#include "BluetoothSerial.h"
#define pinLed 2 
//*SLAVE
BluetoothSerial SerialBT;
void setup()
{
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  SerialBT.begin("ESPclarinha");

  Serial.println("Esperando uma conexao Bluetooth");
}

void loop()
{
  if (SerialBT.available())
    
  {
    String mensagem = SerialBT.readStringUntil('\r');
    Serial.printf("Mensagem Recebida: %s", mensagem);

    if (mensagem.equals("ping"))
      
    {
      SerialBT.print("pong\n\r");
    }
  }
}
