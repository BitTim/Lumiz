//
// Created by tim on 06.12.25.
//

#ifndef LUMIZ_SOLIDEFFECT_H
#define LUMIZ_SOLIDEFFECT_H
#include "effects/effect.h"

class SolidEffect final : public Effect {
public:
    uint32_t color;
    explicit SolidEffect(uint32_t color);
    void frame(Adafruit_NeoPixel &strip, uint16_t currentFrame) override;
};

#endif //LUMIZ_SOLIDEFFECT_H