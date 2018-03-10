#define verbose true

#include <SoftwareSerial.h>
#include "output\diode.cpp"
#include "output\vibrator.cpp"
#define interruptPin 2
#define rxPin 8
#define txPin 7

SoftwareSerial bleSerial = SoftwareSerial(rxPin, txPin);
String data = "";
Diode diode;
Vibrator vibrator;

void setup() {
    pinMode(DIODEPIN, OUTPUT);
    pinMode(VIBPIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), diodestart, HIGH);
    bleSerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (bleSerial.available()) {
        data = bleRecieveData();
        if (data == "1" and diode.state == 0) {
            if (verbose) { Serial.print("Pinging\n"); }
            diode.start();
            vibrator.start();
        }
    }

    executeSteps();
}

char bleRecieveData() {
    char data = bleSerial.read();
    if (verbose) {
        Serial.print(data);
        Serial.print("\n");
    }
    return data;
}

void diodestart() {
    diode.start();
}

void executeSteps() {
    diode.executeStep();
    vibrator.executeStep();
}