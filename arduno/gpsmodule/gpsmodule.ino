#include <SoftwareSerial.h>
#include <TinyGPSPlus.h>

SoftwareSerial gsm(2, 3);       // D2 = RX, D3 = TX
SoftwareSerial gpsSerial(4, 5); // D4 = RX, D5 = TX

TinyGPSPlus gps;

#define trigPin 9
#define echoPin 10
#define buzzer 6
#define led 7

long duration;
int distance;
bool actionDone = false;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  gsm.begin(9600);
  gpsSerial.begin(9600);

  delay(2000);

  gsm.println("AT");
  delay(1000);
  gsm.println("AT+CMGF=1");   // SMS text mode

  Serial.println("System Ready");
}

void makeCall()
{
  gsm.println("ATD+917489591097;");   // apna number
  delay(1000);
}

void sendLocation(float lat, float lon)
{
  gsm.println("AT+CMGS=\"+917489591097\"");   // same number
  delay(1000);

  gsm.print("Ambulance detected.\nLocation:\n");
  gsm.print("https://maps.google.com/?q=");
  gsm.print(lat, 6);
  gsm.print(",");
  gsm.print(lon, 6);

  gsm.write(26);   // CTRL+Z
  delay(3000);
}

void loop()
{
  while (gpsSerial.available())
  {
    gps.encode(gpsSerial.read());
  }

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return;

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 20)
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);

    if (!actionDone)
    {
      makeCall();   // CALL

      if (gps.location.isValid())
      {
        sendLocation(gps.location.lat(),
                     gps.location.lng());
      }

      actionDone = true;
    }
  }
  else
  {
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    actionDone = false;
  }

  delay(500);
}