const int TRIG_PIN = 6;
const int ECHO_PIN = 7;
const int Buzzer_PIN  = 11;
const int DISTANCE_THRESHOLD = 10;
 
float duration_us, distance_cm;
void setup() {   Serial.begin (9600);        pinMode(TRIG_PIN, OUTPUT);   pinMode(ECHO_PIN, INPUT);    pinMode(Buzzer_PIN, OUTPUT);  } void loop() {   digitalWrite(TRIG_PIN, HIGH);   delayMicroseconds(10);   digitalWrite(TRIG_PIN, LOW);   duration_us = pulseIn(ECHO_PIN, HIGH);   distance_cm = 0.017 * duration_us;   if(distance_cm < DISTANCE_THRESHOLD)     digitalWrite(Buzzer_PIN, HIGH);   else     digitalWrite(Buzzer_PIN, LOW);    Serial.print("distance: ");   Serial.print(distance_cm);   Serial.println(" cm");   delay(500); }