/*
   Library used:  DMX Simple https://code.google.com/archive/p/tinkerit/wikis/DmxSimple.wiki
   Hardware:      Arduino Uno

   Demo program to control 3 DMX light fixtures by individually fading red up and down on fixture 1,
   then green, blue, and white, and repeating on the next 2 fixtures before starting over.

   The fixture base addresses are 1, 5, and 9
   Each fixture has 4 channels to control R, G, B, and W
   Eg. Ch 1 = Fixture 1  Red
       Ch 2 = Fixture 1  Green
       Ch 3 = Fixture 1  Blue
       Ch 4 = Fixture 1  White
*/

#include <DmxSimple.h>

void setup() {

  /* DMX devices typically need to receive a complete set of channels
  ** even if you only need to adjust the first channel. You can
  ** easily change the number of channels sent here. If you don't
  ** do this, DmxSimple will set the maximum channel number to the
  ** highest channel you DmxSimple.write() to. */
  //DmxSimple.maxChannel(15);
  DmxSimple.usePin(3);  // DMX data output pin
}

void loop() {
  int brightness;

  // RGBW Light Fixture 1

  for (brightness = 0; brightness <= 255; brightness++) {  // fade up the brightness for fixture 1  Red (ch1)
    DmxSimple.write(1, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {  // fade down the brightness for fixture 1  Red
    DmxSimple.write(1, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {  // fade up the brightness for fixture 1  Green (ch2)
    DmxSimple.write(2, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {  // fade down the brightness for fixture 1  Green
    DmxSimple.write(2, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {  // blue
    DmxSimple.write(3, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(3, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {  // white
    DmxSimple.write(4, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(4, brightness);
    delay(5);
  }


  // RGBW Light Fixture 2

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(5, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(5, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(6, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(6, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(7, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(7, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(8, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(8, brightness);
    delay(5);
  }

  // RGBW Light Fixture 3

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(9, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(9, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(10, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(10, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(11, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(11, brightness);
    delay(5);
  }

  for (brightness = 0; brightness <= 255; brightness++) {
    DmxSimple.write(12, brightness);
    delay(5);
  }
  for (brightness = 255; brightness >= 0; brightness--) {
    DmxSimple.write(12, brightness);
    delay(5);
  }

}
