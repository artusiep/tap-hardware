#ifndef OUTPUT_H
#define OUTPUT_H

#include "Arduino.h"


class Output {
private:
    char definition[20];
public:
    int state = 0;
    unsigned long previousMillis = 0;
    unsigned long currentMillis = 0;

    void virtual setOutputDefinition(char definition[]);

    void virtual start();

    void virtual executeStep();

    void updateTime(); 

    void makeStep();

    void reset();
};

#endif