#define TRIG_ENTRY 2
#define ECHO_ENTRY 3
#define TRIG_EXIT 4
#define ECHO_EXIT 5
#define BUZZER 6
#define LED_ENTRY 7
#define LED_EXIT 8

int peopleCount = 0;

long readDistance(int trigPin, int echoPin){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  long distance = duration * 0.034 / 2; // cm
  return distance;
}

void setup() {
  pinMode(TRIG_ENTRY, OUTPUT);
  pinMode(ECHO_ENTRY, INPUT);
  pinMode(TRIG_EXIT, OUTPUT);
  pinMode(ECHO_EXIT, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_ENTRY, OUTPUT);
  pinMode(LED_EXIT, OUTPUT);

  Serial.begin(9600);
  Serial.println("Person Counter Started");
}

void loop() {
  long distanceEntry = readDistance(TRIG_ENTRY, ECHO_ENTRY);
  long distanceExit = readDistance(TRIG_EXIT, ECHO_EXIT);

  // Entry detected
  if(distanceEntry < 50){
    peopleCount++;
    Serial.print("Person Entered: ");
    Serial.println(peopleCount);
    digitalWrite(LED_ENTRY, HIGH);
    tone(BUZZER, 1000, 200);
    delay(1000); // avoid double counting
    digitalWrite(LED_ENTRY, LOW);
  }

  // Exit detected
  if(distanceExit < 50){
    if(peopleCount > 0) peopleCount--;
    Serial.print("Person Exited: ");
    Serial.println(peopleCount);
    digitalWrite(LED_EXIT, HIGH);
    tone(BUZZER, 500, 200);
    delay(1000); // avoid double counting
    digitalWrite(LED_EXIT, LOW);
  }

  delay(200);
}