#include <SoftPWMServo.h>

#define LEFT_EYE 29
#define RIGHT_EYE 30
#define WAIT 5

int fadeAMT = 1;
int fadeVal = 0;

char inChar;

int blink1_id;
unsigned long blink1_var;
int fade_id;
unsigned long fade_var;


void blink_task1(int id, void * tptr) {
  digitalWrite(LEFT_EYE, !digitalRead(LEFT_EYE)); // Toggle pin state
}

void fade_task1(int id, void * tptr) {
  Serial.print("fadeVal: ");
  Serial.println(fadeVal);
  SoftPWMServoPWMWrite(RIGHT_EYE, fadeVal);
  fadeVal = fadeVal + fadeAMT;

  if (fadeVal >= 255 || fadeVal < 1) {
    fadeAMT = -fadeAMT;
  }
 
}


void setup() {
  Serial.begin(9600);
  pinMode(LEFT_EYE,OUTPUT);
  pinMode(RIGHT_EYE,OUTPUT);

  blink1_id = createTask(blink_task1, 250, TASK_ENABLE, &blink1_var);
  fade_id = createTask(fade_task1, 20, TASK_ENABLE, &fade_var);
}


void loop() {

}












