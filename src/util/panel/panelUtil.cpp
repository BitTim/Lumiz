//
// Created by tim on 07.12.25.
//

#include "panelUtil.h"

#include "Adafruit_NeoPixel.h"
#include "util/pixel/PixelUtil.h"

void PanelUtil::setPanelColor(Adafruit_NeoPixel& stripe, const int n, const uint8_t r, const uint8_t g, const uint8_t b) {
    for (int i = 0; i < NUM_LEDS_PER_PANEL; i++) {
        stripe.setPixelColor(PANELS[n][i], Adafruit_NeoPixel::Color(r, g, b));
    }
}

void PanelUtil::setPanelColor(Adafruit_NeoPixel& stripe, const int n, const uint32_t color) {
    for (int i = 0; i < NUM_LEDS_PER_PANEL; i++) {
        stripe.setPixelColor(PANELS[n][i], color);
    }
}

void PanelUtil::setPanelColorWithBrightness(Adafruit_NeoPixel &stripe, const int n, const uint8_t r, const uint8_t g, const uint8_t b, const double brightness) {
    for (int i = 0; i < NUM_LEDS_PER_PANEL; i++) {
        PixelUtil::setPixelColorWithBrightness(stripe, PANELS[n][i], r, g, b, brightness);
    }
}

void PanelUtil::setPanelColorWithBrightness(Adafruit_NeoPixel& stripe, const int n, const uint32_t color, const double brightness) {
    for (int i = 0; i < NUM_LEDS_PER_PANEL; i++) {
        PixelUtil::setPixelColorWithBrightness(stripe, PANELS[n][i], color, brightness);
    }
}