float peso = 55;
float altura = 1.55;
float IMC = 0;
void setup()
{
  Serial.begin(9600);
  //***Valor IMC***
  IMC = peso / (altura * altura);
 
  if(IMC >= 32.4){
  Serial.println("Obesidade");
  
  }else if(IMC <= 32.3 & IMC >= 27.4){
  Serial.println("Acima do peso");
  
  }else if(IMC <= 27.3 & IMC >= 25.9){
   Serial.println("Pouco acima do peso");
 
  }else if(IMC <= 25.8 & IMC >= 19.1){
   Serial.println("Peso normal"); 
 
  }else{
    Serial.println("Abaixo do peso");
  }
    
}

void loop()
{
  
}