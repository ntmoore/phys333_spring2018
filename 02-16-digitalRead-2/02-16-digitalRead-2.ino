/* digital read example.  blink rate depends on button push
*/
const int buttonPin = 2;
const int ledPin = 3;
int wait_time_ms;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin)) {
    wait_time_ms = 50;
  } else {
    wait_time_ms = 200;
  }

  digitalWrite(ledPin, HIGH);
  delay(wait_time_ms);
  digitalWrite(ledPin, LOW);
  delay(wait_time_ms);

}
