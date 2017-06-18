void menu() {

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
}
