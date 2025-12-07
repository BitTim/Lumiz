//
// Created by tim on 06.12.25.
//

#include "buttonManager.h"

#include <Arduino.h>
#include <stdlib.h>

// region Public

// Adds a button to the button manager
int ButtonManager::addButton(const int pin) {
    // Resize buttons array / reallocate more space for button pins and insert button pin into this array
    buttons = static_cast<Button *>(realloc(buttons, (buttonCount + 1) * sizeof(Button)));
    buttons[buttonCount].pin = pin;
    buttons[buttonCount].state = RELEASED;
    buttons[buttonCount].pressTime = 0;

    // Initialize button pin
    pinMode(pin, INPUT_PULLUP);

    // Return assigned ID for the button
    return buttonCount++;
}

// Check if the state of the button with the provided ID is PRESSED
bool ButtonManager::isPressed(const int buttonId) const {
    return buttons[buttonId].state == PRESSED;
}

// Check if the state of the button with the provided ID is LONG_PRESSED
bool ButtonManager::isLongPressed(const int buttonId) const {
    return buttons[buttonId].state == LONG_PRESSED;
}

// Updates the state of all buttons
void ButtonManager::update() const {
    for (int i = 0; i < buttonCount; i++) {
        // Read the raw button state
        const bool pressed = digitalRead(buttons[i].pin) == LOW;

        // Update button state according to the current state and current pin state
        switch (buttons[i].state) {
            case RELEASED:
                updateStateFromReleased(i, pressed);
                break;
            case JUST_PRESSED:
                updateStateFromJustPressed(i, pressed);
                break;
            case PRESSED:
            case LONG_PRESSED:
                updateStateFromPressed(i, pressed);
                break;
        }
    }
}

// endregion Public
// region Private

// Update button state from the RELEASED state
void ButtonManager::updateStateFromReleased(const int buttonId, const bool pressed) const {
    // If the button is now pressed, set the state to JUST_PRESSED and record press time
    if (pressed) {
        buttons[buttonId].state = JUST_PRESSED;
        buttons[buttonId].pressTime = millis();
    }
}

// Update button state from the JUST_PRESSED state
void ButtonManager::updateStateFromJustPressed(const int buttonId, const bool pressed) const {
    // If the button is now released, calculate the press duration based on the press time and current time
    if (!pressed) {
        const long pressDuration = millis() - buttons[buttonId].pressTime;

        // If press duration is below the long press threshold, set the state to PRESSED, set to LONG_PRESSED otherwise
        if (pressDuration < LONG_PRESS_MS) buttons[buttonId].state = PRESSED;
        else buttons[buttonId].state = LONG_PRESSED;
    }
}

// Update button state from the PRESSED or LONG_PRESSED state
void ButtonManager::updateStateFromPressed(const int buttonId, const bool pressed) const {
    // If the button is now released, set the state to RELEASED
    if (!pressed) buttons[buttonId].state = RELEASED;
}

// endregion Private