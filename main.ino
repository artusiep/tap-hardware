#include <SoftwareSerial.h>
#define rxPin 8
#define txPin 7
#define verbose true

SoftwareSerial bleSerial =  SoftwareSerial(rxPin, txPin);
char data = 0;
void setup()
{
    bleSerial.begin(9600);
    Serial.begin(9600);                                 
    pinMode(13, OUTPUT);  
}
void loop()
{
  if(bleSerial.available()) {
    data = bleRecieveData();    
    if(data == '1')              
      digitalWrite(13, HIGH);   
    else if(data == '0')        
      digitalWrite(13, LOW);   
  }
}


char bleRecieveData() {
  char data = bleSerial.read();
  if(verbose) {
    Serial.print(data);          
    Serial.print("\n");             
  }
  return data;
}

