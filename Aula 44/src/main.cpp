#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

//*Instancias de Objetos 
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
 {
  Serial.begin(9600); //9600 igual baudRate 
  lcd.init();
  lcd.backlight();
  lcd.print("OLA MUNDO!!");
 }

void loop() {
 
}