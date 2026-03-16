#include <Servo.h>

Servo myservo;

int ldrLeft = A0;
int ldrRight = A1;

int servoPos = 90;

void setup() {
  myservo.attach(9);
  myservo.write(servoPos);
  Serial.begin(9600);
}

void loop() {

  int leftValue = analogRead(ldrLeft);
  int rightValue = analogRead(ldrRight);

  Serial.print("Left: ");
  Serial.print(leftValue);
  Serial.print(" Right: ");
  Serial.println(rightValue);

  if (leftValue > rightValue + 50) {
    servoPos--;
    myservo.write(servoPos);
    delay(20);
  }

  if (rightValue > leftValue + 50) {
    servoPos++;
    myservo.write(servoPos);
    delay(20);
  }

  delay(100);
}