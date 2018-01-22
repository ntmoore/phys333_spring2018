/* Computers are good at repeated procedures.  Second version of the count
    up code from friday.  

  Predict: What will be printed to serial monitor?
 */

int i;

void setup() {
  Serial.begin(9600);
  i=1;
}

void loop() {

  // wait a second and tick the counter
  delay(1000);
  i += 1;

  if (i == 10) {
    i = 0;
    Serial.print(i);
    Serial.println(" ");
  }
  else {
    Serial.print(i);
    Serial.print(" ");
  }
}
