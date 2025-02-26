#include <Adafruit_NeoPixel.h>

#define NUM_LEDS_PER_CHASE_STRIP 20
#define NUM_CHASE_STRIPS 6
#define NUM_LEDS_PER_STATIC_STRIP 80
#define NUM_STATIC_STRIPS 2

const int chaseStripPins[NUM_CHASE_STRIPS] = {2, 3, 4, 5, 6, 7};
const int staticStripPins[NUM_STATIC_STRIPS] = {8, 9};

Adafruit_NeoPixel chaseStrips[NUM_CHASE_STRIPS] = {
    Adafruit_NeoPixel(NUM_LEDS_PER_CHASE_STRIP, chaseStripPins[0], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_CHASE_STRIP, chaseStripPins[1], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_CHASE_STRIP, chaseStripPins[2], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_CHASE_STRIP, chaseStripPins[3], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_CHASE_STRIP, chaseStripPins[4], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_CHASE_STRIP, chaseStripPins[5], NEO_GRB + NEO_KHZ800)
};

Adafruit_NeoPixel staticStrips[NUM_STATIC_STRIPS] = {
    Adafruit_NeoPixel(NUM_LEDS_PER_STATIC_STRIP, staticStripPins[0], NEO_GRB + NEO_KHZ800),
    Adafruit_NeoPixel(NUM_LEDS_PER_STATIC_STRIP, staticStripPins[1], NEO_GRB + NEO_KHZ800)
};

void setup() {
    for (int i = 0; i < NUM_CHASE_STRIPS; i++) {
        chaseStrips[i].begin();
        chaseStrips[i].show();
    }
    
    for (int i = 0; i < NUM_STATIC_STRIPS; i++) {
        staticStrips[i].begin();
        staticStrips[i].fill(staticStrips[i].Color(255, 30, 5));
        staticStrips[i].show();
    }
}

void loop() {
    for (int s = 0; s < NUM_CHASE_STRIPS; s++) {
        chaseStrips[s].fill(chaseStrips[s].Color(235, 255, 255));
        chaseStrips[s].show();
        delay(200);
        chaseStrips[s].clear();
        chaseStrips[s].show();
    }
}
