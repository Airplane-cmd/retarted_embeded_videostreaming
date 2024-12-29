#include <Adafruit_NeoPixel.h>

// Number of LEDs in your display
#define NUM_LEDS 512 // Two 16x16 displays = 256 LEDs each

// Define an array of pins to test
int testPins[] = {4, 5, 12, 13, 14, 15, 16}; // Add more pins if needed
int numPins = sizeof(testPins) / sizeof(testPins[0]);

Adafruit_NeoPixel strip(NUM_LEDS, 0, NEO_GRB + NEO_KHZ800); // Default pin, will change dynamically

void setup() {
  Serial.begin(115200);
  Serial.println("Starting pin search...");

  for (int i = 0; i < numPins; i++) {
    int pin = testPins[i];
    Serial.print("Testing pin: ");
    Serial.println(pin);

    // Set the current pin
    strip.setPin(pin);
    strip.begin();
    strip.show(); // Clear LEDs

    // Light up the first LED as a test
    strip.setPixelColor(0, strip.Color(255, 0, 0)); // Red
    strip.show();
    delay(2000); // Wait for 2 seconds to observe the LED

    // Clear LED before moving to the next pin
    strip.clear();
    strip.show();
  }

  Serial.println("Pin search complete. Check which pin lit up the LEDs.");
}

void loop() {
  // Nothing here; search happens in setup
}
