#include <LiquidCrystal.h>
#include <Button.h>
//Button library provided by https://github.com/JChristensen/Button/

  int lcdRS = 11;
  int lcdE = 10;
  int lcdD4 = 5;
  int lcdD5 = 4;
  int lcdD6 = 3;
  int lcdD7 = 2;

  LiquidCrystal lcd(lcdRS, lcdE, lcdD4, lcdD5, lcdD6, lcdD7);

  Button lbutton(6,true,true,25);
  Button rbutton(7,true,true,25);
  Button sbutton(8,true,true,25);
  Button xbutton(9,true,true,25);
  
  enum {WAIT, INCR, DECR, SELC, BACK};
  uint8_t STATE;
  int lastCount = -1;
  unsigned long rpt = 100;

void setup() {

  Serial.begin(115200);

  char appName[] = "autoGarden 0.0.4";

  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print(appName);
  lcd.setCursor(0,1);
  lcd.print("Press Any Button");
}

  void loop() {
  
  menu();

}
