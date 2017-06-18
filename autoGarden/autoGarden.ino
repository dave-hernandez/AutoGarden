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

}

//Menu Array Setup

  char menuArray[3][10] = {"1. Light","2. Water","3. Setup"};
  int maPtr = 0;
  bool menu2 = false;

/////////////////
//PROGRAM START//
/////////////////

  void loop() {

  menu();

//Button Loop

  lcd.setCursor(0,1);
  lcd.print(menuArray[maPtr]);


}
