int gasSensor = A0;
int buzzer = 8;
int threshold = 100;   // Adjust this value

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(gasSensor);
  Serial.println(sensorValue);

  if (sensorValue > threshold) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}