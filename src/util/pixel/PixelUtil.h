//
// Created by tim on 07.12.25.
//

#ifndef LUMIZ_PIXELUTIL_H
#define LUMIZ_PIXELUTIL_H
#include "Adafruit_NeoPixel.h"

class PixelUtil {
public:
    static void setPixelColorWithBrightness(Adafruit_NeoPixel &strip, int n, uint8_t r, uint8_t g, uint8_t b, double brightness);
    static void setPixelColorWithBrightness(Adafruit_NeoPixel &strip, int n, uint32_t color, double brightness);
    static void fillWithBrightness(Adafruit_NeoPixel &strip, uint8_t r, uint8_t g, uint8_t b, double brightness);
    static void fillWithBrightness(Adafruit_NeoPixel &strip, uint32_t color, double brightness);
};

#endif //LUMIZ_PIXELUTIL_H