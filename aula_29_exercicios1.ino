// C++ code
//

void setup()
{
  
  
 //**Exercicio 1** 
  Serial.begin(9600);
int numero = 5;
  
  if(numero > 0){
  Serial.println("Numero positivo");
  
  }else if(numero < 0){
  Serial.println("Numero negativo");
  }
  
  
//** Exercicio 2**
auto nome = "Ricardo";
auto cargo = "estagiario";
int salario = 820;
int resultado = 0;
 
  if(salario <1000){
 resultado = salario + (salario * 10/100);
 Serial.println(resultado);
  }
 Serial.println(nome);
 Serial.println(cargo);
 Serial.println(resultado);

  
 //** Exercicio 3**
 int salarioA = 550;
 int resultadoA = 0;
  
  if(salarioA < 500){
  resultadoA = salarioA + (salarioA * 10/100);
  Serial.println(resultadoA);
  Serial.println("salario reajustado");
  }else if(salarioA > 500){
  Serial.println("caro funcionario, voce nao tem direito ao aumento de salario");
  }
  

 //Exercicio 4***
int numeroA = 8;
int numeroB = 5;
  
  if(numeroA > numeroB){
  Serial.println(numeroA);
  }else{
  Serial.println(numeroB);
  }
  

  //**Exercicio 5***
int nota1 = 9;
int nota2 = 7;
int nota3 = 5;
int nota4 = 7;
int media = 0;
  media = ( nota1 + nota2+ nota3 + nota4) / 4;
  Serial.println(media);
  if(media >= 7){
  Serial.println("Aprovado");
  }else if(media <= 7 & media > 5){
  Serial.println("Recuperacao");
  }else if(media < 5){
  Serial.println("Reprovado");
  }

    
}
   
   
   void loop()
{
  
}