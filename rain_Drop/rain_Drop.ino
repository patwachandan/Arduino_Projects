#include <Servo.h>

Servo myServo;

int rainSensor = 7;  
int rainValue;

void setup() {
  pinMode(rainSensor, INPUT);
  myServo.attach(9);
  myServo.write(0);   // initial position
  Serial.begin(9600);
}

void loop() {

  rainValue = digitalRead(rainSensor);

  if (rainValue == LOW) {   // water detected
    Serial.println("Rain Detected");
    myServo.write(90);
  }
  else {                    // no rain
    Serial.println("No Rain");
    myServo.write(0);
  }

  delay(500);
}
