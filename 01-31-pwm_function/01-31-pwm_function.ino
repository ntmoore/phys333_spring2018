/* Demo PWM implementation.  PWM routine is encapsulated in a funtion.  
Only sending one voltage level */
int output_pin = 13;
void setup() {

  pinMode(output_pin, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  int brightness = 10; // out of [0,31], see line above
  do_pwm_32cycles_20us(brightness, output_pin);

}

/* the normal situation is on for "brightness" intervals
    and then off for the remainder of the period,
    "brightness-(num_pwm_bins-1)" intervals
*/
void do_pwm_32cycles_20us(int on_level, int pwm_pin) {
  int j;
  int num_pwm_bins=32; // number of cycles the PWM brightness can range over
  int cycle_length=20; // in us
  
  // this if statement treats the "edge case" of no brightness
  if (on_level > 0) {

    /* the normal situation is on for "brightness" intervals
        and then off for the remainder of the period,
        "brightness-(num_pwm_bins-1)" intervals
    */
    digitalWrite(output_pin, HIGH);
    for (j = 0; j < num_pwm_bins; j++) {
      if (j == on_level) {
        digitalWrite(output_pin, LOW);
      }
      delayMicroseconds(cycle_length);
    }
  }
}
