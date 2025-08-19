#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
int valor = 0;
int pinS1 = 4;
int pinS2 = 5;

LiquidCrystal_I2C lcd(0x27,20,4);

bool estadoatualS1 = false;
bool estadoatualS2 = false;
bool estadoanteriorS1 = false;
bool estadoanteriorS2 = false;
int contagem = 0;
int resultado = 0;
int numeroA = 1;
void setup()
{
  pinMode(pinS1, INPUT);
  pinMode(pinS2, INPUT);
  Serial.begin(9600);
   lcd.init();                  
  lcd.backlight();
  lcd.setCursor(2,1);
  lcd.print("Contagem:");
}

void loop()
{
  estadoatualS1 = digitalRead(pinS1);
  estadoatualS2 = digitalRead(pinS2);
  int estadoatual=(digitalRead(pinS1)<<1|digitalRead(pinS2));//* "<<1" para mover um byte por isso usamos ele. | a barra é a porta lógica OU. Então estado atual recebe  leitura do pino S1 
  static int estadoanterior=0;

  if (estadoatual!=estadoanterior)
  {
    Serial.println(estadoatual);
    if (estadoatual==3);
    
  }
  estadoanterior=estadoatual;

//*Fazendo a contagem para adicionar (quando for para direita) e subtrair (quando for para a esquerda)
if(estadoatual == 2 )
{

}





}
