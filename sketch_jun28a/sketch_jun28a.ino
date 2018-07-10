

int rightForwardPin = 9;
int leftForwardPin = 3;//
int rightBackwardPin = 11;
int leftBackwardPin = 5;





void setup() {
  

pinMode(rightForwardPin, OUTPUT);
pinMode(leftForwardPin, OUTPUT);
pinMode(rightBackwardPin, OUTPUT);
pinMode(leftBackwardPin, OUTPUT);

}

void loop() {
 
digitalWrite(rightForwardPin, HIGH);
delay(1000);
digitalWrite(rightForwardPin, LOW);
delay(1000);
digitalWrite(leftForwardPin, HIGH);
delay(1000);
digitalWrite(leftForwardPin, LOW);
delay(1000);
digitalWrite(rightBackwardPin, HIGH);
delay(1000);
digitalWrite(rightBackwardPin, LOW);
delay(1000);
digitalWrite(leftBackwardPin, HIGH);
delay(1000);
digitalWrite(leftBackwardPin, LOW);
delay(1000);


}
