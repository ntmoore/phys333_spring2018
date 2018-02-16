/* digital read example.  blink rate depends on button push
*/
const int buttonPin = 2;
const int buzzerPin = 7;
int wait_time_us;
int b_state = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin)) {
    if (b_state == 1) {
      wait_time_us = 50;
      b_state = 0;
    } else {
      wait_time_us = 200;
      b_state = 1;
    }
  }
  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(wait_time_us);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(wait_time_us);

}
