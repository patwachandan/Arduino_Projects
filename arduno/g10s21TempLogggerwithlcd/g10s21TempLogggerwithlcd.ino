#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);   // ✅ Serial start
  lcd.begin(16, 2);
  dht.begin();
  
  lcd.print("Temp Logger");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Sensor Error");
    return;
  }

  lcd.clear();   // ⭐ Important Line

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp,1);   // 1 decimal only
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(hum,1);
  lcd.print(" %");

  delay(2000);

  // ✅ Serial Monitor Output
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C  ");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  delay(2000);
}