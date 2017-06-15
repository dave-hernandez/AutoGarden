#include <LiquidCrystal.h>
#include <Button.h>
//Button library provided by https://github.com/JChristensen/Button/

//HD44780 LCD Setup

  int lcdRS = 12;
  int lcdE = 11;
  int lcdD4 = 5;
  int lcdD5 = 4;
  int lcdD6 = 3;
  int lcdD7 = 2;

  LiquidCrystal lcd(lcdRS, lcdE, lcdD4, lcdD5, lcdD6, lcdD7);

//Photocell Setup

  const int sensorMin = 0;
  const int sensorMax = 800;
  int photocellPin = A0;

<<<<<<< HEAD
//Button Setup
=======
void setup() {

    Serial.begin(9600);

    lcd.begin(16,2);
    lcd.print("AutoGarden 0.0.2");

    pinMode(6,INPUT_PULLUP);
    pinMode(13,OUTPUT);
}
>>>>>>> origin/master

  Button lbutton(7,true,true,25);
  Button rbutton(6,true,true,25);
  Button sbutton(8,true,true,25);
  Button xbutton(9,true,true,25);
  
  enum {WAIT, INCR, DECR, SELC, BACK};
  uint8_t STATE;
  int lastCount = -1;
  unsigned long rpt = 100;

void setup() {

  Serial.begin(9600);

  char appName[] = "Autogarden 0.0.3";

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  
  lcd.print(appName);

<<<<<<< HEAD
}
//Menu Array Setup

  char menuArray[3][10] = {"Light","Water","Setup"};
  int maPtr = 1;
  bool menu2 = false;
    

/////////////////
//PROGRAM START//
/////////////////

  void loop() {

lbutton.read();
rbutton.read();
sbutton.read();
xbutton.read();

  switch (STATE) {
        
    case WAIT:
      if (lbutton.wasPressed())
        STATE = DECR;
      else if (rbutton.wasPressed())
        STATE = INCR;
      else if (sbutton.wasPressed())
        STATE = SELC;
      else if (xbutton.wasPressed())
        STATE = BACK;
      else if (lbutton.wasReleased())
        rpt = 500;
      else if (rbutton.wasReleased())
        rpt = 500;        
      else if (lbutton.pressedFor(rpt)) {
        rpt += 100;
        STATE = DECR;
      }
      else if (rbutton.pressedFor(rpt)) {
        rpt += 100;
        STATE = INCR;
      }
        break;

      case SELC:
        lcd.clear();
        lcd.print(menuArray[maPtr]);
        lcd.setCursor(0,1);
        lcd.print("SUBMENU");

      case INCR:
        maPtr = min(maPtr++, 2);
        STATE = WAIT;
        break;

      case DECR:
        maPtr = max(maPtr--, 0); 
        STATE = WAIT;
        break;

    }
=======
  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Water Module MIA");
    delay(1000);
  }  
>>>>>>> origin/master

//Button Loop

  lcd.setCursor(0,1);
  lcd.print(menuArray[maPtr]);


}
