int ldrPin = A0;
int buzzer = 8;
int ldrValue = 0;
int threshold = 500;   // Adjust according to light condition

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);

  if (ldrValue < threshold) {
    digitalWrite(buzzer, HIGH);  // Alarm ON
  } else {
    digitalWrite(buzzer, LOW);   // Alarm OFF
  }

  delay(200);
}