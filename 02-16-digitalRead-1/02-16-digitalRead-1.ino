/* intro to digitalRead()
    turn a light on if a button is pushed
*/
const int buttonPin = 2;
const int ledPin = 3;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  /* note the compact (lazy code).  digitalRead() returns an int so I can
      use it inside a conditional block.  This works but can be hard to read
      if done too much
  */
  if (digitalRead(buttonPin)) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(2000);

}
