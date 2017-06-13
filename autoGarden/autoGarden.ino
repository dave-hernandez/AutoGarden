#include <LiquidCrystal.h>

//HD44780 LCD Setup

int lcdRS = 12;
int lcdE = 11;
int lcdD4 = 5;
int lcdD5 = 4;
int lcdD6 = 3;
int lcdD7 = 2;

LiquidCrystal lcd(lcdRS, lcdE,
                  lcdD4, lcdD5, lcdD6, lcdD7);

//Photocell setup

const int sensorMin = 0;
const int sensorMax = 800;
int photocellPin = A0;

void setup() {

    Serial.begin(9600);

    lcd.begin(16,2);
    lcd.print("AutoGarden 0.0.2");

    pinMode(6,INPUT_PULLUP);
    pinMode(13,OUTPUT);
}

void loop() {
  int pcaValue;
  int range;

  pcaValue = analogRead(photocellPin);
  range = map(pcaValue, sensorMin, sensorMax, 0, 3);

//Button Loop

  int sensorVal = digitalRead(6);

  Serial.println(sensorVal,DEC);

  if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
  } else {
    digitalWrite(13, HIGH);
    lcd.setCursor(0,1);
    lcd.print("Water Module MIA");
    delay(1000);
  }  

//Photocell Loop

  lcd.setCursor(0,1);

  lcd.print(pcaValue);
  delay(400);
  lcd.print("      ");
//  switch(range) {
//    case 0:
//        lcd.print("Light: Night    ");
//        break;
//    case 1:
//        lcd.print("Light: Shade    ");
//        break;      
//    case 2:
//        lcd.print("Light: Part Sun ");
//        break;
//    case 3:
//        lcd.print("Light: Full Sun ");
//        break;
//  }

}
