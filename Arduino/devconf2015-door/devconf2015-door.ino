// DevConf 2015 IoT Demo Door
// Version 1.3
//
// Developed for Arduino Nano (rev. 3)
//
// The HW project can be found at https://github.com/pmacik/electronics/tree/master/KiCad/devconf2015-door
#include <Servo.h> 
 
Servo servo; 

// pins
const int semaphore = 4;
const int button = 7;
const int doorOpen = 8;
const int servoPin = 9;

// constants
const int lockedPos = 20;
const int unlockedPos = 102;
const int changePositionDelay = 5;

void setup() { 
  servo.attach(servoPin);
  servo.write(lockedPos);
  pinMode(button, INPUT);
  pinMode(doorOpen, INPUT);
  pinMode(semaphore, OUTPUT);
} 
 
void loop() { 
  while(digitalRead(button) == 0) { // wait for signal
    delay(1);
  }
  digitalWrite(semaphore, HIGH);
  for(int i = lockedPos; i < unlockedPos; i++) {
    servo.write(i);
    delay(changePositionDelay);
  }
  delay (5000);
  int state = HIGH;
  while(digitalRead(doorOpen) == HIGH) { // wait for doors to get closed
    if(state == HIGH){
      state = LOW;
    } else {
      state = HIGH;
    }
    digitalWrite(semaphore, state);
  }
  digitalWrite(semaphore, LOW);
  for(int i = unlockedPos; i > lockedPos; i--) {
    servo.write(i);
    delay(changePositionDelay);
  }
} 
