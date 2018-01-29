/* Demo PWM implementation.  Only sending one voltage level */
int output_pin = 13;
void setup() {
  Serial.begin(9600);

  pinMode(output_pin, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {


  int i, j;

  int num_pwm_bins = 32;
  int brightness = 1; // out of [0,31], see line above

  // this if statement treats the "edge case" of no brightness
  if (brightness > 0) {

    /* the normal situation is on for "brightness" intervals
        and then off for the remainder of the period,
        "brightness-(num_pwm_bins-1)" intervals
    */
    digitalWrite(output_pin, HIGH);
    for (j = 0; j < num_pwm_bins; j++) {
      if (j == brightness) {
        digitalWrite(output_pin, LOW);
      }
      delayMicroseconds(20);

    }
  }
}

