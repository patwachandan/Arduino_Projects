#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define SERVO_PIN 6

MFRC522 mfrc522(SS_PIN, RST_PIN);
Servo myServo;

// Allowed UID
byte allowedUID[4] = {0x42, 0x1A, 0xAB, 0x04};

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();

  myServo.attach(SERVO_PIN);
  myServo.write(0);  // Initial position

  Serial.println("Scan your RFID card...");
}

void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID tag : ");

  bool access = true;

  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    Serial.print(" ");

    if (mfrc522.uid.uidByte[i] != allowedUID[i]) {
      access = false;
    }
  }

  Serial.println();

  if (access) {
    Serial.println("Access Granted ✅");

    myServo.write(90);      // Rotate 90 degree
    delay(5000);            // Wait 5 seconds
    myServo.write(0);       // Back to initial position
  } 
  else {
    Serial.println("Access Denied ❌");
  }

  delay(2000);
}