int red[] = {2,5,8,11};
int yellow[] = {3,6,9,12};
int green[] = {4,7,10,13};

int sensor[] = {A0,A1,A2,A3};

void setup() {
  for(int i=0;i<4;i++){
    pinMode(red[i], OUTPUT);
    pinMode(yellow[i], OUTPUT);
    pinMode(green[i], OUTPUT);
    pinMode(sensor[i], INPUT);
  }
}

void loop() {

  for(int i=0;i<4;i++){

    // Sab roads red
    for(int j=0;j<4;j++){
      digitalWrite(red[j], HIGH);
      digitalWrite(yellow[j], LOW);
      digitalWrite(green[j], LOW);
    }

    int density = digitalRead(sensor[i]);

    digitalWrite(red[i], LOW);
    digitalWrite(green[i], HIGH);

    if(density == HIGH){
      delay(8000);   // High traffic → 8 sec
    }
    else{
      delay(4000);   // Low traffic → 4 sec
    }

    digitalWrite(green[i], LOW);
    digitalWrite(yellow[i], HIGH);
    delay(2000);

    digitalWrite(yellow[i], LOW);
  }
}