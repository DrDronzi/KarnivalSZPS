#include <Adafruit_NeoPixel.h>

#define NUM_LEDS_STRIP1 60
#define NUM_LEDS_STRIP2 60
#define NUM_LEDS_STRIP3 100

#define PIN_STRIP1 2
#define PIN_STRIP2 3
#define PIN_STRIP3 4

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS_STRIP1, PIN_STRIP1, NEO_RGB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS_STRIP2, PIN_STRIP2, GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(NUM_LEDS_STRIP3, PIN_STRIP3, NEO_BGR + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip2.begin();
  strip3.begin();
  
  strip1.show();
  strip2.show();
  strip3.show();
  
  setStaticColour(strip1, strip1.Color(220, 19, 223));
  setStaticColour(strip2, strip2.Color(19, 220, 223));
  setStaticColour(strip3, strip3.Color(139, 250, 255));
}

void loop() {
  // No dynamic effects, all strips are static
}

void setStaticColour(Adafruit_NeoPixel& strip, uint32_t color) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);  
  }
  strip.show();
}
