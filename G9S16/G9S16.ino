int pirPin = 2;
int ldrPin = A0;
int ledPin = 13;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int motion = digitalRead(pirPin);
  int lightLevel = analogRead(ldrPin);

  Serial.print("LDR: ");
  Serial.println(lightLevel);

  if (motion == HIGH && lightLevel < 500) {
    digitalWrite(ledPin, HIGH);   // Light ON
  } 
  else {
    digitalWrite(ledPin, LOW);    // Light OFF
  }

  delay(200);
}