// pushData function based on code from Carlyn Maw,Tom Igoe
// Modified for multiple 74hc595 chips by Steve Clements 2019

// Uses two daisy chained 74hc595s to make a 16 LED
// random display.

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

int tDelay = 9150; // tDelay = 9150µs the delay required for the process to complete in 10 minutes

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pushData(0,0);
}

void loop() {
  //count up routine
  for (int i = 0; i < 256; i++) {
      for (int j = 0; j < 256; j++) {
        pushData(i, j);
      }
  }
  // wait a few of seconds to show process has completed, then repeat
  delay(5000);
}


void pushData(byte fstByte, byte scndByte){
  
  // pull latch pin low to accept data
  digitalWrite(latchPin, LOW);
  // push the firstbyte into chip 1
  shiftOut(dataPin, clockPin, MSBFIRST, fstByte);
  // push the second byte into chip 1, which pushes the first byte into chip 2
  shiftOut(dataPin, clockPin, MSBFIRST, scndByte);
  // pull latch pin high to stop accepting data
  digitalWrite(latchPin, HIGH);
  delayMicroseconds(tDelay);
  
}
