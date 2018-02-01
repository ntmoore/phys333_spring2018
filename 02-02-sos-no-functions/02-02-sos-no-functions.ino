/* This is Nathan Anderson's solution to the SOS code, BUT all of the functions
    have been "inlined".  Note that this would be comparitively difficult
    to debug/audit.
  Nathan Moore, Feb 1
*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); //Have the built-in LED and pin 13 as output
}

void loop() {
  //SOS();    //Blinks SOS in morse code
  for (int s = 1; s <= 3; ++s) {
    //dot();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);   //One unit time = 250 ms
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }
  delay(100);

  for (int o = 1; o <= 3; ++o) {
    //dash();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(750);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }
  delay(100);

  for (int s = 1; s <= 3; ++s) {
    //dot();
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);   //One unit time = 250 ms
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
  }

  delay(1500);
}
