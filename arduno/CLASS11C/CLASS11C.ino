#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address (0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Ultrasonic sensor pins
#define trig1 2
#define echo1 3
#define trig2 4
#define echo2 5

int people = 0;
bool inFlag = false;
bool outFlag = false;

// Function to measure distance
int getDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 25000);
  if (duration == 0) return 100;

  return duration * 0.034 / 2;
}

void setup() {
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  lcd.begin();   // ✅ FIXED
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("People Count");
  lcd.setCursor(0, 1);
  lcd.print("Inside: 0");

  Serial.begin(9600);
}

void loop() {
  int d1 = getDistance(trig1, echo1);
  int d2 = getDistance(trig2, echo2);

  // ENTRY
  if (d1 < 10 && !inFlag) {
    people++;
    inFlag = true;
    updateLCD();
    delay(400);
  }

  // EXIT
  if (d2 < 10 && !outFlag && people > 0) {
    people--;
    outFlag = true;
    updateLCD();
    delay(400);
  }

  if (d1 > 15) inFlag = false;
  if (d2 > 15) outFlag = false;
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("People Count");
  lcd.setCursor(0, 1);
  lcd.print("Inside: ");
  lcd.print(people);
}
