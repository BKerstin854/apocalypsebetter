/* Arduino USB Keyboard HID demo
 * Volume+/Volume-/Mute keys
 */

uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define PIN_UP 2
#define PIN_DOWN 3
#define PIN_LEFT 4
#define PIN_RIGHT 5
#define PIN_1 6
#define PIN_2 7
#define PIN_3 8
#define PIN_4 9
#define PIN_5 10
#define PIN_6 11
#define PIN_7 12
#define PIN_8 13
#define PIN_9 14
#define PIN_A 15
#define PIN_X 16
#define PIN_Y 17
#define PIN_POT 18
#define PIN_SLI 19


int state = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(PIN_UP, INPUT);
  pinMode(PIN_DOWN, INPUT);
  pinMode(PIN_LEFT, INPUT);
  pinMode(PIN_RIGHT, INPUT);
  pinMode(PIN_1, INPUT);
  pinMode(PIN_2, INPUT);
  pinMode(PIN_3, INPUT);
  pinMode(PIN_4, INPUT);
  pinMode(PIN_5, INPUT);
  pinMode(PIN_6, INPUT);
  pinMode(PIN_7, INPUT);
  pinMode(PIN_8, INPUT);
  pinMode(PIN_9, INPUT);
  pinMode(PIN_X, INPUT);
  pinMode(PIN_Y, INPUT);
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_SLI, INPUT);

  
  // enable internal pull-ups
  
 
  delay(200);
}

void loop() 
{



  
    state = digitalRead(PIN_1);
    if (state != 1) {
      buf[2] = 30;   // 1
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_2);
    if (state != 1) {
      buf[2] = 31;   // 2
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_3);
    if (state != 1) {
      buf[2] = 32;   // 3
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_4);
    if (state != 1) {
      buf[2] = 33;   // 4
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_5);
    if (state != 1) {
      buf[2] = 34;   // 5
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_6);
    if (state != 1) {
      buf[2] = 35;   // 6
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_7);
    if (state != 1) {
      buf[2] = 36;   // 7
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  
    state = digitalRead(PIN_8);
    if (state != 1) {
      buf[2] = 37;   // 8
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 



    state = digitalRead(PIN_9);
    if (state != 1) {
      buf[2] = 38;   // 9
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  

  // Check other Pins

  state = digitalRead(PIN_UP);
    if (state != 1) {
      buf[2] = 82;   // Up Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = digitalRead(PIN_DOWN);
    if (state != 1) {
      buf[2] = 81;   // Down Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = digitalRead(PIN_LEFT);
    if (state != 1) {
      buf[2] = 80;   // Left Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = digitalRead(PIN_RIGHT);
    if (state != 1) {
      buf[2] = 79;   // Right Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = digitalRead(PIN_A);
    if (state != 1) {
      buf[2] = 4;   // A Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = analogRead(PIN_POT);
    if ((state >= 400) && (state <= 600)) {
      buf[2] = 19;   // P Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = analogRead(PIN_SLI);
    if ((state >= 400) && (state <= 600)) {
      buf[2] = 22;   // S Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = analogRead(PIN_X);
    if (state <= -10) {
      buf[2] = 80;   // Left Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = analogRead(PIN_X);
    if (state >= 10) {
      buf[2] = 79;   // Right Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = analogRead(PIN_Y);
    if (state <= -10) {
      buf[2] = 81;   // Down Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 

  state = analogRead(PIN_Y);
    if (state >= 10) {
      buf[2] = 82;   // Up Key
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    } 



  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
}
