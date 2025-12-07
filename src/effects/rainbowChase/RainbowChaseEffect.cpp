//
// Created by tim on 06.12.25.
//

#include "RainbowChaseEffect.h"

#include "util/pixel/PixelUtil.h"
#define NUM_CYCLES 3

RainbowChaseEffect::RainbowChaseEffect(const int trailLength) {
    this->trailLength = trailLength;
}

void RainbowChaseEffect::frame(Adafruit_NeoPixel& strip, const uint16_t currentFrame) {
    const uint16_t ledCount = strip.numPixels();
    const float trailFactor = 1.0 / trailLength;

    const long offset = 65535 / (NUM_CYCLES * ledCount);
    const long hue = offset * currentFrame % 65535;
    const uint32_t color = Adafruit_NeoPixel::gamma32(Adafruit_NeoPixel::ColorHSV(hue, 255, 255));

    for (uint16_t led = 0; led < ledCount; led++) {
        const long trail = (currentFrame - led + ledCount) % ledCount;
        const float alpha = trail > trailLength ? 0.0 : 1 - trailFactor * trail;

        PixelUtil::setPixelColorWithBrightness(strip, led, color, alpha);
    }

    if (currentFrame >= NUM_CYCLES * ledCount) resetFrameCounter();
}
