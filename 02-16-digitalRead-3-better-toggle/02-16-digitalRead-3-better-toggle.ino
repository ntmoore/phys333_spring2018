/* digital read example.  blink rate depends on button push
*/
const int buttonPin = 2;
const int ledPin = 3;
int b_wait_time_ms = 10;
int b_state = 0;
int old_time = 0;
int delay_time_ms;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin)) {
    /*
      now, has it been a while since the button was last pushed?
    */
    if ((millis() - old_time) > b_wait_time_ms ) {
      if (b_state == 1) {
        delay_time_ms = 50;
        b_state = 0;
      }
      if (b_state == 0) {
        delay_time_ms = 200;
        b_state = 1;
      }
      /* reset the clock used to avoid multiple button pushes*/
      old_time = millis();
    }
  }
  digitalWrite(ledPin, HIGH);
  delay(delay_time_ms);
  digitalWrite(ledPin, LOW);
  delay(delay_time_ms);

}
