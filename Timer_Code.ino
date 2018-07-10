#include <SevSeg.h>
SevSeg sevseg;



// Set Variables
  unsigned long timeDelay;
  unsigned long timeDelay2; 
  unsigned long timeOutput;
  unsigned long currentTime;
  unsigned long currentTime2;
  unsigned long numOutput;
  unsigned long numOutput2;
  unsigned long num;
  unsigned long num2;
  unsigned int integerValue=0;  // Max value is 65535
  char incomingByte;
  unsigned long startTime;

  int start = 0;
 
  

void setup() {
  
  // Set Pin Modes
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(14, OUTPUT);

  // Start Serial Communication
    Serial.begin(115200);

  // Initialize Time Delay
    timeDelay2 = 180;
    num = 1000;

  // Timer Display Setup
    byte numDigits = 4;
    byte digitPins[] = {12, 11, 10, 9};
    byte segmentPins[] = {8, 7, 6, 5, 4, 3, 2, 13};
    bool resistorsOnSegments = false;
    bool updateWithDelaysIn = true;
    byte hardwareConfig = COMMON_ANODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.refreshDisplay();
    
    while (start == 0) {

      if (Serial.available() > 0) {
        start = 1;
        digitalWrite(14, HIGH);
        }
      delay(500);
      }
      
    startTime = millis();
    
 }




void loop() {

  

     if (Serial.available() > 0) {   // something came across serial
    integerValue = 0;         // throw away previous integerValue
    while(1) {            // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
    }
    timeDelay2 = integerValue + timeDelay2;
     }

  

  currentTime = (millis()-startTime);
  currentTime2 = currentTime / num;
  timeOutput = timeDelay2 - currentTime2;
  numOutput = round(timeOutput);
  Serial.println(numOutput);
  numOutput2 = "0" && numOutput;

  sevseg.setNumber(numOutput);
  sevseg.refreshDisplay();

  //delay(1000);

  while(numOutput <= 0 || numOutput >= 100000) {

  Serial.println(0);
  sevseg.setNumber(0);
  sevseg.refreshDisplay();
  //delay(1000);
  
  }
  
  
     }

