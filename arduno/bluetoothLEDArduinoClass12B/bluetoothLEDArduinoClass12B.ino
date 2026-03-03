#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX

int led = 8;
int buzzer = 9;
char data;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  bluetooth.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if (bluetooth.available()) {
    data = bluetooth.read();
    Serial.println(data);

    if (data == 'A') {
      digitalWrite(led, HIGH);
    }
    if (data == 'a') {
      digitalWrite(led, LOW);
    }
    if (data == 'B') {
      digitalWrite(buzzer, HIGH);
    }
    if (data == 'b') {
      digitalWrite(buzzer, LOW);
    }
  }
}
