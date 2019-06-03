# 74hc595

These demos are aimed primarily as a jumping off point for absolute beginners.

Using daisy chained 74hc595 chips with the Arduino.

What should be taken into consideration is the way data is moved between chip 1 and chip 2..... etc. Firstly you can send a data
byte in two directions Least Significant Bit (LSB) first or the Most Sgnificant Bit (MSB) first. Taking the Latch pin LOW, then
allows data to be pushed to the first chip.
The first byte is written to chip 1 and the next byte is also written to chip 1 but pushes the first byte to the next chip
and so on until all the chips have been filled. Only then, taking the Latch Pin HIGH will stop data more being accepted by the
chip and the output pins are then activated. 

WARNING: the 74hc595 cannot cope with more than about 20mA on each output pin and no more than 80mA total. Therefore
if connecting LEDs directly to chip output pins use higher value resistors than normal. I use green LEDs with 2K to 3K resistors
but any resister 10 times higher than you would normally use, should provide sufficient current reduction.

<h3>SETUP</h3>

74hc595 pin connections
<ul>
<li>Pin 1 - 2KΩ - LED 2</li>
<li>Pin 2 - 2KΩ - LED 3</li>
<li>Pin 3 - 2KΩ - LED 4</li>
<li>Pin 4 - 2KΩ - LED 5</li>
<li>Pin 5 - 2KΩ - LED 6</li>
<li>Pin 6 - 2KΩ - LED 7</li>
<li>Pin 7 - 2KΩ - LED 8</li>
<li>Pin 8 - Gnd</li>
<li>Pin 9 - Pin 14 on chip 2</li>
<li>Pin 10 - 10kΩ resister to Vcc rail</li>
<li>Pin 11 - D12 and Pin 11 on chip 2</li>
<li>Pin 12 - D8 and Pin 12 on chip 2</li>
<li>Pin 13 - 10kΩ resister to Gnd rail</li>
<li>Pin 14 - D11</li>
<li>Pin 15 - 2KΩ - LED 1</li>
<li>Pin 16 - Vcc (3 - 6V)</li>
</ul>

The wiring of the second chip is similar to the above wiring, only pin 9 is left unconnected unless you want to daisy
chain another 74hc595.

As a matter of habit, I always use 10kΩ resisters on pull-up or pull-down pins, in case I want to feed a pulse to these
pins in future projects.

<h3>Example Sketches</h3>

<i>74hc595_binary_counter.ino</i><br>
The first example counts from 0 to 65536 in binary, and takes exactly 10 minutes to complete.

<i>74hc595_random_display.ino</i><br>
The second example creates random on/off states on 16 channels.

<i>74hc595_knight_rider.ino</i><br>
<i>74hc595_knight_rider_2.ino</i><br>
And third and fourth examples are versions of the obligatory "Knight Rider" demo. A must, if you have row of LEDS set up.
The two versions of the "Knight Rider" demo use slightly different coding techniques. The first one uses an array and the second uses bit shifting.

<i>74hc595_bounce_effect.ino</i><br>
A simple bit shift sketch where the LEDs appear to bounce in the middle.

<i>74hc595_serial_input.ino</i><br>
Input an integer between 0 and 65335 and show the binary equivalent with the LEDs.

<h4>Any code improvement suggestions are very welcome!</h4>
