#include <Adafruit_NeoPixel.h>

// Define the pin connected to the LED matrix and the number of LEDs
#define LED_PIN 12
#define NUM_LEDS 512 // Two 16x16 displays = 256 LEDs each

// Create an instance of the NeoPixel library
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
uint32_t wheel(byte wheelPos);
void rainbowCycle(int wait);
void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  rainbowCycle(20); // Run a rainbow animation
}

// Fill the LEDs with a rainbow pattern
void rainbowCycle(int wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) { // Each iteration is one color frame
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, wheel((i * 256 / strip.numPixels() + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Generate colors across a rainbow (helper function)
uint32_t wheel(byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if (wheelPos < 85) {
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  } else if (wheelPos < 170) {
    wheelPos -= 85;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  } else {
    wheelPos -= 170;
    return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
  }
}
