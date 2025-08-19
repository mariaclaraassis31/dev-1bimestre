#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define botao 2
#define entradaA 4
#define entradaB 5


//* tabela de possibilidades
const int8_t tabelaTransicao[4][4] = {
    // +1 horario
    // 0 parado
    // - 1 antihorario
    //*Tabela de transicao que vai combinar a posicao anterior com a posicao atual e retornar
    //*Se deve ser incrementado ou decrementado com o movimento
    // 0   1  2  3 ATUAL
    {0, 1, -1, 0}, // 0 anterior
    {-1, 0, 0, 1}, // 1 anterior
    {1, 0, 0, -1}, // 2 anterior
    {0, -1, 1, 0}  // 3 anterior
};

//* 32013201 HORARIO
//* 10231023 ANTIHORARIO

void setup()
{

  pinMode(entradaA, INPUT);
  pinMode(entradaB, INPUT);
  pinMode(botao, INPUT);
  

  Serial.begin(115200);

  lcd.init();
  lcd.backlight();
}

void loop()
{
encoderUpdate;
static bool posicaoMenu = 0; //* 0(false)- intensidade do led ou 1(true)- menu

}


void encoderUpdate()
{

  //*Faz a leitura do canal de cada estado
  bool leituraEntradaA = digitalRead(entradaA);
  bool leituraEntradaB = digitalRead(entradaB);

  //*Une os valores dos dois canais em uma unica variavel
  //*Rotaciona o valor de A para uma posicao a esquerda e deixa o valor de B na posicao da direita
  int estadoAtualEncoder = ((leituraEntradaA << 1) | leituraEntradaB);

  static int estadoAnteriorEncoder = 3;
  static int contador = 0;
  static int acumuladorMovimento = 0; //*Variavel para verificar se for dado os 4 pulsos corretos

  //*Caso houver alguma movimentacao no encoder, adicione ou subtraia uma unidade do acumulador de movimento
  if (estadoAtualEncoder != estadoAnteriorEncoder)
    acumuladorMovimento += tabelaTransicao[estadoAnteriorEncoder][estadoAtualEncoder];
  {
    //*Se o encoder esta na posicao 3(posicao de repouso)
    if (estadoAtualEncoder == 3)
    {

      if (acumuladorMovimento == 4)
        contador++;

      else if (acumuladorMovimento == -4)
        contador--;

      acumuladorMovimento = 0;
      Serial.println(contador);
    }
  }
  estadoAnteriorEncoder = estadoAtualEncoder;

}