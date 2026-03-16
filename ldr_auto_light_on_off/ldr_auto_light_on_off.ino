int ldr = 2;     // LDR module digital pin
int led = 8;     // LED pin

void setup() {
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  int value = digitalRead(ldr);

  if(value == HIGH)   // Dark condition
  {
    digitalWrite(led, HIGH);   // Light ON
  }
  else
  {
    digitalWrite(led, LOW);    // Light OFF
  }

}