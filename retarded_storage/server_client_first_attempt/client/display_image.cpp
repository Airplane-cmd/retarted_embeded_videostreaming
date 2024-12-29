#include <Adafruit_NeoPixel.h>

// Define the pin connected to the LED matrix and the number of LEDs
#define LED_PIN 12
#define NUM_LEDS 512 // Two 16x16 displays = 256 LEDs each

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200); // Match with the Python script baud rate
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.println("Ready to receive image data...");
}

void loop() {
  static int currentLED = 0;

  // Continuously read incoming data
  while (Serial.available() >= 3) { // Process RGB data as it arrives
    uint8_t r = Serial.read();
    uint8_t g = Serial.read();
    uint8_t b = Serial.read();

    // Set the color of the current LED
    strip.setPixelColor(currentLED, strip.Color(r, g, b));

    currentLED++;

    // If all LEDs have been updated, show the frame and reset
    if (currentLED >= NUM_LEDS) {
      strip.show();
      currentLED = 0; // Reset to the first LED
      Serial.println("Frame displayed.");
    }
  }
}
