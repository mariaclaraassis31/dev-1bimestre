#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define pinLedVermelho 4
#define pinLedBranco 18
#define pinBotaoLcdFrase 23
#define pinBotaoLcdDesenho 19
#define tempoPiscaLedVermelho 800

//** VARIAVEIS LED ****
unsigned long tempoms;
unsigned long tempomsFrase;
unsigned long tempoInicial = 0;
bool estadoLedVermelho = 0;
bool estadoLedBranco = 0;

unsigned long tempoAnterior = 0;  // Armazena o último tempo em que o display foi alternado
const long intervalo = 800;      // Intervalo de tempo para alternar o display
bool exibindo = true;             // Controla se o display está ligado ou desligado
unsigned long tempoAtual;

bool mostrarFrase = false;
bool mostrarDesenho = true;


LiquidCrystal_I2C lcd(0x27, 20, 4);

//** CRIOU ESTRELA **
byte estrelas[8] = {
    B01000,
    B11100,
    B01000,
    B00010,
    B00111,
    B01010,
    B11100,
    B01000};

void setup()
{
  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinLedBranco, OUTPUT);
  pinMode(pinBotaoLcdFrase, INPUT_PULLUP);
  pinMode(pinBotaoLcdDesenho, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, estrelas);

  lcd.setCursor(6, 0);
  lcd.print("Bom Dia,");
  lcd.setCursor(5, 1);
  lcd.print("Bem-vindo");
  lcd.setCursor(9, 2);
  lcd.print("Ao");
  lcd.setCursor(6, 3);
  lcd.print("MariMay!");
}

void loop()
{


  //! BOTAO DESENHO
  bool leituraBotaoLcdDesenho = digitalRead(pinBotaoLcdDesenho);
  tempoms = millis();
  tempoAtual = millis ();

  
  if (leituraBotaoLcdDesenho == 0)
  {
    mostrarFrase = false;
    digitalWrite(pinLedBranco, LOW);

    if (tempoms - tempoInicial >= tempoPiscaLedVermelho)
    {
      estadoLedVermelho = !estadoLedVermelho;
      digitalWrite(pinLedVermelho, estadoLedVermelho);
      tempoInicial = tempoms;
    }

    if (tempoAtual - tempoAnterior >=intervalo)
    {
      tempoAnterior = tempoAtual; // Atualiza o tempo anterior para o tempo atual

      if (mostrarDesenho)
      {
      lcd.display();    // Religa o display
      lcd.clear();

      //! CORACAO
      lcd.setCursor(10, 1);
      lcd.write(255);

      lcd.setCursor(11, 0);
      lcd.write(255);

      lcd.setCursor(12, 1);
      lcd.write(255);

      lcd.setCursor(10, 1);
      lcd.write(255);

      lcd.setCursor(11, 2);
      lcd.write(255);

      lcd.setCursor(10, 3);
      lcd.write(255);

      lcd.setCursor(9, 2);
      lcd.write(255);

      lcd.setCursor(8, 1);
      lcd.write(255);

      lcd.setCursor(9, 0);
      lcd.write(255);

      lcd.setCursor(9, 1);
      lcd.write(255);

      lcd.setCursor(11, 1);
      lcd.write(255);

      lcd.setCursor(10, 2);
      lcd.write(255);

      //! ESTRELAS
      lcd.setCursor(4, 0);
      lcd.write(0);

      lcd.setCursor(1, 1);
      lcd.write(0);

      lcd.setCursor(5, 2);
      lcd.write(0);

      lcd.setCursor(2, 3);
      lcd.write(0);

      lcd.setCursor(18, 0);
      lcd.write(0);

      lcd.setCursor(15, 1);
      lcd.write(0);

      lcd.setCursor(19, 2);
      lcd.write(0);

      lcd.setCursor(17, 3);
      lcd.write(0);
      }
  
      else
      {
        lcd.noDisplay();  // Desliga o display
      } 
      
      mostrarDesenho = !mostrarDesenho; 
    }
  }
  else
  {
    digitalWrite(pinLedVermelho, LOW);
   
  }

  //! BOTAOFRASE

  bool leituraBotaoLcdFrase = digitalRead(pinBotaoLcdFrase);
  static bool leituraAnteriorBotaoLcdFrase = 1;

  if (leituraBotaoLcdFrase == 0 && leituraAnteriorBotaoLcdFrase == 1)
  {
    mostrarFrase = true;
    mostrarDesenho = false;
    digitalWrite(pinLedBranco, HIGH);
    

    if (mostrarFrase)
    {
  
    lcd.display();    // Religa o display
    lcd.clear();

    lcd.setCursor(3, 1);
    lcd.print("Cada um brilha");
    lcd.setCursor(1, 2);
    lcd.print("de uma forma unica");

    lcd.setCursor(1, 0);
    lcd.write(0);

    lcd.setCursor(19, 0);
    lcd.write(0);

    lcd.setCursor(19, 3);
    lcd.write(0);

    lcd.setCursor(0, 3);
    lcd.write(0);
    }
    mostrarFrase = false;
  }
   leituraAnteriorBotaoLcdFrase = leituraBotaoLcdFrase;
  
}

