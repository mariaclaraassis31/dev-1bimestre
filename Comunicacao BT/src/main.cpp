#include <Arduino.h>
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
//*ESP Master
void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESPMaster", true);

  if (SerialBT.connect()) //*nome do esp que o coleguinha deu o nome
  {
    Serial.println("Conectado ao dispositivo com sucesso");
  }
  else
  {
    Serial.println("Deu ruim galera");
    while (true)
      ; //*TRAVA O ESP
  }
}

void loop()
{
  SerialBT.print("ping");
  Serial.println("Enviado a mensagem");

  unsigned long timeout = millis() + 3000;
  while (millis() < timeout)
  {
    if (SerialBT.available())
    {
      String resposta = SerialBT.readStringUntil('\r');
      Serial.printf("Resposta: %s", resposta);
      break;
    }
  }
}
/*void setup()
{
  Serial.begin(9600);
  SerialBT.begin("ESPMariMay");

  Serial.println("Esperando uma conexao Bluetooth"); 
}

void loop()
{
 if(SerialBT.available());
 {
  String mensagem = SerialBT.readStringUntil('\r');
  Serial.printf("Mensagem Recebida: %s", mensagem);

  if(mensagem.equals("ping"));
  {
    SerialBT.print("pong\n\r");
  }
 }
}*/
