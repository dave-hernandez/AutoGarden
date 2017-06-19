  char menuArray[3][10] = {"1. MenuA","2. MenuB","3. MenuC"};
  char aMenu[3][11] = {"1. OptionA","2. OptionB","3.OptionC"};
  int maPtr = 0;
  int menuLevel = 0;
  char appName[] = "Autogarden 0.0.4";


void menu() {

  lbutton.read();
  rbutton.read();
  sbutton.read();
  xbutton.read();
  ;

    switch (STATE) {
        Serial.print(menuLevel);
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

      case BACK:
      STATE=WAIT;
        if (menuLevel == 0){
          lcd.clear();
          lcd.print(appName);
          lcd.setCursor(0,1);
          lcd.print("Invalid");
        }
        
        else if (menuLevel == 1) {
          menuLevel--;
          lcd.clear();
          lcd.print(appName);
          lcd.setCursor(0,1);
          lcd.print(menuArray[maPtr]);
        }
        break;
        
      case INCR:
        maPtr = min(maPtr++, 2);
        STATE = WAIT;
        lcd.clear();
        lcd.print(appName);
        lcd.setCursor(0,1);
        lcd.print(menuArray[maPtr]);
        break;

      case DECR:
        maPtr = max(maPtr--, 0); 
        STATE = WAIT;
        lcd.clear();
        lcd.print(appName);
        lcd.setCursor(0,1);
        lcd.print(menuArray[maPtr]);       
        break;

      case SELC:
        menuLevel++;
        STATE = WAIT;
        lcd.clear();
        lcd.print(menuArray[maPtr]);
        lcd.setCursor(0,1);
        lcd.write("SUBMENU");
        break;

    }
}
