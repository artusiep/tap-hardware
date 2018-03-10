#ifndef BUZZER_H
#define BUZZER_H

#include "Output.h"

#define BUZZERPIN 11

class Buzzer : public Output {
public:
    void virtual setOutputDefinition(char definition[]) {}

    void virtual executeDefinition() {

    }
};


#endif