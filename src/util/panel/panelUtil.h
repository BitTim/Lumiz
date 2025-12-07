//
// Created by tim on 07.12.25.
//

#ifndef LUMIZ_PANELUTIL_H
#define LUMIZ_PANELUTIL_H
#include <stdint.h>

#include "Adafruit_NeoPixel.h"

#define NUM_PANELS 10
#define NUM_LEDS_PER_PANEL 6

const int PANELS[NUM_PANELS][NUM_LEDS_PER_PANEL] = {
    { 0,  1,  2,  3, 58, 59},
    { 4,  5, 54, 55, 56, 57},
    { 6,  7,  8,  9, 52, 53},
    {10, 11, 12, 13, 50, 51},
    {14, 15, 46, 47, 48, 49},
    {16, 17, 18, 19, 44, 45},
    {20, 21, 40, 41, 42, 43},
    {22, 23, 36, 37, 38, 39},
    {24, 25, 26, 27, 34, 35},
    {28, 29, 30, 31, 32, 33}
};

class PanelUtil {
public:
    static void setPanelColor(Adafruit_NeoPixel& stripe, int n, uint8_t r, uint8_t g, uint8_t b);
    static void setPanelColor(Adafruit_NeoPixel& stripe, int n, uint32_t color);
    static void setPanelColorWithBrightness(Adafruit_NeoPixel& stripe, int n, uint8_t r, uint8_t g, uint8_t b, double brightness);
    static void setPanelColorWithBrightness(Adafruit_NeoPixel& stripe, int n, uint32_t color, double brightness);
};

#endif //LUMIZ_PANELUTIL_H