#include <LiquidCrystal.h>

// LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Entry sensor
int trig1 = 9;
int echo1 = 10;

// Exit sensor
int trig2 = 7;
int echo2 = 6;

long duration1, duration2;
int distance1, distance2;

int count = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  lcd.print("Attendance");
  lcd.setCursor(0,1);
  lcd.print("Counter");
  delay(2000);
  lcd.clear();
}

void loop() {

  // Entry sensor reading
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);

  duration1 = pulseIn(echo1, HIGH);
  distance1 = duration1 * 0.034 / 2;

  // Exit sensor reading
  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);

  duration2 = pulseIn(echo2, HIGH);
  distance2 = duration2 * 0.034 / 2;

  // Entry detected
  if (distance1 < 20 && distance1 > 0) {
    count++;
    updateLCD();
    Serial.print("Entered: ");
    Serial.println(count);
    delay(2000);
  }

  // Exit detected
  if (distance2 < 20 && distance2 > 0) {
    if (count > 0) count--;
    updateLCD();
    Serial.print("Exited: ");
    Serial.println(count);
    delay(2000);
  }
}

void updateLCD() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Students Inside:");
  lcd.setCursor(0,1);
  lcd.print(count);
}
