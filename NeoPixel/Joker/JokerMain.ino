#include <Adafruit_NeoPixel.h>

#define NUM_LEDS_BOX 85
#define NUM_LEDS_NECK 70
#define NUM_LEDS_POINTS 175
#define NUM_LEDS_SIDE 50
#define NUM_LEDS_MOON 65

#define PIN_STRIP1 2
#define PIN_STRIP2 3
#define PIN_STRIP3 4
#define PIN_STRIP4 5
#define PIN_STRIP5 6
#define PIN_STRIP6 7
#define PIN_STRIP7 8

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS_BOX, PIN_STRIP1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS_BOX, PIN_STRIP2, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS_POINTS, PIN_STRIP3, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(NUM_LEDS_NECK, PIN_STRIP4, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip5 = Adafruit_NeoPixel(NUM_LEDS_SIDE, PIN_STRIP5, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip6 = Adafruit_NeoPixel(NUM_LEDS_SIDE, PIN_STRIP6, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip7 = Adafruit_NeoPixel(NUM_LEDS_MOON, PIN_STRIP7, NEO_RGB + NEO_KHZ800);

void setup() {
  strip1.begin();
  delay(10);
  strip2.begin();
  delay(10);
  strip3.begin();
  delay(10);
  strip4.begin();
  delay(10);
  strip5.begin();
  delay(10);
  strip6.begin(); 
  delay(10);
  strip7.begin(); 
  
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
  strip6.show();
  strip7.show(); 
  
  setStaticColour(strip1, strip1.Color(255, 255, 255));
  setStaticColour(strip2, strip2.Color(255, 255, 255));
  setStaticColour(strip4, strip4.Color(68, 237, 7));
  setStaticColour(strip5, strip5.Color(178, 14, 196));
  setStaticColour(strip6, strip6.Color(178, 14, 196));
  setStaticColour(strip7, strip7.Color(255, 231, 10));
}

void loop() {
    chase(strip3, strip3.Color(178, 14, 196), 50, 5);
}

void setStaticColour(Adafruit_NeoPixel& strip, uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);  
  }
  strip.show();
}

void chase(Adafruit_NeoPixel& strip, uint32_t color, uint8_t wait, int interval) {
  for (int i = 0; i < strip.numPixels(); i++) {
    for (int j = 0; j < strip.numPixels(); j += interval) {
      int index = (i + j) % strip.numPixels();
      strip.setPixelColor(index, color);
    }
    strip.show();
    delay(wait);
    for (int j = 0; j < strip.numPixels(); j += interval) {
      int index = (i + j) % strip.numPixels();
      strip.setPixelColor(index, 0);
    }
  }
}
