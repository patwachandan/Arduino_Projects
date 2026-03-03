int mq5Pin = A0;
int relayPin = 8;
int buzzerPin = 7;
int ledPin = 6;

int threshold = 450;  // adjust after testing

void setup() {
  pinMode(relayPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(relayPin, HIGH); // Motor ON initially
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(mq5Pin);
  Serial.println(sensorValue);

  if (sensorValue < threshold) {
    // Alcohol detected → STOP vehicle
    digitalWrite(relayPin, LOW);
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
  } else {
    // Safe → RUN vehicle
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(100);
}