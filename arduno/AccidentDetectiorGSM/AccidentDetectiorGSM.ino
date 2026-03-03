#include <SoftwareSerial.h>
SoftwareSerial gsm(2, 3); // TX, RX

#define trigPin 9
#define echoPin 10
#define buzzer 6
#define led 7

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  gsm.begin(9600);
  delay(1000);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 10) {   // Accident condition
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);

    sendSMS();
    delay(10000); // repeat SMS रोकने के लिए
  }
}

void sendSMS() {
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+916392385252\""); // Ambulance number
  delay(1000);
  gsm.print("Accident detected! Please send ambulance immediately.");
  delay(1000);
  gsm.write(26); // CTRL+Z
}