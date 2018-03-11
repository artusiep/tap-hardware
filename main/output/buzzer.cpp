#include "buzzer.h"
void Buzzer::setOutputDefinition(char definition[]) {}

void Buzzer::start() {
    this->updateTime();
    this->previousMillis = this->currentMillis;
    if (verbose) {
        Serial.print("Start Buzzer\n");
    }
    this->state = 1;
}

void Buzzer::executeStep() {
    this->updateTime();
    if (verboseBuzzer) {
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

void Buzzer::turnOn() {
    digitalWrite(BUZZERPIN, HIGH);
}

void Buzzer::turnOff() {
    digitalWrite(BUZZERPIN, LOW);
}