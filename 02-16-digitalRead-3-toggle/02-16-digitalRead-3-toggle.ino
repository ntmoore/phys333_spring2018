/* digital read example.  blink rate depends on button push
*/
const int buttonPin = 2;
const int ledPin = 3;
int wait_time_ms;
int b_state = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin)) {
    if (b_state == 1) {
      wait_time_ms = 50;
      b_state = 0;
    } else {
      wait_time_ms = 200;
      b_state = 1;
    }
  }
  digitalWrite(ledPin, HIGH);
  delay(wait_time_ms);
  digitalWrite(ledPin, LOW);
  delay(wait_time_ms);

}
