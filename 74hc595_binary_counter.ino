// Uses two daisy chained 74hc595 chips to count
// in binary from 0 to 65536 in exactly 10 minutes

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
}

void loop() {
  //count up routine
  for (int i = 0; i < 256; i++) {
      for (int j = 0; j < 256; j++) {
        //ground latchPin and hold low for as long as you are transmitting
        digitalWrite(latchPin, LOW);
        // push the firstbyte into chip 1
        shiftOut(dataPin, clockPin, MSBFIRST, i);
        // push the second byte into chip 1, which pushes the first byte into chip 2
        shiftOut(dataPin, clockPin, MSBFIRST, j);
        //return the latch pin high to signal chip that it
        //no longer needs to listen for information
        digitalWrite(latchPin, HIGH);
        
        delayMicroseconds(tDelay);
      }
  }
  // wait a few of seconds to show process has completed, then repeat
  delay(5000);
}
