#define trigPin 9
#define echoPin 10
#define buzzer 6
#define led 7

long duration;
int distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if(distance > 0 && distance < 10)
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    Serial.println("AMBULANCE ALERT SENT");
    delay(3000);
  }
  else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
  }
}