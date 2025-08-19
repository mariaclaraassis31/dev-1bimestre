// C++ code
//
#define pinLEDRED 12
#define pinLEDGREEN 9
#define pinLEDYELLOW 7
#define pinLEDWHITE 4

int temperatura = 31;
int bateria = 50;
int variavel = 40;  
int resultado2= 0;
int resultado = 0; 
int numeroavaliado = 66;
int numerodivisivel = 2;
int resultadopar = 0;

void setup()
{
  //****Exercicio 1****
    pinMode(pinLEDRED, OUTPUT);
  if(temperatura > 30){
 digitalWrite(pinLEDRED,HIGH);
  
   //***Exercicio 2*** 
    pinMode(pinLEDGREEN, OUTPUT);
} if(bateria <=80 & bateria >=20);{
  digitalWrite (pinLEDGREEN,HIGH);
}
 
  //***Exercicio 3***
     Serial.begin(9600);
   resultado = map(variavel,0, 100, 0, 1023);
     Serial.println(resultado);
   resultado2 = constrain(resultado, 20, 80);
     pinMode(pinLEDYELLOW, OUTPUT);
   if(resultado > 80);{
     Serial.println("O valor excedeu os limites");
   digitalWrite (pinLEDYELLOW, HIGH);
      }
  
  //***Exercicio 4**
    Serial.begin(9600);
  pinMode(pinLEDWHITE, OUTPUT);
  resultadopar = numeroavaliado / numerodivisivel;
  resultadopar = numeroavaliado % numerodivisivel;
  if(resultadopar == 0){
  Serial.println("O valor e par");
  digitalWrite (pinLEDWHITE, HIGH);
     }
  
       

}

void loop()
{ 



}