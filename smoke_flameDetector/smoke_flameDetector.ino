 int smoke = 7;
int flame = 6;
int buzzer = 8;

void setup() {
  pinMode(smoke, INPUT);
  pinMode(flame, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int smokeStatus = digitalRead(smoke);
  int flameStatus = digitalRead(flame);

  if (smokeStatus == LOW || flameStatus == LOW) {
    digitalWrite(buzzer, HIGH);
    Serial.println("Fire or Smoke Detected!");
  } 
  else {
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}