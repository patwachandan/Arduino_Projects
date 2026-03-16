#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

Servo windowServo;

int gasPin = A0;
int ldrPin = A1;

int rainPin = 3;
int motionPin = 4;

int buzzer = 5;
int lightLED = 6;

int servoPin = 7;

int trig = 9;
int echo = 10;

long duration;
int distance;

void setup() {

Serial.begin(9600);

pinMode(rainPin, INPUT);
pinMode(motionPin, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(lightLED, OUTPUT);

pinMode(trig, OUTPUT);
pinMode(echo, INPUT);

windowServo.attach(servoPin);

dht.begin();

display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
}

void loop() {

float temp = dht.readTemperature();
float hum = dht.readHumidity();

int gasValue = analogRead(gasPin);
int ldrValue = analogRead(ldrPin);

int rainState = digitalRead(rainPin);
int motionState = digitalRead(motionPin);

digitalWrite(trig, LOW);
delayMicroseconds(2);

digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

duration = pulseIn(echo, HIGH);
distance = duration * 0.034 / 2;

if(gasValue > 250)
{
digitalWrite(buzzer, HIGH);
}
else
{
digitalWrite(buzzer, LOW);
}

if(motionState == HIGH)
{
digitalWrite(lightLED, HIGH);
}

if(rainState == LOW)
{
windowServo.write(0);
}
else
{
windowServo.write(90);
}

if(ldrValue < 300)
{
digitalWrite(lightLED, LOW);
}
else
{
digitalWrite(lightLED, HIGH);
}

display.clearDisplay();

display.setTextSize(1);
display.setTextColor(WHITE);

display.setCursor(0,0);
display.print("Temp: ");
display.print(temp);

display.setCursor(0,10);
display.print("Hum: ");
display.print(hum);

display.setCursor(0,20);
display.print("Gas: ");
display.print(gasValue);

display.setCursor(0,30);
display.print("Dist: ");
display.print(distance);

display.setCursor(0,40);
display.print("LDR: ");
display.print(ldrValue);

display.display();

delay(1000);
}