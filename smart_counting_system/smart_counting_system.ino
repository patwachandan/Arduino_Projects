#include <Servo.h>

Servo myservo;
int pos = 90;          // Home position
int joyX;

void setup() {
  myservo.attach(9);
  myservo.write(pos);
}

void loop() {
  joyX = analogRead(A0);   // Read X-axis

  // Move LEFT fast
  if (joyX < 450) {
    pos -= 6;               // Speed (increase value for more speed)
    if (pos < 0) pos = 0;
  }
  // Move RIGHT fast
  else if (joyX > 570) {
    pos += 6;
    if (pos > 180) pos = 180;
  }
  // Auto return to center when joystick released
  else {
    if (pos < 90) pos += 4;   // return speed
    if (pos > 90) pos -= 4;
  }

  myservo.write(pos);
  delay(5);   // lower delay = more speed & smooth movement
}


