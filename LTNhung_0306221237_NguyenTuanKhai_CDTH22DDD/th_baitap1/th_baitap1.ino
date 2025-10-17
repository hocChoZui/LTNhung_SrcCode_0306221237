int ledPins[] = {3,4,5,6,7,8,9,10,11,12};

unsigned long previousMillis = 0;
const long interval = 2000;

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  for(int i = 0; i < 10; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    
    for(int i = 0; i < 10; i++){
    
      int randomNumber = random(1, 101);
      
      if(randomNumber % 2 == 0){  
        digitalWrite(ledPins[i], LOW);  
      }
      else{  
        digitalWrite(ledPins[i], HIGH); 
      
      }
    }

  }

}
