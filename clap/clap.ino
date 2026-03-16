int soundSensor = 2;
int led = 13;

int clap = 0;
bool ledState = false;

void setup() {
  pinMode(soundSensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  int sound = digitalRead(soundSensor);

  if(sound == HIGH){
    
    clap++;
    delay(300);

    if(clap == 1){
      ledState = !ledState;
      digitalWrite(led, ledState);
      clap = 0;
    }
  }

}