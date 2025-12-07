//
// Created by tim on 06.12.25.
//

#ifndef LUMIZ_RAINBOWCHASEEFFECT_H
#define LUMIZ_RAINBOWCHASEEFFECT_H
#include "effects/effect.h"

class RainbowChaseEffect final : public Effect {
public:
    int trailLength;

    explicit RainbowChaseEffect(int trailLength);
    void frame(Adafruit_NeoPixel &strip, uint16_t currentFrame) override;
};

#endif //LUMIZ_RAINBOWCHASEEFFECT_H