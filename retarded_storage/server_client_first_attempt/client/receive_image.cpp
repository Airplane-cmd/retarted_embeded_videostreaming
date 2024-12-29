#include <Adafruit_NeoPixel.h>

// Define the pin connected to the LED matrix and the number of LEDs
#define LED_PIN 12
#define NUM_LEDS 512 // Two 16x16 displays = 256 LEDs each

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200); // Match this with the Python script's baud rate
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.println("Ready to receive image data...");
}

void loop() {
  // Check if enough data is available for all LEDs (NUM_LEDS * 3 bytes for RGB)
  if (Serial.available() >= NUM_LEDS * 3) {
    Serial.println("Receiving image data...");
    for (int i = 0; i < NUM_LEDS; i++) {
      // Read RGB values from serial
      uint8_t r = Serial.read();
      uint8_t g = Serial.read();
      uint8_t b = Serial.read();

      // Set the LED color
      strip.setPixelColor(i, strip.Color(r, g, b));
    }
    // Show the received image
    strip.show();
    Serial.println("Image displayed.");
  }
}
