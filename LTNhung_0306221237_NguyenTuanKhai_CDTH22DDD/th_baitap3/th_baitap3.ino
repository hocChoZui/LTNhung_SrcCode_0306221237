const int ledPin = 9;      
const int buttonUpPin = 2;  
const int buttonDownPin = 3; 

bool ledState = false;
unsigned long previousMillis = 0;

unsigned long blinkInterval = 500; 

const unsigned long minInterval = 50;   
const unsigned long maxInterval = 2000; 
const unsigned long stepSize = 50; 

bool buttonUpState = false;
bool buttonDownState = false;
bool lastButtonUpState = false;
bool lastButtonDownState = false;
unsigned long buttonUpDebounceTime = 0;
unsigned long buttonDownDebounceTime = 0;
const long debounceDelay = 50;


void setup() {
  // put your setup code here, to run once:
    pinMode(ledPin, OUTPUT);
  pinMode(buttonUpPin, INPUT);
  pinMode(buttonDownPin, INPUT);
  
  digitalWrite(ledPin, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
   unsigned long currentMillis = millis();

   int readingUp = digitalRead(buttonUpPin);
   if(readingUp != lastButtonUpState){
    buttonUpDebounceTime = currentMillis;
   }

   if ((currentMillis - buttonUpDebounceTime) > debounceDelay) {
    if (readingUp != buttonUpState) {
      buttonUpState = readingUp;

      if (buttonUpState == HIGH) { 
        if (blinkInterval > minInterval) {
          blinkInterval -= stepSize;
          if (blinkInterval < minInterval) {
            blinkInterval = minInterval;
          }
        
        }
      }
    }
  }
  lastButtonUpState = readingUp;

  int readingDown = digitalRead(buttonDownPin);
  if (readingDown != lastButtonDownState) {
    buttonDownDebounceTime = currentMillis;
  }
  if ((currentMillis - buttonDownDebounceTime) > debounceDelay) {
    if (readingDown != buttonDownState) {
      buttonDownState = readingDown;
      if (buttonDownState == HIGH) { 

        if (blinkInterval < maxInterval) {
          blinkInterval += stepSize;
          if (blinkInterval > maxInterval) {
            blinkInterval = maxInterval;
          }
        }
      }
    }
  }
  lastButtonDownState = readingDown;
  

  if (currentMillis - previousMillis >= blinkInterval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }

}
