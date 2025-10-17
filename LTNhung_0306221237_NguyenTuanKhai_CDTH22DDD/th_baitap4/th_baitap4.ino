const int ledVang = 8;    
const int ledDo = 9;      
const int buttonPin = 2;  

int mode = 0;            
bool buttonState = false;
bool lastButtonState = false;
unsigned long buttonDebounceTime = 0;
const long debounceDelay = 50;

void setup() {
  pinMode(ledVang, OUTPUT);
  pinMode(ledDo, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  digitalWrite(ledVang, LOW);
  digitalWrite(ledDo, LOW);
}

void loop() {
  unsigned long currentMillis = millis();
  
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    buttonDebounceTime = currentMillis;
  }
  
  if ((currentMillis - buttonDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      if (buttonState == HIGH) {
        mode = (mode + 1) % 5;
        
        switch(mode) {
          case 0:  
            digitalWrite(ledVang, LOW);
            digitalWrite(ledDo, LOW);
            break;
            
          case 1: 
            digitalWrite(ledVang, HIGH);
            digitalWrite(ledDo, HIGH);
            break;
            
          case 2: 
            digitalWrite(ledVang, LOW);
            digitalWrite(ledDo, LOW);
            break;
            
          case 3: 
            digitalWrite(ledVang, HIGH);
            digitalWrite(ledDo, LOW);
            break;
          case 4: 
           digitalWrite(ledVang, LOW);
            digitalWrite(ledDo, HIGH);
            break;
        }
      }
    }
  }
  
  lastButtonState = reading;
}