//
// Created by tim on 06.12.25.
//

#ifndef LUMIZ_EFFECTMANAGER_H
#define LUMIZ_EFFECTMANAGER_H

#include <Adafruit_NeoPixel.h>

#include "effects/effect.h"

// Class to manage effects and their execution
class EffectManager {
public:
    // Helper method to manage effect registration
    void addEffect(Effect* effect);

    // Helper method to execute currently selected effect from registry
    void run(Adafruit_NeoPixel& strip, ButtonManager* buttonManager);

private:
    Effect** effects = nullptr;
    int effectCount = 0;
    int activeEffectIndex = 0;

    // Helper method to cycle to the next effect in the effect manager cycle
    void nextEffect();

    // Helper method to cycle to the previous effect in the effect manager cycle
    void previousEffect();
};

#endif //LUMIZ_EFFECTMANAGER_H