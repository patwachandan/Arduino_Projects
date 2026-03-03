#include <SoftwareSerial.h>

// Bluetooth on safe pins
SoftwareSerial BT(A0, A1); // RX, TX

// -------- FRONT L298N --------
int FL_IN1 = 2;
int FL_IN2 = 3;
int FR_IN1 = 4;
int FR_IN2 = 7;
int ENA1 = 5;
int ENB1 = 6;

// -------- REAR L298N --------
int RL_IN1 = 8;
int RL_IN2 = 9;
int RR_IN1 = 11;
int RR_IN2 = 12;
int ENA2 = 10;
int ENB2 = 13;

// Speed (0–255)
int speedCar = 200;

void setup() {
  int pins[] = {
    FL_IN1, FL_IN2, FR_IN1, FR_IN2,
    RL_IN1, RL_IN2, RR_IN1, RR_IN2,
    ENA1, ENB1, ENA2, ENB2
  };

  for (int i = 0; i < 12; i++) {
    pinMode(pins[i], OUTPUT);
  }

  analogWrite(ENA1, speedCar);
  analogWrite(ENB1, speedCar);
  analogWrite(ENA2, speedCar);
  analogWrite(ENB2, speedCar);

  BT.begin(9600);
}

void loop() {
  if (BT.available()) {
    char cmd = BT.read();

    switch (cmd) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stopCar(); break;
    }
  }
}

// -------- MOVEMENT FUNCTIONS --------

void forward() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  digitalWrite(RL_IN1, HIGH); digitalWrite(RL_IN2, LOW);
  digitalWrite(RR_IN1, HIGH); digitalWrite(RR_IN2, LOW);
}

void backward() {
  digitalWrite(FL_IN1, LOW); digitalWrite(FL_IN2, HIGH);
  digitalWrite(FR_IN1, LOW); digitalWrite(FR_IN2, HIGH);
  digitalWrite(RL_IN1, LOW); digitalWrite(RL_IN2, HIGH);
  digitalWrite(RR_IN1, LOW); digitalWrite(RR_IN2, HIGH);
}

void left() {
  digitalWrite(FL_IN1, LOW); digitalWrite(FL_IN2, HIGH);
  digitalWrite(RL_IN1, LOW); digitalWrite(RL_IN2, HIGH);
  digitalWrite(FR_IN1, HIGH); digitalWrite(FR_IN2, LOW);
  digitalWrite(RR_IN1, HIGH); digitalWrite(RR_IN2, LOW);
}

void right() {
  digitalWrite(FL_IN1, HIGH); digitalWrite(FL_IN2, LOW);
  digitalWrite(RL_IN1, HIGH); digitalWrite(RL_IN2, LOW);
  digitalWrite(FR_IN1, LOW); digitalWrite(FR_IN2, HIGH);
  digitalWrite(RR_IN1, LOW); digitalWrite(RR_IN2, HIGH);
}

void stopCar() {
  digitalWrite(FL_IN1, LOW); digitalWrite(FL_IN2, LOW);
  digitalWrite(FR_IN1, LOW); digitalWrite(FR_IN2, LOW);
  digitalWrite(RL_IN1, LOW); digitalWrite(RL_IN2, LOW);
  digitalWrite(RR_IN1, LOW); digitalWrite(RR_IN2, LOW);
}