#include "effectManager/effectManager.h"
#include "init.h"
#include "effects/solid/SolidEffect.h"
#include "effects/rainbowChase/RainbowChaseEffect.h"
#include "effects/panelTest/panelTest.h"

// Number of LEDs
#define LED_COUNT 60

// Pin definitions
#define LED_PIN 12
#define BTN_A_PIN 8
#define BTN_B_PIN 9

// Framerate management
#define FRAME_RATE 60
constexpr unsigned long targetFrameTime = 1000 / FRAME_RATE;

// Global class definitions
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
ButtonManager buttonManager;
EffectManager effectManager;

// Function that runs once to set up all components
void setup() {
  // Init Neopixel LEDs
  strip.begin();
  strip.setBrightness(255);
  strip.show();

  // Init buttons
  buttonManager.addButton(BTN_A_PIN);
  buttonManager.addButton(BTN_B_PIN);

  // Initialize effects
  initEffects(&effectManager);
}

// Function that runs repeatedly to update the LED strip
void loop() {
  // Capture time in milliseconds at which this frame starts
  const unsigned long startTime = millis();

  // Update the ButtonManager to keep track of button states
  buttonManager.update();

  // Run the active effect via EffectManager and check for effect cycling
  effectManager.run(strip, &buttonManager);

  // Calculate elapsed time and delay to maintain target frame rate
  const unsigned long elapsedTime = millis() - startTime;
  if (elapsedTime < targetFrameTime) delay(targetFrameTime - elapsedTime);
}
