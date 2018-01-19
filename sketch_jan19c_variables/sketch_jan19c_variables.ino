// How many lines will the serial monitor print?
// What will be printed?
int a, b;
void setup() {
  Serial.begin(9600);
  delay(2000);
  a=2;
  b=a;
  Serial.print("a=");
  Serial.println(a);
  Serial.print("b=");
  Serial.println(b);
  delay(2000);
  a=3;
  Serial.print("a=");
  Serial.println(a);
  Serial.print("b=");
  Serial.println(b);
  delay(2000);
}
void loop() {
  delay(1000);
  Serial.print("a=");
  Serial.println(a);
  Serial.print("b=");
  Serial.println(b);
}

/* notes
 * http://www.pd4cs.org/variables-misconception-variables-used-in-programs-work-like-variables-in-math/
 * http://www.pd4cs.org/variables-misconception-assignment-a-b-1-changes-the-value-of-b-by-1-as-well-as-changing-a-2/  
 *
 */
