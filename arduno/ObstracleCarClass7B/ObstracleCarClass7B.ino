#include <Servo.h>

Servo myServo;

#define trigPin 9
#define echoPin 8

#define M1 4
#define M2 5
#define M3 6
#define M4 7

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  myServo.attach(10);
  myServo.write(90);

  Serial.begin(9600);
}

int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);  // timeout add

  if (duration == 0) {
    return 0;
  }

  distance = duration * 0.034 / 2;
  return distance;
}


void forward() {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
}

void stopCar() {
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
}

void leftTurn() {
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, HIGH);
  digitalWrite(M4, LOW);
  delay(500);
}

void rightTurn() {
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  delay(500);
}

void loop() {

  distance = getDistance();
  Serial.println(distance);

  // Ignore 0 reading
  if (distance == 0) {
    forward();
    return;
  }

  if (distance > 15) {
    forward();
  } 
  else {
    stopCar();
    delay(300);
    rightTurn();   // sirf right turn test ke liye
  }
}


