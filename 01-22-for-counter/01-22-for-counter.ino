/* This ia a "for" loop version of the same 0-9 counter
*/
void setup() {
  Serial.begin(9600);
}

void loop() {
  int i;
  for (i = 0; i < 10; i++) {
    delay(1000);
    Serial.print(i);

    if (i == 9) {
      Serial.println();
    } else {
      Serial.print(" ");
    }
    
  }
}
