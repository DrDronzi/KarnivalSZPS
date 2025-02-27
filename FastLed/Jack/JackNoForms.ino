#include <FastLED.h>

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

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB leds_strip1[NUM_LEDS_STRIP1];
CRGB leds_strip2[NUM_LEDS_STRIP2];
CRGB leds_strip3[NUM_LEDS_STRIP3];
CRGB leds_strip4[NUM_LEDS_STRIP4];
CRGB leds_strip5[NUM_LEDS_STRIP5];

void setup() {
  // Initialize each strip on its designated pin
  FastLED.addLeds<LED_TYPE, PIN_STRIP1, COLOR_ORDER>(leds_strip1, NUM_LEDS_STRIP1);
  FastLED.addLeds<LED_TYPE, PIN_STRIP2, COLOR_ORDER>(leds_strip2, NUM_LEDS_STRIP2);
  FastLED.addLeds<LED_TYPE, PIN_STRIP3, COLOR_ORDER>(leds_strip3, NUM_LEDS_STRIP3);
  FastLED.addLeds<LED_TYPE, PIN_STRIP4, COLOR_ORDER>(leds_strip4, NUM_LEDS_STRIP4);
  FastLED.addLeds<LED_TYPE, PIN_STRIP5, COLOR_ORDER>(leds_strip5, NUM_LEDS_STRIP5);
  
  // Set static colors for each strip:
  // Strip 1: White
  fill_solid(leds_strip1, NUM_LEDS_STRIP1, CRGB(255, 255, 255));
  // Strip 2: White
  fill_solid(leds_strip2, NUM_LEDS_STRIP2, CRGB(255, 255, 255));
  // Strip 3: Warm White (slightly yellowish)
  fill_solid(leds_strip3, NUM_LEDS_STRIP3, CRGB(255, 223, 150));
  // Strip 4: White
  fill_solid(leds_strip4, NUM_LEDS_STRIP4, CRGB(255, 255, 255));
  // Strip 5: White
  fill_solid(leds_strip5, NUM_LEDS_STRIP5, CRGB(255, 255, 255));
  
  FastLED.show();
}

void loop() {
  // No dynamic effects; the strips remain static.
}