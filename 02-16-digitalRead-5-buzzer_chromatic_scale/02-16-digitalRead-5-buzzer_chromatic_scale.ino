/* digital read example.  play a chromatic scale.  This is suppose to work but 
 *  doesn't on the grove buzzer.  Maybe its the wrong freq for the buzzer?
*/
const int buttonPin = 2;
const int buzzerPin = 7;
int wait_time_us = 500;
int b_state = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin)) {
    Serial.println(b_state);
    Serial.println(wait_time_us);
    switch (b_state) {
      case 0:
        wait_time_us = 602;
        break;
      case 1:
        wait_time_us = 638;
        break;
      case 2:
        wait_time_us = 676;
        break;
      case 3:
        wait_time_us = 716;
        break;
      case 4:
        wait_time_us = 758;
        break;
      case 5:
        wait_time_us = 804;
        break;
      case 6:
        wait_time_us = 851;
        break;
      case 7:
        wait_time_us = 902;
        break;
      case 8:
        wait_time_us = 956;
        break;
      case 9:
        wait_time_us = 1012;
        break;
      case 10:
        wait_time_us = 1073;
        break;
      case 11:
        wait_time_us = 1136;
        break;
    }
    b_state += 1;
    if (b_state == 12) {
      b_state = 0;
    }
  }

  digitalWrite(buzzerPin, HIGH);
  delay(wait_time_us);
  digitalWrite(buzzerPin, LOW);
  delay(wait_time_us);

}
