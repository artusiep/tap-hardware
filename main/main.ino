#define verbose true

#include <SoftwareSerial.h>
#include "output\diode.cpp"
#include "output\buzzer.cpp"
#include "output\vibrator.cpp"

#define rxPin 8
#define txPin 7
SoftwareSerial bleSerial = SoftwareSerial(rxPin, txPin);


#include "input\button.cpp"

#define interruptPin 2
#define connectionPin 10


String data = "";
Diode diode;
Vibrator vibrator;
Button button;
Buzzer buzzer;

void setup() {
    pinMode(connectionPin, OUTPUT);
    pinMode(DIODEPIN, OUTPUT);
    pinMode(VIBPIN, OUTPUT);
    pinMode(BUZZERPIN, OUTPUT);
    pinMode(interruptPin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interruptPin), click, RISING);
    bleSerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
    if (bleSerial.available()) {
        data = bleRecieveData();
        if (data == "1" and diode.state == 0) {
            if (verbose) { Serial.print("Pinging\n"); }
            outputsStart();
        }
    }
    outputsSteps();
    button.handle();
}

char bleRecieveData() {
    char data = bleSerial.read();
    if (verbose) {
        Serial.print(data);
        Serial.print("\n");
    }
    if (data == 'N') {
        digitalWrite(connectionPin, HIGH);
    } else if (data == 'L') {
        digitalWrite(connectionPin, LOW);
    }
    return data;
}

void click() {
    button.click();
}

void outputsStart() {
    diode.start();
    vibrator.start();
    buzzer.start();
}

void outputsSteps() {
    buzzer.executeStep();
    diode.executeStep();
    vibrator.executeStep();
}