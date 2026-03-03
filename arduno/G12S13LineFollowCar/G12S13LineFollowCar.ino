// IR sensor pins
#define leftIR 2
#define rightIR 3

// Motor pins
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define ENA 5
#define ENB 6

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  analogWrite(ENA, 150);   // Speed control
  analogWrite(ENB, 150);
}

void loop() {

  int leftSensor = digitalRead(leftIR);
  int rightSensor = digitalRead(rightIR);

  // Both on black line → forward
  if (leftSensor == 0 && rightSensor == 0) {
    forward();
  }

  // Left on line, Right off → turn right
  else if (leftSensor == 0 && rightSensor == 1) {
    turnRight();
  }

  // Right on line, Left off → turn left
  else if (leftSensor == 1 && rightSensor == 0) {
    turnLeft();
  }

  // Both off → stop
  else {
    stopMotors();
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}