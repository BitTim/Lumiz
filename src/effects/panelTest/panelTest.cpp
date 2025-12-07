//
// Created by tim on 07.12.25.
//

#include "panelTest.h"

#include "util/panel/panelUtil.h"

void PanelTest::frame(Adafruit_NeoPixel &strip, const uint16_t currentFrame) {
    PanelUtil::setPanelColorWithBrightness(strip, currentFrame % NUM_PANELS, random(255), random(255), random(255), random(100) / 100.0);
}