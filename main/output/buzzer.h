#ifndef BUZZER_H
#define BUZZER_H

#include "output.h"

#define verboseBuzzer false

#define BUZZERPIN 11

class Buzzer : public Output {
public:
    void setOutputDefinition(char definition[]);

    void start();

    void executeStep();

    void turnOn();

    void turnOff();
};

#endif