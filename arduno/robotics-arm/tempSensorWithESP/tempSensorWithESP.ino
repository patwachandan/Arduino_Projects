#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "DHT.h"

#define DHTPIN D4
#define DHTTYPE DHT11   // or DHT22

DHT dht(DHTPIN, DHTTYPE);
ESP8266WebServer server(80);

const char* ssid = "ESP8266_DHT";
const char* password = "12345678";

void handleRoot() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  String html = "<!DOCTYPE html><html>";
  html += "<head><meta http-equiv='refresh' content='2'>";
  html += "<title>ESP8266 DHT Dashboard</title>";
  html += "<style>";
  html += "body{font-family:Arial;text-align:center;background:#f4f4f4;}";
  html += ".card{background:white;padding:20px;margin:20px;border-radius:10px;}";
  html += "</style></head><body>";

  html += "<h1>ESP8266 Local Web Dashboard</h1>";
  html += "<div class='card'><h2>Temperature</h2><p>";
  html += temp;
  html += " °C</p></div>";

  html += "<div class='card'><h2>Humidity</h2><p>";
  html += hum;
  html += " %</p></div>";

  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  WiFi.softAP(ssid, password);
  Serial.println("SoftAP Started");
  Serial.println(WiFi.softAPIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
