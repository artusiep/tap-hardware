#ifndef DIODE_H
#define DIODE_H

#include "output.h"

#define DIODEPIN 13

class Diode : public Output {
public:
    void virtual setOutputDefinition(char definition[]) {}

    void virtual start() {
        this->updateTime();
        this->previousMillis = this->currentMillis;
        if (verbose) {
            Serial.print("Start Diode\n");
        }
        this->state = 1;
    }

    void virtual executeStep() {
        this->updateTime();
        Serial.print("\nCurrent: ");
        Serial.print(this->currentMillis);
        Serial.print("\nPrevious: ");
        Serial.print(this->previousMillis);
        switch (this->state) {
            case 0:
                break;
            case 1:
                this->turnOn();
                this->makeStep();
                break;
            case 2:
                if (this->currentMillis - this->previousMillis >= 3000) {
                    this->makeStep();
                }
                break;
            case 3:
                this->turnOff();
                this->reset();
                break;
        }
    }

    void turnOn() {
        digitalWrite(DIODEPIN, HIGH);
    }

    void turnOff() {
        digitalWrite(DIODEPIN, LOW);
    }
};

#endif