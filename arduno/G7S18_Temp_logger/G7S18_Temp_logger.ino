#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define BUZZER 3

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);

  lcd.print("Temp Logger");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    return;
  }

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.print((char)223); // degree symbol
  lcd.print("C ");

  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(hum);
  lcd.print("% ");

  // Serial Monitor Log
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("  Hum: ");
  Serial.println(hum);

  // 🔔 Alert Condition
  if (temp > 35) {
    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(BUZZER, LOW);
    delay(300);
  } else {
    digitalWrite(BUZZER, LOW);
    delay(1500);
  }
}
