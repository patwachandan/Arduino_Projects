int ldrPin = A0;
int soundPin = 2;   // DO pin connected
int buzzer = 8;

int lightValue;
int soundValue;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(ldrPin);
  soundValue = digitalRead(soundPin);

  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print("  Sound: ");
  Serial.println(soundValue);

  // Agar andhera ho ya light suddenly change ho
  if (lightValue < 50) {
    digitalWrite(buzzer, HIGH);
  }
  // Agar clap/sound detect ho
  else if (soundValue == HIGH) {
    digitalWrite(buzzer, HIGH);
  }
  else {
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}
