//
// Created by tim on 06.12.25.
//

#include "SolidEffect.h"

SolidEffect::SolidEffect(const uint32_t color) {
    this->color = color;
}

void SolidEffect::frame(Adafruit_NeoPixel& strip, const uint16_t currentFrame) {
    strip.fill(color);
}
