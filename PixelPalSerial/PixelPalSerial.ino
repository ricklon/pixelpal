#include <SoftPWMServo.h>

#define LEFT_EYE 29
#define RIGHT_EYE 30
#define WAIT 5
char inChar;

void setup() {
  Serial.begin(9600);
  pinMode(LEFT_EYE,OUTPUT);
  pinMode(RIGHT_EYE,OUTPUT);

}


void loop() {


  if(Serial.available() > 0) {
    inChar = Serial.read();

  }
  switch (inChar) {
  case 'a':
    digitalWrite(LEFT_EYE, HIGH);
    digitalWrite(RIGHT_EYE, HIGH);
    delay(250);
    digitalWrite(LEFT_EYE, LOW);
    digitalWrite(RIGHT_EYE, LOW);
    delay(500);
    break;
  case 'b':
    digitalWrite(LEFT_EYE, HIGH);
    digitalWrite(RIGHT_EYE, LOW);
    delay(250);
    digitalWrite(LEFT_EYE, LOW);
    digitalWrite(RIGHT_EYE, HIGH);
    delay(500);
    break;
  case 'c':
    for (int ii = 0; ii < 255; ii++) {
      SoftPWMServoPWMWrite(LEFT_EYE, ii);
      delay(WAIT);
    }
    for (int ii = 255; ii >  0; ii--) {
      SoftPWMServoPWMWrite(LEFT_EYE, ii);
      delay(WAIT);
    }
    for (int ii = 0; ii < 255; ii++) {
      SoftPWMServoPWMWrite(RIGHT_EYE, ii);
      delay(WAIT);
    }
    for (int ii = 255; ii >  0; ii--) {
      SoftPWMServoPWMWrite(RIGHT_EYE, ii);
      delay(WAIT);
    }
    break;
  default:
    digitalWrite(LEFT_EYE, HIGH);
    digitalWrite(RIGHT_EYE, HIGH);
    delay(250);
    digitalWrite(LEFT_EYE, LOW);
    digitalWrite(RIGHT_EYE, LOW);
    delay(500);

  }
}










