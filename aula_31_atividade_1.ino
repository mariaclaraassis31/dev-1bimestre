// C++ code
//
#define pinLEDRED 12
#define pinLEDORANGE 8
#define pinLEDGREEN 4
#define tempoLEDRED  5000
#define tempoLEDORANGE  2000
#define tempoLEDGREEN  3000
unsigned long tempoms;
unsigned  tempoInicial= 0;
char faseSemaforo = 0;

void setup()
{
  pinMode(pinLEDRED, OUTPUT);
  pinMode(pinLEDORANGE, OUTPUT);
  pinMode(pinLEDGREEN, OUTPUT);
  
}

void loop()
{
 
   tempoms = millis();
 
 if(faseSemaforo == 0){
 digitalWrite(pinLEDRED, LOW);
 digitalWrite(pinLEDORANGE, LOW);
 digitalWrite(pinLEDGREEN, HIGH);
 if(tempoms - tempoInicial >= tempoLEDGREEN)
 {
 tempoInicial = tempoms;
 faseSemaforo = 1;
  }}
 
  if(faseSemaforo == 1){
  digitalWrite(pinLEDRED, LOW);
  digitalWrite(pinLEDORANGE, HIGH);
  digitalWrite(pinLEDGREEN, LOW);
  if(tempoms - tempoInicial >= tempoLEDORANGE)
  {
  tempoInicial = tempoms;
  faseSemaforo = 2;
  }}
 
  if(faseSemaforo == 2){
  digitalWrite(pinLEDRED, HIGH);
  digitalWrite(pinLEDORANGE, LOW);
  digitalWrite(pinLEDGREEN, LOW);
  if(tempoms - tempoInicial >= tempoLEDRED)
  {
  tempoInicial = tempoms;
  faseSemaforo = 0;
  
  
  }}

}