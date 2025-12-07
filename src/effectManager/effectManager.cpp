//
// Created by tim on 06.12.25.
//

#include "effectManager.h"

// region Public

// Adds an effect to this effect manager cycle
void EffectManager::addEffect(Effect* effect) {
    // Resize effects array / reallocate more space for effect pointers and insert effect into this array
    effects = static_cast<Effect **>(realloc(effects, (effectCount + 1) * sizeof(Effect*)));
    effects[effectCount++] = effect;
}

// Runs the active effect
void EffectManager::run(Adafruit_NeoPixel &strip, ButtonManager* buttonManager) {
    // Check if the active effect is valid
    if (effects == nullptr) return;
    if (effectCount == 0) return;
    if (activeEffectIndex > effectCount - 1) return;
    if (activeEffectIndex < 0) return;

    // Check if buttons are long pressed and cycle to the next or previous effect accordingly
    if (buttonManager->isLongPressed(0)) nextEffect();
    if (buttonManager->isLongPressed(1)) previousEffect();

    // Run the active effect
    effects[activeEffectIndex]->run(strip, buttonManager);
}

// endregion Public
// region Private

// Cycles to the next effect in the effect manager cycle
void EffectManager::nextEffect() {
    activeEffectIndex = (activeEffectIndex + 1) % effectCount;
}

// Cycles to the previous effect in the effect manager cycle
void EffectManager::previousEffect() {
    activeEffectIndex = (activeEffectIndex - 1 + effectCount) % effectCount;
}

// endregion Private
