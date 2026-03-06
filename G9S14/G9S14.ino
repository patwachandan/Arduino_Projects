int ldr = A0;
int sound = 2;
int buzzer = 8;

void setup()
{
  pinMode(sound, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int ldrValue = analogRead(ldr);
  int soundValue = digitalRead(sound);

  Serial.println(ldrValue);

  if(ldrValue < 40 || soundValue == LOW)
  {
    digitalWrite(buzzer, HIGH);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }

  delay(200);
}