#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int btn = 7;
int led = 9;
int dem = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btn_state = digitalRead(btn);
  lcd.setCursor(3, 0);
  delay(200);
  if (btn_state == HIGH) {
    dem++;
    if (dem % 2 != 0) {
      lcd.noDisplay();
      digitalWrite(led, HIGH);
    } else {
      lcd.display();
      digitalWrite(led, LOW);
    }
  }
}