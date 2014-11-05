
#define LEFT_EYE 29
#define RIGHT_EYE 30

void setup() {
  pinMode(LEFT_EYE,OUTPUT);
  pinMode(RIGHT_EYE,OUTPUT);

}


void loop() {
  digitalWrite(LEFT_EYE, HIGH);
  digitalWrite(RIGHT_EYE, LOW);
  delay(250);
  digitalWrite(LEFT_EYE, LOW);
  digitalWrite(RIGHT_EYE, HIGH);
  delay(500);

}



