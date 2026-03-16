#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define S0 4
#define S1 5
#define S2 6
#define S3 7

int red, green, blue;

void setup()
{
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  lcd.begin();
  lcd.backlight();

  Serial.begin(9600);
}

void loop()
{

  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  red = analogRead(A0);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  green = analogRead(A0);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  blue = analogRead(A0);

  lcd.clear();

  if(red < green && red < blue)
  {
    lcd.print("Color: RED");
  }

  else if(green < red && green < blue)
  {
    lcd.print("Color: GREEN");
  }

  else if(blue < red && blue < green)
  {
    lcd.print("Color: BLUE");
  }

  delay(500);
}