#define verbose true

#include <SoftwareSerial.h>
#include "output\diode.cpp"
#include "output\vibrator.cpp"
#include "input\button.cpp"
#define rxPin 8
#define txPin 7
#define interruptPin 2


SoftwareSerial bleSerial = SoftwareSerial(rxPin, txPin);
String data = "";
Diode diode;
Vibrator vibrator;
Button button;


void setup() {
    pinMode(DIODEPIN, OUTPUT);
    pinMode(VIBPIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING);
    bleSerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    //button.checkIfPushed();
    if (bleSerial.available()) {
        data = bleRecieveData();
        if (data == "1" and diode.state == 0) {
            if (verbose) { Serial.print("Pinging\n"); }
            diode.start();
            vibrator.start();
        }
    }
    executeSteps();
    button.handle();
}

char bleRecieveData() {
    char data = bleSerial.read();
    if (verbose) {
        Serial.print(data);
        Serial.print("\n");
    }
    return data;
}

void click() {
    button.click();
}

void executeSteps() {
    diode.executeStep();
    vibrator.executeStep();
}