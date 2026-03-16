#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 9
#define BUZZER 4

Servo door;
MFRC522 rfid(SS_PIN, RST_PIN);

String masterCard = "27E5C55";

void setup() {

  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  door.attach(3);
  door.write(0);

  pinMode(BUZZER, OUTPUT);

  Serial.println("Scan RFID Card");
}

void loop() {

  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  String cardID = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    cardID += String(rfid.uid.uidByte[i], HEX);
  }

  cardID.toUpperCase();

  Serial.println(cardID);

  if (cardID == masterCard) {

    Serial.println("Access Granted");

    digitalWrite(BUZZER, HIGH);
    delay(200);
    digitalWrite(BUZZER, LOW);

    door.write(90);   // Door Open
    delay(5000);

    door.write(0);    // Door Close
  }

  else {

    Serial.println("Access Denied");

    digitalWrite(BUZZER, HIGH);
    delay(1000);
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}