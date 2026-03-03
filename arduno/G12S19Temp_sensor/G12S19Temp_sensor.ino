#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define RELAY_PIN 8
#define BUZZER_PIN 9

DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH);   // relay off (most modules are active LOW)
  digitalWrite(BUZZER_PIN, LOW);

  dht.begin();
}

void loop() 
{
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  if (temperature >= 30.0)
  {
    digitalWrite(RELAY_PIN, LOW);   // fan ON
    digitalWrite(BUZZER_PIN, HIGH);
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);  // fan OFF
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(2000);
}