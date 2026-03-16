#include <Servo.h>

// Create 7 servo objects
Servo servo[7];

// Define servo pins
int servoPins[7] = {2, 3, 4, 5, 6, 7, 8};

// Define positions
int POS_0 = 0;
int POS_90 = 90;
int POS_180 = 180;

// Define servo angles for digits 0-9
int digitAngles[10][7] = {
  // s1, s2, s3, s4, s5, s6, s7  (for digits 0 to 9)
  {90,  0, 90, 90, 90, 90, 90},   // 0
  { 0,  0,180,180,  0, 90, 90},   // 1
  {90, 90, 90,180, 90, 90,180},   // 2
  {90, 90, 90,180,  0, 90, 90},   // 3
  { 0, 90,180, 90,  0, 90, 90},   // 4
  {90, 90, 90, 90,  0,  0, 90},   // 5
  {90, 90, 90, 90, 90,  0, 90},   // 6
  {90, 90,180,180,  0, 90, 90},   // 7
  {90, 90, 90, 90, 90, 90, 90},   // 8
  {90, 90, 90, 90,  0, 90, 90}    // 9
};

void setup() {
  // Attach all servos
  for (int i = 0; i < 7; i++) {
    servo[i].attach(servoPins[i]);
  }

  // Begin Serial Communication
  Serial.begin(9600);
  Serial.println("7-Segment Servo Display Starting...");
}

void loop() {
  for (int digit = 0; digit < 10; digit++) {
    Serial.print("Displaying digit: ");
    Serial.println(digit);

    // Move servos to required angles for current digit
    for (int i = 0; i < 7; i++) {
      servo[i].write(digitAngles[digit][i]);
    }

    delay(4000); // Wait for 4 seconds before showing next digit
  }
}
