
//NOME:MARIA CLARA DE ASSIS RAMOS
//AULA:45
//Objetivo da aula foi fazer o led ligar e fazer a contagem do  botao sem o ruido atrapalhando

#include <Arduino.h>
#define pinLed 5
#define pinBotao 19


void setup() 
{
 pinMode(pinLed, OUTPUT);
 pinMode(pinBotao, INPUT_PULLUP);
 Serial.begin(9600);
}

void loop() 
{

bool estadoAtualBotao = digitalRead(pinBotao);
static bool estadoAnteriorBotao =  1;
static bool estadoBotao = 1;
static bool ultimaAcao = 1;

static bool estadoLed = 0;

static unsigned long tempoAnteriorDebounce = 0; 
unsigned long tempoAtual = millis();
const unsigned long tempoDebounce = 50;

static int contagem = 0;

//*Estado do led 
if(estadoAtualBotao && !estadoAnteriorBotao)
{
estadoLed = !estadoLed;
digitalWrite(pinLed, estadoLed);
}
 
//!INICIA TRATAMENTO DO RUIDO BOTAO

 //*Marca quando uma mudanca de estado acontece 
 if(estadoAtualBotao != estadoAnteriorBotao)
{
tempoAnteriorDebounce = tempoAtual;
}
//*verifica se a mudanca de estado esta estavel a bastante tempo
 if((tempoAtual - tempoAnteriorDebounce) > tempoDebounce)
{
//houve uma alteracao proposital do estado do botao?
if(estadoAtualBotao != ultimaAcao) 
{
  ultimaAcao = estadoAtualBotao;
if(!estadoAtualBotao)
{
  //o botao foi pressionado
  contagem ++;
  Serial.println(contagem);
}
else
{
  //o botao foi solto 
}
}
}estadoAnteriorBotao = estadoAtualBotao;
//!FINAL DO TRATAMENTO DO RUIDO BOTAO

}
