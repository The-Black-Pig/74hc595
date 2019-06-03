// pushData function based on code from Carlyn Maw,Tom Igoe
// Modified for multiple 74hc595 chips by Steve Clements 2019

// Use the serial interface to input any number between 1 and
// 65535 to display the binary value using a 74hc595 and sixteen LEDs

//Pin connected to ST_CP of 74HC595 (pin 12)
int latchPin = 8;
//Pin connected to SH_CP of 74HC595 (pin 11)
int clockPin = 12;
////Pin connected to DS of 74HC595 (pin 14)
int dataPin = 11;

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pushData(0, 0); // reset all LEDS to off
  Serial.begin(9600);
  Serial.println("Input a value between 0 and 65535");
  Serial.setTimeout(10);
  
}

void loop (){
  // Read serial input:
  while (Serial.available() == 0) {}
    long inputValue = Serial.parseInt();
    Serial.print("You have entered "); Serial.println(inputValue);
    Serial.print("Equivalent Binary Value is "); Serial.println(inputValue, BIN);
    
    long high_byte = inputValue/256;
    long low_byte = inputValue - (high_byte * 256);
    
    pushData(low_byte, high_byte);

  }

void pushData(byte fstByte, byte scndByte){
  
  // pull latch pin low to accept data
  digitalWrite(latchPin, LOW);
  // push the firstbyte into chip 1
  shiftOut(dataPin, clockPin, LSBFIRST, fstByte);
  // push the second byte into chip 1, which pushes the first byte into chip 2
  shiftOut(dataPin, clockPin, LSBFIRST, scndByte);
  // pull latch pin high to stop accepting data
  digitalWrite(latchPin, HIGH);
  //delay(tDelay);
  
}

