#include <Servo.h>

Servo myServo;

int ldrLeft = A0;
int ldrRight = A1;

int leftValue;
int rightValue;

int servoPos = 90;   // Starting position (center)

void setup() {
  myServo.attach(9);
  myServo.write(servoPos);

  Serial.begin(9600);
}

void loop() {
  leftValue = analogRead(ldrLeft);
  rightValue = analogRead(ldrRight);

  Serial.print("Left LDR: ");
  Serial.print(leftValue);
  Serial.print("  Right LDR: ");
  Serial.println(rightValue);

  int diff = leftValue - rightValue;

  if (diff < 50) {           // Light more on LEFT
    servoPos--;
  }
  else if (diff < -50) {    // Light more on RIGHT
    servoPos++;
  }

  servoPos = constrain(servoPos, 0, 180);
  myServo.write(servoPos);

  delay(30);
}
