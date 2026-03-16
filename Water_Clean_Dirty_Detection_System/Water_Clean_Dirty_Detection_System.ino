#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int sensorPin = A0;
int turbidity;

void setup()
{
  lcd.begin();
  lcd.backlight();
  
  Serial.begin(9600);
}

void loop()
{
  turbidity = analogRead(sensorPin);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Turbidity:");
  lcd.print(turbidity);

  lcd.setCursor(0,1);

  if(turbidity > 700)
  {
    lcd.print("Water: Dirty");
  }
  else
  {
    lcd.print("Water: Clean");
  }

  delay(1000);
}