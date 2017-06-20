  char menuArray[3][12] = {"1. Settings","2. MenuB","3. MenuC"};
  char aMenu[3][11] = {"A. Clock","B. OptionB","C.OptionC"};
  int maPtr = 0;
  int aPtr = 0;
  int menuLevel = 0;
  char motd[] = "   Main  Menu   ";

int menuShow(int a){
  switch(a){
    case 0:
      lcd.clear();
      lcd.print(motd);
      lcd.setCursor(0,1);
      lcd.print(menuArray[maPtr]);
      break;

    case 1:
      lcd.clear();
      lcd.print(menuArray[maPtr]);
      lcd.setCursor(0,1);
      lcd.print(aMenu[aPtr]);
      break;
      
    default:
      lcd.print("var too large");
      break;
  }
}

void menu() {

  lbutton.read();
  rbutton.read();
  sbutton.read();
  xbutton.read();
  ;

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

      case BACK:
      STATE=WAIT;
        if (menuLevel == 0){
          lcd.clear();
          lcd.print(motd);
          lcd.setCursor(0,1);
          lcd.print("Invalid");
          delay(750);
          menuShow(0);
        }
        
        else if (menuLevel == 1) {
          menuLevel--;
          menuShow(0);
        }
        break;
        
      case INCR:
        maPtr = min(maPtr++, 2);
        STATE = WAIT;
        if (menuLevel == 0) {
          menuShow(0);
        }
        break;

      case DECR:
        maPtr = max(maPtr--, 0); 
        STATE = WAIT;
        if (menuLevel == 0) {
          menuShow(0);
        }
        break;

      case SELC:
        menuLevel++;
        STATE = WAIT;
        menuShow(1);
        break;

    }
}
