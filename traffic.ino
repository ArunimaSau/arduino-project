#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
#include <SevSeg.h>

SevSeg s;
byte CommonPins[]={};
byte SegPins[]={2,3,4,5,6,7,8};
int red=9;
int green=10;

void setup() {
  // put your setup code here, to run once:
 lcd.init();                      // initialize the lcd 
  
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  //lcd.print("Hello world!");
 pinMode(12,OUTPUT);
  s.begin(COMMON_ANODE,1,CommonPins,SegPins,2);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
digitalWrite(red,HIGH);
lcd.setCursor(4,1);
lcd.print("STOP !!!");
}


void loop() {
  // put your main code here, to run repeatedly:
 for(int i=9;i>=0;i--){
    show(i);
    if(i<=3){
      lcd.clear();
      lcd.print("READY TO GO !!!");
      digitalWrite(12,HIGH);
      delay(1000);
      digitalWrite(12,LOW);
    }
  }
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("GO !!!");
  for(int i=9;i>=0;i--){
    show(i);
    if(i<=3){
      lcd.clear();
      lcd.print("BE SLOW !!!");
      digitalWrite(12,HIGH);
      delay(1000);
      digitalWrite(12,LOW);
    }
  }
  lcd.clear();
  digitalWrite(red,HIGH);
  digitalWrite(green,LOW);
  lcd.setCursor(4,1);
  lcd.print("STOP !!!");
}
 void show(int num){
  s.setNumber(num);
s.refreshDisplay();
delay(1000);
}
