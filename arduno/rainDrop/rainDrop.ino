#include <Servo.h>

Servo myServo;

int rainPin = 2;
int servoPin = 9;

void setup() {
  pinMode(rainPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);   // कपड़े बाहर
}

void loop() {
  int rainStatus = digitalRead(rainPin);

  if (rainStatus == LOW) {
    // बारिश हो रही है
    myServo.write(90);   // कपड़े अंदर
  } else {
    // बारिश नहीं
    myServo.write(0);    // कपड़े बाहर
  }

  delay(500);
}
