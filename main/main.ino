#define verbose true

#include <SoftwareSerial.h>
#include "output\diode.h"

#define rxPin 8
#define txPin 7

SoftwareSerial bleSerial = SoftwareSerial(rxPin, txPin);
char data = 0;
Diode diode;

void setup() {
    pinMode(DIODEPIN, OUTPUT);
    bleSerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (bleSerial.available()) {
        data = bleRecieveData();
        if (data == '1' and diode.state == 0) {
            if (verbose) { Serial.print("Pinging\n"); }
            diode.start();
        }
    }

    if (diode.state != 0) {
        diode.executeStep();
    }
}


char bleRecieveData() {
    char data = bleSerial.read();
    if (verbose) {
        Serial.print(data);
        Serial.print("\n");
    }
    return data;
}

