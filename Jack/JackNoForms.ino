#include <Adafruit_NeoPixel.h>

#define NUM_LEDS_STRIP1 180
#define NUM_LEDS_STRIP2 180
#define NUM_LEDS_STRIP3 70
#define NUM_LEDS_STRIP4 55
#define NUM_LEDS_STRIP5 55

#define PIN_STRIP1 2
#define PIN_STRIP2 3
#define PIN_STRIP3 4
#define PIN_STRIP4 5
#define PIN_STRIP5 6

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS_STRIP1, PIN_STRIP1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS_STRIP2, PIN_STRIP2, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS_STRIP3, PIN_STRIP3, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUM_LEDS_STRIP4, PIN_STRIP4, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUM_LEDS_STRIP5, PIN_STRIP5, NEO_RGB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();
  
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
  
  setStaticColour(strip1, strip1.Color(255, 255, 255));   // White
  setStaticColour(strip2, strip2.Color(255, 255, 255));   // White
  setStaticColour(strip3, strip3.Color(255, 223, 150));   // Warm White
  setStaticColour(strip4, strip4.Color(255, 255, 255));   // White
  setStaticColour(strip5, strip5.Color(255, 255, 255));   // White
}

void loop() {

}

void setStaticColour(Adafruit_NeoPixel& strip, uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);  
  }
  strip.show();
}
