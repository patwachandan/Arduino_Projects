const int sensor1 = 8;
const int sensor2 = 9;

unsigned long time1 = 0;
unsigned long time2 = 0;
float speed;

float distance = 0.10; // Distance between sensors in meters (10 cm)

void setup() {
  Serial.begin(9600);
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
}

void loop() {

  if (digitalRead(sensor1) == LOW) {
    time1 = millis();
    delay(100);  
  }

  if (digitalRead(sensor2) == LOW) {
    time2 = millis();
    
    float timeTaken = (time2 - time1) / 1000.0; // seconds
    
    if (timeTaken > 0) {   // avoid divide by zero
      speed = distance / timeTaken;   // m/s
      speed = speed * 3.6;            // convert to km/h

      Serial.print("Speed: ");
      Serial.print(speed);
      Serial.println(" km/h");
    }

    delay(1000);
  }
}