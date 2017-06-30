#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 12 //arduino pin number
#define PIXELNUM 1 //number of pixels in strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXELNUM, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  rainbow(20); // calls the rainbow function for a given number of seconds
  blinkLED(3); // blinks the LED for number of given times
}

void rainbow(uint8_t wait) { //flashes through a cycle of rainbow colors
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void blinkLED(int val) { //blinks the LED
for (int x = 0; x <= val; x++) {
    strip.setPixelColor(0,239, 26, 179); // change the last 3 hex values to change the blinking color
    strip.show();
    delay(500);
    strip.setPixelColor(0,0,0,0);
    strip.show();
    delay(700);
  }
}

//IGNORE FUNCTION BELOW!!!

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

