#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int btnTogglePin = 6;
const int btnLeftPin   = 7;
const int btnRightPin  = 8;

bool btnToggleState = LOW;
bool lastBtnToggleState = LOW;
unsigned long lastDebounceToggle = 0;

bool btnLeftState = LOW;
bool lastBtnLeftState = LOW;
unsigned long lastDebounceLeft = 0;

bool btnRightState = LOW;
bool lastBtnRightState = LOW;
unsigned long lastDebounceRight = 0;

const long debounceDelay = 50;

const char *text = "HELLO";
const int textLen = 5;
int pos = 0;
const int minPos = -textLen;
const int maxPos = 15;

bool lcdIsOn = false;

char lineBuf[17];

void setup() {
  pinMode(btnTogglePin, INPUT);
  pinMode(btnLeftPin, INPUT);
  pinMode(btnRightPin, INPUT);
  lcd.begin(16, 2);
  lcd.noDisplay();
}

void loop() {
  unsigned long currentMillis = millis();

  int readingToggle = digitalRead(btnTogglePin);
  if (readingToggle != lastBtnToggleState) {
    lastDebounceToggle = currentMillis;
  }
  if ((currentMillis - lastDebounceToggle) > debounceDelay) {
    if (readingToggle != btnToggleState) {
      btnToggleState = readingToggle;
      if (btnToggleState == HIGH) {
        lcdIsOn = !lcdIsOn;
        if (lcdIsOn) {
          lcd.display();
          lcd.clear();
          updateAndShow();
        } else {
          lcd.noDisplay();
        }
      }
    }
  }
  lastBtnToggleState = readingToggle;

  int readingLeft = digitalRead(btnLeftPin);
  if (readingLeft != lastBtnLeftState) {
    lastDebounceLeft = currentMillis;
  }
  if ((currentMillis - lastDebounceLeft) > debounceDelay) {
    if (readingLeft != btnLeftState) {
      btnLeftState = readingLeft;
      if (btnLeftState == HIGH && lcdIsOn) {
        pos -= 2;
        if (pos < minPos) pos = minPos;
        updateAndShow();
      }
    }
  }
  lastBtnLeftState = readingLeft;

  int readingRight = digitalRead(btnRightPin);
  if (readingRight != lastBtnRightState) {
    lastDebounceRight = currentMillis;
  }
  if ((currentMillis - lastDebounceRight) > debounceDelay) {
    if (readingRight != btnRightState) {
      btnRightState = readingRight;
      if (btnRightState == HIGH && lcdIsOn) {
        pos += 2;
        if (pos > maxPos) pos = maxPos;
        updateAndShow();
      }
    }
  }
  lastBtnRightState = readingRight;
}

void updateAndShow() {
  for (int i = 0; i < 16; ++i) lineBuf[i] = ' ';
  lineBuf[16] = '\0';
  for (int i = 0; i < textLen; ++i) {
    int col = pos + i;
    if (col >= 0 && col < 16) {
      lineBuf[col] = text[i];
    }
  }
  lcd.setCursor(0, 0);
  lcd.print(lineBuf);
}
