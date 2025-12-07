//
// Created by tim on 07.12.25.
//

#ifndef LUMIZ_PANELTEST_H
#define LUMIZ_PANELTEST_H
#include "../effect.h"

class PanelTest final : public Effect {
protected:
    void frame(Adafruit_NeoPixel &strip, uint16_t currentFrame) override;
};

#endif //LUMIZ_PANELTEST_H