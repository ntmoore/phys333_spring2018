/* digital read example.  blink rate depends on button push
*/
const int buttonPin = 2;
const int ledPin = 3;
int b_wait_time_ms = 1000;
int b_state = 0;
int old_time = 0;
// note, if delay_time_ms is not initialized, the progam will have 
// odd behavior until the button is pushed for the first time.  
int delay_time_ms = 200;

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
      // // This section of code didn't initially work because
      // // the second if statement would always be triggered.  Fixed with an "else"
      //    if ((millis() - old_time) > b_wait_time_ms ) {
      //      if (b_state == 1) {
      //        delay_time_ms = 50;
      //        b_state = 0;
      //      } else{
      //      // if (b_state == 0) {
      //        delay_time_ms = 200;
      //        b_state = 1;
      //      }
      // This switch/case statement is equivalent to the (corrected) if block above.
      switch (b_state) {
        case 1:
          delay_time_ms = 50;
          b_state = 0;
          break;
        case 0:
          delay_time_ms = 200;
          b_state = 1;
          break;
        default:
          break;
      }
    }
    /* reset the clock used to avoid multiple button pushes*/
    old_time = millis();
  }

  digitalWrite(ledPin, HIGH);
  delay(delay_time_ms);
  digitalWrite(ledPin, LOW);
  delay(delay_time_ms);
}
