// C++ code
//
#define pinBotao 10
int contagem = 0; 
bool estadoAnteriorBotao = estadoAnteriorBotao;
void setup()
{
  pinMode(pinBotao, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
 static bool estadoAnteriorBotao = 0;
 bool estadoAtualBotao = digitalRead(pinBotao);
 if(estadoAtualBotao == 1 && estadoAnteriorBotao == 0)
 {
 contagem ++;
 Serial.println(contagem);
 } 
estadoAnteriorBotao = estadoAtualBotao;
}



