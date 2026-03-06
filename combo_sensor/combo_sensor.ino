#define GAS_SENSOR A0
#define SOUND_SENSOR 7
#define TRIG 9
#define ECHO 10
#define BUZZER 6
#define LED 5

long duration;
int distance;

void setup()
{
  pinMode(SOUND_SENSOR, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);
}

void loop()
{

  // GAS SENSOR
  int gasValue = analogRead(GAS_SENSOR);
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if(gasValue > 300)
  {
    Serial.println("Gas Detected!");
    digitalWrite(BUZZER, HIGH);
    digitalWrite(LED, HIGH);
  }

  // ULTRASONIC SENSOR
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < 20)
  {
    Serial.println("Intruder Detected!");
    digitalWrite(BUZZER, HIGH);
  }

  // SOUND SENSOR
  int sound = digitalRead(SOUND_SENSOR);

  if(sound == HIGH)
  {
    Serial.println("Loud Sound Detected!");
    digitalWrite(LED, HIGH);
  }

  delay(500);

  digitalWrite(BUZZER, LOW);
  digitalWrite(LED, LOW);
}