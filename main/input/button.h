//
// Created by ezsiear on 2018-03-10.
//

#ifndef TAP_HARDWARE_BUTTON_H
#define TAP_HARDWARE_BUTTON_H
#include "Arduino.h"


#define interruptPin 2

class Button {
private:
    int pin = interruptPin;
public:
    int state = 0;
    unsigned long previousMillis = 0;
    unsigned long currentMillis = 0;
    unsigned long timeToElapse = 2000;
    int getState() {
        return state;
    }

    void setState(int state) {
        this->state = state;
    }

    void click();

    void handle();

    void updateTime();
};

#endif //TAP_HARDWARE_BUTTON_H
