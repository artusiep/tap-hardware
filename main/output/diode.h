#ifndef DIODE_H
#define DIODE_H

#include "output.cpp"

#define verboseDiode false

#define DIODEPIN 13

class Diode : public Output {
public:
    void setOutputDefinition(char definition[]);

    void start();

    void executeStep();

    void turnOn();

    void turnOff();
};

#endif