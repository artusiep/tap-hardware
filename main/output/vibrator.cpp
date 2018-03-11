#include "vibrator.h"
void Vibrator::setOutputDefinition(char definition[]) {}

void Vibrator::start() {
    this->updateTime();
    this->previousMillis = this->currentMillis;
    if (verbose) {
        Serial.print("Start Vibrator\n");
    }
    this->state = 1;
}

void Vibrator::executeStep() {
    this->updateTime();
    if(verbosVibrator){
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

void Vibrator::turnOn() {
    digitalWrite(VIBPIN, HIGH);
}

void Vibrator::turnOff() {
    digitalWrite(VIBPIN, LOW);
}