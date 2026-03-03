int ldr = A0;
int led = 13;
int value = 0;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(ldr);
  Serial.println(value);

  if(value < 500)   // Dark condition
  {
    digitalWrite(led, HIGH);   // Light ON
  }
  else
  {
    digitalWrite(led, LOW);    // Light OFF
  }

  delay(200);
}
