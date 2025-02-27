#include <FastLED.h>

const int mainArray = 42;
int pins[mainArray];
bool litLEDs[mainArray]; 

int delayTime = 500;
const int minDelayTime = 50;

// FastLED configuration for the additional LED strip:
#define LED_STRIP_NUM_LEDS 100
#define LED_STRIP_PIN 43
#define LED_TYPE WS2811
#define COLOR_ORDER GRB

CRGB ledStrip[LED_STRIP_NUM_LEDS];

void setup()
{
  // Initialize the digital pins for your existing LED system
  for (int i = 0; i < mainArray; i++) {
    pins[i] = i;
    pinMode(pins[i], OUTPUT);
    litLEDs[i] = false; 
  }
  randomSeed(analogRead(A0));
  
  // Initialize FastLED for the additional LED strip
  FastLED.addLeds<LED_TYPE, LED_STRIP_PIN, COLOR_ORDER>(ledStrip, LED_STRIP_NUM_LEDS);
  // Set the entire LED strip to white
  fill_solid(ledStrip, LED_STRIP_NUM_LEDS, CRGB::White);
  FastLED.show();
}

void loop()
{
  randomLeds();
  oddEvenLeds();
  trailLeds();
  chasingLeds();
}

void randomLeds() {
  int litCount = 0;

  while (litCount < mainArray) {
    int currentLED;
    do {
      currentLED = random(0, mainArray);
    } while (litLEDs[currentLED]);

    digitalWrite(pins[currentLED], HIGH);
    litLEDs[currentLED] = true;
    litCount++;

    delay(delayTime);
    delayTime = max(delayTime - 10, minDelayTime);
  }

  delay(1000);
  for (int i = 0; i < mainArray; i++) {
    digitalWrite(pins[i], LOW);
    litLEDs[i] = false;
  }
  delayTime = 500;
}

void trailLeds() {
  for (int z = 0; z < 2; z++) {
    int arraySize = mainArray;
    int temp = (arraySize - 1); 
    for (int i = 0; i < arraySize; i++) {
      for (int j = 0; j <= temp; j++) {
        digitalWrite(pins[j], HIGH);
        delay(30);
        digitalWrite(pins[j], LOW);
        if (j == temp) {
          digitalWrite(pins[temp], HIGH);
          temp = temp - 1;
        }
        if (temp == 0) {
          for (int y = 0; y < 2; y++) {
            for (int x = 0; x < arraySize; x++) {
              digitalWrite(pins[x], LOW);
            }
            delay(300);
            for (int x = 0; x < arraySize; x++) {
              digitalWrite(pins[x], HIGH);
            }
            delay(300);
          }
        }
      }
      delay(100);
    }
  }
}

void oddEvenLeds() {
  for (int z = 0; z < 20; z++) {
    for (int i = 1; i < mainArray; i += 2) {
      digitalWrite(pins[i], HIGH);
    }
    delay(250);
    
    for (int i = 1; i < mainArray; i += 2) {
      digitalWrite(pins[i], LOW);
    }
    
    for (int i = 0; i < mainArray; i += 2) {
      digitalWrite(pins[i], HIGH);
    }
    delay(250);

    for (int i = 0; i < mainArray; i += 2) {
      digitalWrite(pins[i], LOW);
    }
  }
}

void chasingLeds() {
  for (int z = 0; z < 10; z++) {
    for (int i = 42; i > 28; i--) {
      digitalWrite(pins[i], HIGH);
      digitalWrite(pins[i-14], HIGH);
      digitalWrite(pins[i-28], HIGH);
      delay(60);
      digitalWrite(pins[i], LOW);
      digitalWrite(pins[i-14], LOW);
      digitalWrite(pins[i-28], LOW);
    }
  }
}