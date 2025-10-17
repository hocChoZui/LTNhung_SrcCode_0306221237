
int led_rr = 2;
int led_yr = 1;
int led_gr = 0;

int led_rb = 3;
int led_yb = 4;
int led_gb = 5;

bool led_state = false;

int red_time = 3000;
int yellow_time = 400;
int green_time = 5000;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_gr, OUTPUT);
  pinMode(led_gb, OUTPUT);

  pinMode(led_yr, OUTPUT);
  pinMode(led_yb, OUTPUT);

  pinMode(led_rr, OUTPUT);
  pinMode(led_rb, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (led_state != true) {
    digitalWrite(led_gr, HIGH);
    delay(green_time);
    digitalWrite(led_gr, LOW);

    digitalWrite(led_yr, HIGH);
    delay(yellow_time);
    digitalWrite(led_yr, LOW);

    digitalWrite(led_rr, HIGH);
    delay(red_time);
    digitalWrite(led_rr, LOW);

    led_state = true;
  } else {
    digitalWrite(led_gb, HIGH);
    delay(green_time);
    digitalWrite(led_gb, LOW);

    digitalWrite(led_yb, HIGH);
    delay(yellow_time);
    digitalWrite(led_yb, LOW);

    digitalWrite(led_rb, HIGH);
    delay(red_time);
    digitalWrite(led_rb, LOW);

    led_state = false;
  }
}