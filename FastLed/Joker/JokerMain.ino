#include <FastLED.h>

#define NUM_LEDS_BOX   85
#define NUM_LEDS_NECK  70
#define NUM_LEDS_POINTS 175
#define NUM_LEDS_SIDE  50
#define NUM_LEDS_MOON  65

#define PIN_STRIP1 2
#define PIN_STRIP2 3
#define PIN_STRIP3 4
#define PIN_STRIP4 5
#define PIN_STRIP5 6
#define PIN_STRIP6 7
#define PIN_STRIP7 8

#define LED_TYPE WS2811
#define COLOR_ORDER GRB

// Define LED arrays for each strip
CRGB leds_strip1[NUM_LEDS_BOX];
CRGB leds_strip2[NUM_LEDS_BOX];
CRGB leds_strip3[NUM_LEDS_POINTS];
CRGB leds_strip4[NUM_LEDS_NECK];
CRGB leds_strip5[NUM_LEDS_SIDE];
CRGB leds_strip6[NUM_LEDS_SIDE];
CRGB leds_strip7[NUM_LEDS_MOON];

void setup() {
  // Initialize each LED strip with FastLED on the designated pins
  FastLED.addLeds<LED_TYPE, PIN_STRIP1, COLOR_ORDER>(leds_strip1, NUM_LEDS_BOX);
  FastLED.addLeds<LED_TYPE, PIN_STRIP2, COLOR_ORDER>(leds_strip2, NUM_LEDS_BOX);
  FastLED.addLeds<LED_TYPE, PIN_STRIP3, COLOR_ORDER>(leds_strip3, NUM_LEDS_POINTS);
  FastLED.addLeds<LED_TYPE, PIN_STRIP4, COLOR_ORDER>(leds_strip4, NUM_LEDS_NECK);
  FastLED.addLeds<LED_TYPE, PIN_STRIP5, COLOR_ORDER>(leds_strip5, NUM_LEDS_SIDE);
  FastLED.addLeds<LED_TYPE, PIN_STRIP6, COLOR_ORDER>(leds_strip6, NUM_LEDS_SIDE);
  FastLED.addLeds<LED_TYPE, PIN_STRIP7, COLOR_ORDER>(leds_strip7, NUM_LEDS_MOON);

  // Set static colors for the specified strips:
  // Strip 1: White
  fill_solid(leds_strip1, NUM_LEDS_BOX, CRGB(255, 255, 255));
  // Strip 2: White
  fill_solid(leds_strip2, NUM_LEDS_BOX, CRGB(255, 255, 255));
  // Strip 4: Color (68, 237, 7)
  fill_solid(leds_strip4, NUM_LEDS_NECK, CRGB(68, 237, 7));
  // Strip 5: Color (178, 14, 196)
  fill_solid(leds_strip5, NUM_LEDS_SIDE, CRGB(178, 14, 196));
  // Strip 6: Color (178, 14, 196)
  fill_solid(leds_strip6, NUM_LEDS_SIDE, CRGB(178, 14, 196));
  // Strip 7: Color (255, 231, 10)
  fill_solid(leds_strip7, NUM_LEDS_MOON, CRGB(255, 231, 10));
  
  FastLED.show();
}

void loop() {
  // Run the chase animation on strip3 (the "points" strip)
  chase(leds_strip3, NUM_LEDS_POINTS, CRGB(178, 14, 196), 50, 5);
}

// A helper function to set a static color on a given LED array
void setStaticColour(CRGB *leds, int numLeds, CRGB color) {
  fill_solid(leds, numLeds, color);
  FastLED.show();
}

// The chase animation: lights up every 'interval'-th LED, shows the pattern, delays,
// then turns them off before moving to the next step.
void chase(CRGB *leds, int numLeds, CRGB color, uint8_t wait, int interval) {
  for (int i = 0; i < numLeds; i++) {
    // Light up a subset of LEDs based on the current offset
    for (int j = 0; j < numLeds; j += interval) {
      int index = (i + j) % numLeds;
      leds[index] = color;
    }
    FastLED.show();
    delay(wait);
    // Turn off the LEDs that were lit
    for (int j = 0; j < numLeds; j += interval) {
      int index = (i + j) % numLeds;
      leds[index] = CRGB::Black;
    }
  }
}