/* Arduino USB Keyboard HID demo
 * Volume+/Volume-/Mute keys
 */

uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */

#define PIN_UP 2
#define PIN_DOWN 3
#define PIN_LEFT 4
#define PIN_RIGHT 5
#define PIN_A 6
#define PIN_1 7
#define PIN_2 8
#define PIN_3 9
#define PIN_4 10
#define PIN_5 11
#define PIN_6 12
#define PIN_7 13
#define PIN_8 14
#define PIN_9 15
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
  pinMode(PIN_A, INPUT);
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
  digitalWrite(PIN_UP, 1); 
  digitalWrite(PIN_DOWN, 1);
  digitalWrite(PIN_LEFT, 1);
  digitalWrite(PIN_RIGHT, 1); 
  digitalWrite(PIN_A, 1); 
  digitalWrite(PIN_1, 1); 
  digitalWrite(PIN_2, 1);
  digitalWrite(PIN_3, 1);
  digitalWrite(PIN_4, 1); 
  digitalWrite(PIN_5, 1);
  digitalWrite(PIN_6, 1); 
  digitalWrite(PIN_7, 1);
  digitalWrite(PIN_8, 1);
  digitalWrite(PIN_9, 1); 
  digitalWrite(PIN_X, 1); 
  digitalWrite(PIN_Y, 1);
  digitalWrite(PIN_POT, 1);
  digitalWrite(PIN_SLI, 1); 
   

  delay(200);
}

void loop() 
{
  state = digitalRead(PIN_UP);
  if (state != 1) {
    buf[2] = 82;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_DOWN);
  if (state != 1) {
    buf[2] = 81;   // Volume down key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_LEFT);
  if (state != 1) {
    buf[2] = 80;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_RIGHT);
  if (state != 1) {
    buf[2] = 79;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_A);
  if (state != 1) {
    buf[2] = 4;   // A key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_1);
  if (state != 1) {
    buf[2] = 30;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_2);
  if (state != 1) {
    buf[2] = 31;   // Volume down key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_3);
  if (state != 1) {
    buf[2] = 32;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_4);
  if (state != 1) {
    buf[2] = 33;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_5);
  if (state != 1) {
    buf[2] = 34;   // A key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_6);
  if (state != 1) {
    buf[2] = 35;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_7);
  if (state != 1) {
    buf[2] = 36;   // Volume down key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_8);
  if (state != 1) {
    buf[2] = 37;   // Volume up key
    Serial.write(buf, 8); // Send keypress
    releaseKey();
  } 

  state = digitalRead(PIN_9);
  if (state != 1) {
    buf[2] = 38;   // Volume up key
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

/*state = analogRead(PIN_X);
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
*/
  
}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key  
  delay(500);
}
