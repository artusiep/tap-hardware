#ifndef VIBRATOR_H
#define VIBRATOR_H

#include "output.h"
#define verbosVibrator false

#define VIBPIN 12


class Vibrator : public Output {
public:
    void setOutputDefinition(char definition[]);

    void start();

    void executeStep();

    void turnOn();

    void turnOff();
};


#endif