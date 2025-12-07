//
// Created by tim on 06.12.25.
//

#ifndef LUMIZ_BUTTONMANAGER_H
#define LUMIZ_BUTTONMANAGER_H

#define LONG_PRESS_MS 500

// All possible button states
enum ButtonState { RELEASED, JUST_PRESSED, PRESSED, LONG_PRESSED };

// Simple struct to represent a registered button
struct Button {
    int pin;
    ButtonState state;
    unsigned long pressTime;
};

// Class to manage button states and interactions
class ButtonManager {
public:
    // Helper function to manage button registration
    int addButton(int pin);

    // Helper function to update button states
    void update() const;

    // Helper function to check button states
    bool isPressed(int buttonId) const;
    bool isLongPressed(int buttonId) const;

private:
    Button* buttons = nullptr;
    int buttonCount = 0;

    // Helper function to update button states according to their current state
    void updateStateFromReleased(int buttonId, bool pressed) const;
    void updateStateFromJustPressed(int buttonId, bool pressed) const;
    void updateStateFromPressed(int buttonId, bool pressed) const;
};

#endif //LUMIZ_BUTTONMANAGER_H