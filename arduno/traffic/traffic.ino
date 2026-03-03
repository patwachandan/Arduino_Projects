// Pin definitions
const int redLedPin = 13;
const int yellowLedPin = 12;
const int greenLedPin = 11;

// Time intervals (in milliseconds)
const int redTime = 5000;    // Red light duration
const int yellowTime = 2000; // Yellow light duration
const int greenTime = 5000;  // Green light duration

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  // Red light
  digitalWrite(redLedPin, HIGH);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  delay(redTime);

  // Green light
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);
  delay(greenTime);

  // Yellow light
  digitalWrite(redLedPin, LOW);
  digitalWrite(yellowLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
  delay(yellowTime);
}