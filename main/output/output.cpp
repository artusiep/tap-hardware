#include "output.h"

void Output::updateTime() {
    this->currentMillis = millis();
}

void Output::makeStep() {
    this->state++;
}

void Output::reset() {
    this->state = 0;
}