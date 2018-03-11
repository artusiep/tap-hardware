#include "button.h"
#include "Arduino.h"


Button::Button() {
    pinMode(pin, INPUT);
}

void Button::click() {
    switch (this->state) {
        case 0:
            this->state++;
            this->previousMillis = this->currentMillis;
            break;
        case 1:
            this->state++;
            break;
    }
}

void Button::handle() {
    this->updateTime();
    if (this->state == 1 and (this->currentMillis - this->previousMillis >= this->timeToElapse)) {
        Serial.print("One click\n");
        bleSerial.print("1");
        this->state = 0;
    } else if (this->state == 2) {
        Serial.print("Two clicks\n");
        bleSerial.print("2");
        this->state = 0;
    }
}

void Button::updateTime() {
    this->currentMillis = millis();
}