#include <Servo.h>




unsigned int groupNum;
unsigned int integerValue=0;  // Max value is 65535
  char incomingByte;
unsigned int anNum;

int elevenState = 0;
int twelveState = 0;
int thirteenState = 0;
int fourteenState = 0;
int fifteenState = 0;
int sixteenState = 0;
int seventeenState = 0;
int eighteenState = 0;
int nineteenState = 0;

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo5;
Servo myservo7;
Servo myservo9;



void setup() {
  // put your setup code here, to run once:


//Lights
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);


//Analog Outputs
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(14, OUTPUT);
pinMode(15, OUTPUT);
pinMode(16, OUTPUT);
pinMode(17, OUTPUT);
pinMode(18, OUTPUT);
pinMode(19, OUTPUT);

Serial.begin(9600);

digitalWrite(3, HIGH);
digitalWrite(4, HIGH);
digitalWrite(5, HIGH);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);

myservo1.attach(11);
myservo2.attach(12);
myservo3.attach(13);
myservo5.attach(15);
myservo7.attach(17);
myservo9.attach(19);

}







void loop() {
  // put your main code here, to run repeatedly:

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
if (integerValue <= 10) {
groupNum = integerValue;
} else {
anNum = integerValue;
}

     }


     
//Check Lights
if(groupNum == 0) {
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 0");
}

if(groupNum == 1) {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 1");
}

if(groupNum == 2) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 2");
}

if(groupNum == 3) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 3");
}

if(groupNum == 4) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 4");
}

if(groupNum == 5) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 5");
}

if(groupNum == 6) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  Serial.println("Group 6");
}

if(groupNum == 7) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  Serial.println("Group 7");
}

if(groupNum == 8) {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  Serial.println("Group 8");
}



//Check Analog Outputs

if(anNum == 11) {
  if(elevenState == 0) {
    myservo1.write(180);
    elevenState = 1;
    Serial.println("AO1 ON");
  } else {
    myservo1.write(0);
    elevenState = 0;
    Serial.println("AO1 OFF");
  }
  anNum = 0;
}

if(anNum == 12) {
  if(twelveState == 0) {
    myservo2.write(180);
    twelveState = 1;
    Serial.println("AO2 ON");
  } else {
    myservo2.write(0);
    twelveState = 0;
    Serial.println("AO2 OFF");
  }
  anNum = 0;
}

if(anNum == 13) {
  if(thirteenState == 0) {
    myservo3.write(180);
    thirteenState = 1;
    Serial.println("AO3 ON");
  } else {
    myservo3.write(0);
    thirteenState = 0;
    Serial.println("AO3 OFF");
  }
  anNum = 0;
}

if(anNum == 14) {
  if(fourteenState == 0) {
    digitalWrite(14, HIGH);
    fourteenState = 1;
    Serial.println("AO4 ON");
  } else {
    digitalWrite(14, LOW);
    fourteenState = 0;
    Serial.println("AO4 OFF");
  }
  anNum = 0;
}

if(anNum == 15) {
  if(fifteenState == 0) {
    myservo5.write(180);
    fifteenState = 1;
    Serial.println("AO5 ON");
  } else {
    myservo5.write(0);
    fifteenState = 0;
    Serial.println("AO5 OFF");
  }
  anNum = 0;
}

if(anNum == 16) {
  if(sixteenState == 0) {
    digitalWrite(16, HIGH);
    sixteenState = 1;
    Serial.println("AO6 ON");
  } else {
    digitalWrite(16, LOW);
    sixteenState = 0;
    Serial.println("AO6 OFF");
  }
  anNum = 0;
}

if(anNum == 17) {
  if(seventeenState == 0) {
    myservo7.write(180);
    seventeenState = 1;
    Serial.println("AO7 ON");
  } else {
    myservo7.write(0);
    seventeenState = 0;
    Serial.println("AO7 OFF");
  }
  anNum = 0;
}

if(anNum == 18) {
  if(eighteenState == 0) {
    digitalWrite(18, HIGH);
    eighteenState = 1;
    Serial.println("AO8 ON");
  } else {
    digitalWrite(18, LOW);
    eighteenState = 0;
    Serial.println("AO8 OFF");
  }
  anNum = 0;
}

if(anNum == 19) {
  if(nineteenState == 0) {
    myservo9.write(180);
    nineteenState = 1;
    Serial.println("AO9 ON");
  } else {
    myservo9.write(0);
    nineteenState = 0;
    Serial.println("AO9 OFF");
  }
  anNum = 0;
}

delay(250);


}







