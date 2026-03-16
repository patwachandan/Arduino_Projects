#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(128, 64, &Wire, -1);

int sensorPin = A0;
int turbidity;

void setup() {

  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {

  turbidity = analogRead(sensorPin);

  display.clearDisplay();

  display.setCursor(0,10);
  display.print("Turbidity:");
  display.println(turbidity);

  display.setCursor(0,30);

  if(turbidity > 700)
  display.println("Water Dirty");
  else
  display.println("Water Clean");

  display.display();

  delay(1000);
}