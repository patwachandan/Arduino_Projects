#include <Servo.h>

Servo radar;

int trigPin = 2;
int echoPin = 3;
int buzzer  = 6;

long duration;
int distance;

void setup() {
  radar.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {

  for(int angle = 15; angle <= 165; angle++) {
    radar.write(angle);
    delay(20);
    distance = getDistance();

    if(distance > 0 && distance < 20) {
      digitalWrite(buzzer, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
    }
  }

  for(int angle = 165; angle >= 15; angle--) {
    radar.write(angle);
    delay(20);
    distance = getDistance();

    if(distance > 0 && distance < 20) {
      digitalWrite(buzzer, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
    }
  }
}

int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 25000);

  if(duration == 0) return -1;

  int dist = duration * 0.034 / 2;
  return dist;
}