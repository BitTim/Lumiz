//
// Created by tim on 07.12.25.
//

#include "PixelUtil.h"

void PixelUtil::setPixelColorWithBrightness(Adafruit_NeoPixel& strip, const int n, const uint8_t r, const uint8_t g, const uint8_t b, const double brightness) {
    strip.setPixelColor(n, strip.Color(r * brightness, g * brightness, b * brightness));
}

void PixelUtil::setPixelColorWithBrightness(Adafruit_NeoPixel& strip, const int n, const uint32_t color, const double brightness) {
    setPixelColorWithBrightness(strip, n, color >> 16, color >> 8, color >> 0, brightness);
}

void PixelUtil::fillWithBrightness(Adafruit_NeoPixel& strip, const uint8_t r, const uint8_t g, const uint8_t b, const double brightness) {
    strip.fill(strip.Color(r * brightness, g * brightness, b * brightness));
}

void PixelUtil::fillWithBrightness(Adafruit_NeoPixel& strip, const uint32_t color, const double brightness) {
    fillWithBrightness(strip, color >> 16, color >> 8, color >> 0, brightness);
}