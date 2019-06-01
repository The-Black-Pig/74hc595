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
but 10 times higher than you would for the rating of different LED colours i.e. Vcc - forward voltage.

<b>SETUP</b>

74hc595 pin connections
<ul>
<li>Pin 1 - LED 2</li>
<li>Pin 2 - LED 3</li>
<li>Pin 3 - LED 4</li>
<li>Pin 4 - LED 5</li>
<li>Pin 5 - LED 6</li>
<li>Pin 6 - LED 7</li>
<li>Pin 7 - LED 8</li>
<li>Pin 8 - Gnd</li>
<li>Pin 9 - Pin 14 on chip 2</li>
<li>Pin 10 - 10kΩ resister to Vcc rail</li>
<li>Pin 11 - D12 and Pin 11 on chip 2</li>
<li>Pin 12 - 10kΩ resister to Gnd rail</li>
<li>Pin 13 - D8 and Pin 13 on chip 2</li>
<li>Pin 14 - D11</li>
<li>Pin 15 - LED 1</li>
<li>Pin 16 - Vcc (3 - 6V)</li>
</ul>

The wiring of the second chip is similar to the above wiring, only pin 9 is left unconnected unless you want to daisy
chain another 74hc595.

As a matter of habit, I always use 10kΩ resisters on pull-up or pull-down pins, in case I want to feed a pulse to these
pins in future projects.
