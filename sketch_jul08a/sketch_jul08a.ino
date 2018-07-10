#include <SevSeg.h>
SevSeg sevseg;

void setup() {
  // put your setup code here, to run once:

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

  byte numDigits = 4;
    byte digitPins[] = {12, 11, 10, 9};
    byte segmentPins[] = {8, 7, 6, 5, 4, 3, 2, 13};
    bool resistorsOnSegments = false;
    bool updateWithDelaysIn = true;
    byte hardwareConfig = COMMON_ANODE;
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.refreshDisplay();

}

void loop() {
  // put your main code here, to run repeatedly:

sevseg.setNumber(3);
sevseg.refreshDisplay();
delay(50);


}
