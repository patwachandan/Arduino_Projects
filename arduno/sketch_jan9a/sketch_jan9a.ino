#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/*
   LCD Library  : NewliquidCrystal
   LCD Address  : 0x27
   LCD Size     : 16x2
*/

LiquidCrystal_I2C lcd(0x27, 16, 2);  

// Pulse Sensor Pin
int pulsePin = A0;
int blinkPin = 13;

// Volatile Variables (Used in ISR)
volatile int BPM;
volatile int Signal;
volatile int IBI = 600;
volatile boolean Pulse = false;
volatile boolean QS = false;

volatile int rate[10];
volatile unsigned long sampleCounter = 0;
volatile unsigned long lastBeatTime = 0;
volatile int P = 512;
volatile int T = 512;
volatile int thresh = 525;
volatile int amp = 100;
volatile boolean firstBeat = true;
volatile boolean secondBeat = false;

// -------------------- SETUP --------------------
void setup()
{
  Serial.begin(115200);
  pinMode(blinkPin, OUTPUT);

  // LCD Initialization (IMPORTANT FIX)
  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Heart Beat");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring...");
  delay(2000);
  lcd.clear();

  interruptSetup();
}

// -------------------- LOOP --------------------
void loop()
{
  if (QS == true)  // Heartbeat detected
  {
    Serial.print("Heart-Beat Found BPM: ");
    Serial.println(BPM);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Heart Rate");

    lcd.setCursor(0, 1);
    lcd.print(BPM);
    lcd.print(" BPM");

    QS = false;
    delay(1000);
  }
}

// ---------------- TIMER INTERRUPT SETUP ----------------
void interruptSetup()
{
  TCCR2A = 0x02;
  TCCR2B = 0x06;
  OCR2A = 0x7C;
  TIMSK2 = 0x02;
  sei();  
}

// ---------------- TIMER2 ISR ----------------
ISR(TIMER2_COMPA_vect)
{
  cli();

  Signal = analogRead(pulsePin);
  sampleCounter += 2;
  int N = sampleCounter - lastBeatTime;

  if (Signal < thresh && N > (IBI / 5) * 3)
  {
    if (Signal < T)
      T = Signal;
  }

  if (Signal > thresh && Signal > P)
  {
    P = Signal;
  }

  if (N > 250)
  {
    if ((Signal > thresh) && (Pulse == false) && (N > (IBI / 5) * 3))
    {
      Pulse = true;
      digitalWrite(blinkPin, HIGH);

      IBI = sampleCounter - lastBeatTime;
      lastBeatTime = sampleCounter;

      if (secondBeat)
      {
        secondBeat = false;
        for (int i = 0; i <= 9; i++)
          rate[i] = IBI;
      }

      if (firstBeat)
      {
        firstBeat = false;
        secondBeat = true;
        sei();
        return;
      }

      word runningTotal = 0;
      for (int i = 0; i < 9; i++)
      {
        rate[i] = rate[i + 1];
        runningTotal += rate[i];
      }

      rate[9] = IBI;
      runningTotal += rate[9];
      runningTotal /= 10;

      BPM = 60000 / runningTotal;
      QS = true;
    }
  }

  if (Signal < thresh && Pulse == true)
  {
    digitalWrite(blinkPin, LOW);
    Pulse = false;
    amp = P - T;
    thresh = amp / 2 + T;
    P = thresh;
    T = thresh;
  }

  if (N > 2500)
  {
    thresh = 512;
    P = 512;
    T = 512;
    lastBeatTime = sampleCounter;
    firstBeat = true;
    secondBeat = false;
  }

  sei();
}
