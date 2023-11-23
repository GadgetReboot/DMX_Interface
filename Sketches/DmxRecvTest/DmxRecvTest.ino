// DMX Receiver Test
//
// Library used: DmxSerial https://github.com/mathertel/DmxSerial
// Hardware:  Arduino Nano
//
// Receives DMX data and pwm-controls a 4 pin RGB common Anode LED
// DMX address 9  controls Red
// DMX address 10 controls Green
// DMX address 11 controls Blue
// DMX address 12 controls White (sets red, green, and blue with the same data to get white)
//
// The data input pin is the serial UART Rx pin (D1) so connect the TTL data to this pin
// Be sure to disconnect the DMX data from the UART Rx pin when programming or it will
// prevent programming


#include <DMXSerial.h>

// common anode RGB led pins for pwm brightness control
const int RedPin =    9;
const int GreenPin =  6;
const int BluePin =   5;

// 255 = off for common anode
#define RedDefaultLevel   255
#define GreenDefaultLevel 255
#define BlueDefaultLevel  255

void setup () {
  DMXSerial.init(DMXReceiver);

  // set default LED rgb levels 
  analogWrite(RedPin,   RedDefaultLevel);
  analogWrite(GreenPin, GreenDefaultLevel);
  analogWrite(BluePin,  BlueDefaultLevel);

  pinMode(RedPin,   OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin,  OUTPUT);
}


void loop() {

  // if DMX data has been received for channel 9 through 12, control the LED
  // the pwm value used is 255 minus received data value because for common anode, 
  // the LED is on when the control data is 0 and off when data is 255.
  if (DMXSerial.read(12) > 0) {
    // treat the RGB LED as a white LED if the white level is > 0 (set RGB channels to the same brightness to get white)
    analogWrite(RedPin,   255 - DMXSerial.read(12));
    analogWrite(GreenPin, 255 - DMXSerial.read(12));
    analogWrite(BluePin,  255 - DMXSerial.read(12));
  }
  else {
    // read recent RGB DMX values and set pwm levels
    analogWrite(RedPin,   255 - DMXSerial.read(9));
    analogWrite(GreenPin, 255 - DMXSerial.read(10));
    analogWrite(BluePin,  255 - DMXSerial.read(11));
  }
}
