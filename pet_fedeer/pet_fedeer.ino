#include <Servo.h>

Servo myServo;

int irPin = 2;
int irState = 0;

void setup() {
  pinMode(irPin, INPUT);
  myServo.attach(9);
  myServo.write(0);   // initial position
}

void loop() {

  irState = digitalRead(irPin);

  if (irState == LOW) {   // object detected
    myServo.write(20);    // open servo
    delay(1000);          // keep open for 1 second
    myServo.write(0);     // close servo
    delay(1000);          // small delay to avoid repeat
  }

}