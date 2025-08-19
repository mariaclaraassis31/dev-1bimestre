// C++ code
//
#define pinLEDRED 13
#define pinLEDORANGE 11
#define pinLEDYELLOW 8
#define pinLEDGREEN 5
#define pinLEDWHITE 2
int salaDeAula = 3;

void setup()
{ Serial.begin(9600);
 
 
 switch(salaDeAula){
 pinMode(pinLEDRED, OUTPUT);
 case 1: 
 Serial.println("Sala 1");
 digitalWrite(pinLEDRED, HIGH);
 break;

 
 pinMode(pinLEDORANGE, OUTPUT);
 case 2:
 Serial.println("Sala 2");
 digitalWrite(pinLEDORANGE, HIGH);
 break;
   
 pinMode(pinLEDYELLOW, OUTPUT);
 case 3:
 Serial.println("Sala 3");
 digitalWrite(pinLEDYELLOW, HIGH); 
 break;
   
 pinMode(pinLEDGREEN, OUTPUT);
 case 4:
 Serial.println("Sala 4");
 digitalWrite(pinLEDGREEN, HIGH);
 break;
   
   pinMode(pinLEDWHITE, OUTPUT);
   case 5:
   Serial.println("Sala 5");
   digitalWrite(pinLEDWHITE, HIGH);
   break;
 }

}

void loop()
{
  
}