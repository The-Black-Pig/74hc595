// Modified by Steve Clements 2019

// Uses two daisy chained 74hc595 chips to
// make a 16 LED random display.

// WARNING: the 74hc595 cannot cope with more than 20mA on
// each output pin and not more than 80mA total. therefore
// if connecting LEDs direct to chip outputs use higher
// value resistors. I use green LEDs with 2K to 3K resistors.

//Pin connected to ST_CP of 74HC595 (pin 12)
int latchPin = 8;
//Pin connected to SH_CP of 74HC595 (pin 11)
int clockPin = 12;
////Pin connected to DS of 74HC595 (pin 14)
int dataPin = 11;

int tDelay = 200;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  // turn all leds off
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  // push the second byte into chip 1, which pushes the first byte into chip 2
  shiftOut(dataPin, clockPin, MSBFIRST, 0);
  digitalWrite(latchPin, HIGH);
  delay(500);
}

void loop() {
  
        //ground latchPin and hold low for as long as you are transmitting
        digitalWrite(latchPin, LOW);
        int randomNumber = random(0, 255);
        // push the firstbyte into chip 1
        shiftOut(dataPin, clockPin, MSBFIRST, randomNumber);
        randomNumber = random(0, 255);
        // push the second byte into chip 1, which pushes the first byte into chip 2
        shiftOut(dataPin, clockPin, MSBFIRST, randomNumber);
        digitalWrite(latchPin, HIGH);
        delay(tDelay);
        
}
