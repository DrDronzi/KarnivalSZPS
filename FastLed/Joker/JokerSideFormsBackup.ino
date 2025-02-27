#include <FastLED.h>

#define NUM_LEDS_STRIP1 60
#define NUM_LEDS_STRIP2 60
#define NUM_LEDS_STRIP3 100

#define PIN_STRIP1 2
#define PIN_STRIP2 3
#define PIN_STRIP3 4

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds_strip1[NUM_LEDS_STRIP1];
CRGB leds_strip2[NUM_LEDS_STRIP2];
CRGB leds_strip3[NUM_LEDS_STRIP3];

void setup() {
  FastLED.addLeds<LED_TYPE, PIN_STRIP1, COLOR_ORDER>(leds_strip1, NUM_LEDS_STRIP1);
  FastLED.addLeds<LED_TYPE, PIN_STRIP2, COLOR_ORDER>(leds_strip2, NUM_LEDS_STRIP2);
  FastLED.addLeds<LED_TYPE, PIN_STRIP3, COLOR_ORDER>(leds_strip3, NUM_LEDS_STRIP3);
  
  // Set static colors on each strip:
  fill_solid(leds_strip1, NUM_LEDS_STRIP1, CRGB(220, 19, 223));
  fill_solid(leds_strip2, NUM_LEDS_STRIP2, CRGB(220, 19, 223));
  fill_solid(leds_strip3, NUM_LEDS_STRIP3, CRGB(255, 236, 66));
  
  FastLED.show();
}

void loop() {
  // No dynamic effects; all strips remain static.
}