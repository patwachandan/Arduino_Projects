// Motor pins
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;

int ena = 5;
int enb = 6;

int lightPin = 12;
int buzzerPin = 13;

char command;

void setup() {
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);

  pinMode(lightPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    if (command == 'F') {       // Forward
      forward();
    }
    else if (command == 'B') {  // Backward
      backward();
    }
    else if (command == 'L') {  // Left
      left();
    }
    else if (command == 'R') {  // Right
      right();
    }
    else if (command == 'S') {  // Stop
      stopCar();
    }
    else if (command == 'W') {  // Light ON
      digitalWrite(lightPin, HIGH);
    }
    else if (command == 'w') {  // Light OFF
      digitalWrite(lightPin, LOW);
    }
    else if (command == 'H') {  // Horn
      digitalWrite(buzzerPin, HIGH);
      delay(300);
      digitalWrite(buzzerPin, LOW);
    }
  }
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopCar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}