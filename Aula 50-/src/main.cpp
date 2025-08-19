#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

//*definindo as entradas
#define pinoA 4
#define pinoB 5
#define pinBotao 18

//*variavel
int contagem = 0;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() 
{
  pinMode(pinoA,INPUT); 
  pinMode(pinoB, INPUT);
  Serial.begin(115200);
 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,1);
  lcd.print("contagem:");
}

/*void loop() 
{
  bool leiturapinClk = digitalRead(pinoA);//*leitura da entrada do pino CLK
  bool leiturapinDt = digitalRead(pinoB); //*leitura da entrada do pino DT
 static bool leituraAnteriorPinClk = 1; //*leitura anterior do pino clk recebe 1
 static bool leituraAnteriorPinDt = 1; //*leitura anterior do pino DT recebe 1

if(leiturapinClk != leituraAnteriorPinClk || leiturapinDt != leituraAnteriorPinClk) //* quando a leitura tiver alguma mudanca nos dois blocos, quanto no Dt quanto no CLK, havera a seguinte mudanca
{
leituraAnteriorPinClk = leiturapinClk;//*mudanca que ocorrera = leitura anterior ira receber a leitura atual do pino CLK
leituraAnteriorPinDt = leiturapinDt;//*mudanca que ocorrera = leitura anterior ira receber a leitura atual do pino DT
Serial.print(leiturapinClk);//*o que aparecera
Serial.print(" ");
Serial.println(leiturapinDt);//*o que tambem vai aparecer

if(leiturapinClk && leiturapinDt)//*quando o numero final for 11 ele junta todos e imprimi o traco
{
Serial.println("----------");
}

}
}*/
void loop()
{


}