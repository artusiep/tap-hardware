#ifndef VIBRATOR_H
#define VIBRATOR_H

#include "Output.h"

#define DIODEPIN 12


class VIBRATOR : public Output {
public:
    void virtual setOutputDefinition(char definition[]) {}

    void virtual executeDefinition() {
        pinMode(VIBPIN, OUTPUT);
    }
};


#endif