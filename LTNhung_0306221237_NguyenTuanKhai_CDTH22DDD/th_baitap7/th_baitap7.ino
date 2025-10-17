#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


byte AW[8] = {
  B01010, B00100, B00000, B01110,
  B10001, B11111, B10001, B00000
};


byte AA[8] = {
  B00100, B01010, B00000, B01110,
  B10001, B11111, B10001, B00000
};


byte DD[8] = {
  B00000,
  B01110,
  B01001,
  B11101,
  B01001,
  B01001,
  B01110,
  B00000
};


byte EE[8] = {
  B00100,
  B01010,
  B11110,
  B10000,
  B11110,
  B10000,
  B11110,
  B00000
};

byte OO[8] = {
  B01110,
  B10001,
  B00000,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
};

byte OW[8] = {
  B00111,
  B01001,
  B00010,
  B01110,
  B10001,
  B10001,
  B01110,
  B00000
};

byte UW[8] = {
  B00010,
  B00101,
  B10001,
  B10010,
  B10010,
  B10010,
  B01100,
  B00000
};

void setup() {
  lcd.begin(16, 2);

  lcd.createChar(0, AW);
  lcd.createChar(1, AA);
  lcd.createChar(2, DD);
  lcd.createChar(3, EE);
  lcd.createChar(4, OO);
  lcd.createChar(5, OW);
  lcd.createChar(6, UW);

  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.print(" ");
  lcd.write(byte(1));
  lcd.print(" ");
  lcd.write(byte(2));
  lcd.print(" ");
  lcd.write(byte(3));
  lcd.print(" ");
  lcd.write(byte(4));
  lcd.print(" ");

  lcd.setCursor(0, 1);
  lcd.write(byte(5));
  lcd.print(" ");
  lcd.write(byte(6));
  lcd.print(" ");
}

void loop() {
}