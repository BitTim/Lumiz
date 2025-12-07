//
// Created by tim on 07.12.25.
//

#ifndef LUMIZ_EFFECTS_H
#define LUMIZ_EFFECTS_H

#include "effects/panelTest/panelTest.h"
#include "effects/rainbowChase/RainbowChaseEffect.h"
#include "effects/solid/SolidEffect.h"

// Function to initialize all effects and add them to the effect manager
inline void initEffects(EffectManager* effectManager) {
    // region Effect Creation

    auto solidEffect = SolidEffect(Adafruit_NeoPixel::Color(255, 255, 255));
    auto rainbowChaseEffect = RainbowChaseEffect(20);
    auto panelTestEffect = PanelTest();

    // endregion Effect Instances
    // region Effect Registration

    effectManager->addEffect(&solidEffect);
    effectManager->addEffect(&rainbowChaseEffect);
    effectManager->addEffect(&panelTestEffect);

    // endregion Effect Registration
}

#endif //LUMIZ_EFFECTS_H