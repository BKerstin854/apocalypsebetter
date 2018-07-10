#include <SevSeg.h>
SevSeg sevseg;

int randNumber = 0;
int displayNum = 0;
int start = 0;
void setup() {
  
// Set Pin Modes



//Start Serial Communication
Serial.begin(9600);

// Timer Display Setup
    byte numDigits = 4;
    byte digitPins[] = {10, 11, 12, 13};
    byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
    bool resistorsOnSegments = true;
    bool updateWithDelaysIn = true;
    byte hardwareConfig = COMMON_ANODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.refreshDisplay();

    start = digitalRead(14);
    while (start == 0) {
      start = digitalRead(14);
      
      
      }
delay(500);
}

void loop() {
  

  randNumber = random(1000, 9999);
  sevseg.setNumber(randNumber);
  sevseg.refreshDisplay();
  Serial.println(randNumber);

}
