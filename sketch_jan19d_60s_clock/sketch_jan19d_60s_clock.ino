/* this implements a clock/timer that rolls over at 60
 *  clock runs at ~1Hz so effectively it is an example of 
 *  loops w/o explicit "for" structure
 */
int i; // this is the number of seconds, should roll over at 60
void setup() {
  Serial.begin(9600);
  i = 0;
}

void loop() {
  delay(999);
  i = i + 1; // i++; // i+=1;
  if (i == 60) {
    i = 0;
  }

  Serial.print(i);
  Serial.print("\t");
  Serial.println(millis());
}
