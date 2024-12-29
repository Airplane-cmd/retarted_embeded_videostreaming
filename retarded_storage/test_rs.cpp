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
  if (Serial.available()) {
    Serial.println("Data received!");
  }
}