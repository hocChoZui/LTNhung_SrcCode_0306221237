//#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//LiquidCrystal_I2C lcd(0x27, 16,2);
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS,E,D4,D5,D6,D7

int btnF= 6;
int btnC=7;
int sensorPin = A0;
bool status = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnC, INPUT);
  pinMode(btnF, INPUT);
  lcd.begin(16, 2);
  //lcd.init();
  //lcd.backlight();
  lcd.setCursor(0,0);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(sensorPin);
  float voltage = reading * 5.0/1024.0; 
  float temp = voltage * 100.0; // đổi ra độ C 
  float tempF = (temp*1.8)+32; //đổi từ độ C sang độ F
  //độ C
  if(digitalRead(btnC) == HIGH)
  {
    status = true;
  }
  if(digitalRead(btnF) == HIGH)
  {
    status = false;
  }
  if(status == true)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("C: ");
    lcd.print(temp);
  }
  // độ Fs
  else if(status == false)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("F: ");
    lcd.print(tempF);
  }

  delay(200);
}
