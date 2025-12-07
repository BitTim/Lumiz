//
// Created by tim on 06.12.25.
//

#ifndef LUMIZ_EFFECT_H
#define LUMIZ_EFFECT_H

#include <Adafruit_NeoPixel.h>

#include "buttonManager/buttonManager.h"

// Base class for all effects
class Effect {
public:
    virtual ~Effect() = default;

    // Method to encapsulate effect execution and frame management
    void run(Adafruit_NeoPixel& strip, const ButtonManager* buttonManager) {
        const auto currentFrame = static_cast<uint16_t>(floor(frameCounter++ * speed));

        // Check if buttons are pressed and change speed accordingly
        if (buttonManager->isPressed(0)) increaseSpeed();
        if (buttonManager->isPressed(1)) decreaseSpeed();

        // Execute frame calculation
        frame(strip, currentFrame);
        strip.show();
    }

protected:
    // Method to handle frame rendering for the effect
    virtual void frame(Adafruit_NeoPixel& strip, uint16_t currentFrame) = 0;

    // Helper method to reset the frame counter
    void resetFrameCounter() { frameCounter = 0; }

private:
    double speed = 1.0;
    uint16_t frameCounter = 0;

    // Helper functions to increase or decrease speed
    void increaseSpeed() { speed += 0.1; }
    void decreaseSpeed() { speed -= 0.1; }
};

#endif //LUMIZ_EFFECT_H