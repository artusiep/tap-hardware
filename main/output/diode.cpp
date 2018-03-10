#include "diode.h"
void Diode::setOutputDefinition(char definition[]) {}

void Diode::start() {
    this->updateTime();
    this->previousMillis = this->currentMillis;
    if (verbose) {
        Serial.print("Start Diode\n");
    }
    this->state = 1;
}

void Diode::executeStep() {
    this->updateTime();
    if(verboseDiode){
        Serial.print("\nCurrent: ");
        Serial.print(this->currentMillis);
        Serial.print("\nPrevious: ");
        Serial.print(this->previousMillis);
    }
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

void Diode::turnOn() {
    digitalWrite(DIODEPIN, HIGH);
}

void Diode::turnOff() {
    digitalWrite(DIODEPIN, LOW);
}