int Input = A0;

int Buzzer = A1;

int GreenLED = A2;

int RedLED = A3;

int value;

int MAX = 600;



void setup() {

  Serial.begin(9600);

  pinMode(Input ,INPUT);

  pinMode(RedLED ,OUTPUT);

  pinMode(GreenLED ,OUTPUT);

  pinMode(Buzzer ,OUTPUT);

}



void loop() {

  value = analogRead(A0);

  if (value >= MAX) {

    digitalWrite(GreenLED ,LOW);

    digitalWrite(RedLED ,HIGH);

    digitalWrite(Buzzer ,HIGH);

    delay(5000);

    digitalWrite(Buzzer ,LOW);

    delay(6000);

  }

  else {

    digitalWrite(RedLED ,LOW);

    digitalWrite(Buzzer ,LOW);

    digitalWrite(GreenLED ,HIGH);

  }

}