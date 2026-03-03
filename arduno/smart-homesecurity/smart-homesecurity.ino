#include <Servo.h>
#include <SoftwareSerial.h>

Servo gate;
SoftwareSerial BT(10, 11); // TX, RX

#define trigPin 2
#define echoPin 3
#define ledPin 6
#define buzzer 7

int ldrPin = A0;
char data;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  gate.attach(9);
  gate.write(0); // gate closed

  Serial.begin(9600);
  BT.begin(9600);
}

void loop() {

  // Ultrasonic Distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Gate Control
  if (distance < 20) {
    gate.write(90);
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);
  } else {
    gate.write(0);
  }

  // LDR Light Control
  int ldrValue = analogRead(ldrPin);
  if (ldrValue < 400) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // Bluetooth Control
  if (BT.available()) {
    data = BT.read();

    if (data == 'O') gate.write(90);
    if (data == 'C') gate.write(0);
    if (data == 'L') digitalWrite(ledPin, HIGH);
    if (data == 'F') digitalWrite(ledPin, LOW);
  }
}