int pirPin = 2;      
int buzzerPin = 8;   
int ledPin = 7;      

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    digitalWrite(buzzerPin, HIGH);  
    digitalWrite(ledPin, HIGH);     
    Serial.println("Motion Detected!");
  } 
  else {
    digitalWrite(buzzerPin, LOW);   
    digitalWrite(ledPin, LOW);      
    Serial.println("No Motion");
  }

  delay(300);
}