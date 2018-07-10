#include <SevSeg.h>
SevSeg sevseg;

// Set Display Pin Variables:
  //const int *** = *;

// Set Time Delay
  unsigned long timeDelay;
  unsigned long timeDelay2; 
  unsigned long timeOutput;
  unsigned long currentTime;
  unsigned long currentTime2;
  unsigned long numOutput;
  unsigned long num;
  unsigned long num2;
  unsigned int integerValue=0;  // Max value is 65535
  char incomingByte;
 
  

void setup() {
  
  // Set Pin Modes
    //pinMode(***, OUTPUT);

  // Start Serial Communication
    Serial.begin(9600);

  // Initialize Time Delay
    timeDelay2 = 5;
    num = 1000;

  // Timer Display Setup
    byte numDigits = 4;
    byte digitPins[] = {10, 11, 12, 13};
    byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
    bool resistorsOnSegments = true;
    bool updateWithDelaysIn = true;
    byte hardwareConfig = COMMON_CATHODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.refreshDisplay();
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

  

  currentTime = millis();
  currentTime2 = currentTime / num;
  timeOutput = timeDelay2 - currentTime2;
  numOutput = round(timeOutput);
  Serial.println(numOutput);

  sevseg.setNumber(numOutput);
  sevseg.refreshDisplay();

  while(numOutput <= 0 || numOutput >= 100000) {

  Serial.println(0);
  sevseg.setNumber(0);
  sevseg.refreshDisplay();
  delay(1000);


  }
  
  
  delay(1000);
     }

