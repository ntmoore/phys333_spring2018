/* Demo PWM implementation.  PWM routine is encapsulated in a funtion.
  Only sending one voltage level */
int output_pin = 13;
void setup() {

  pinMode(output_pin, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  unsigned int fundamental_wait_time_us = 10;
  unsigned int brightness = 40; // out of [0,total_cycles-1]
  unsigned int total_cycles = 600;
  do_pwm(output_pin, fundamental_wait_time_us, brightness, total_cycles );
}

/* the normal situation is on for "brightness" intervals
    and then off for the remainder of the period,
    "brightness-(total_cycles-1)" intervals

    PWM signal is output on "output_pin"

    The PWM signal consists of a number of short intervals for which the output
    pin can be on or off.  This shortest time interval (in microseconds)
    is "fundamental_wait_time_us"

    The function should run for total_cycles*fundamental_wait_time_us
    (in microseconds)
*/
void do_pwm(
  int output_pin,
  unsigned int fundamental_wait_time_us,
  unsigned int brightness,
  unsigned int total_cycles
)
{
  int j;

  /* This if statement treats the "edge case" of no brightness.
      The normal situation is on for "brightness" intervals
      and then off for the remainder of the period,
      "brightness-(num_pwm_bins-1)" intervals
  */
  unsigned int on_time_us, off_time_us;
  on_time_us = fundamental_wait_time_us * brightness;
  off_time_us =  fundamental_wait_time_us * (total_cycles - brightness);

  if (on_time_us > 0) {
    digitalWrite(output_pin, HIGH);
    delayMicroseconds(on_time_us);
    digitalWrite(output_pin, LOW);
    delayMicroseconds(off_time_us);
  } else {
    // This is the case that the brightness is zero.
    digitalWrite(output_pin, LOW);
    delayMicroseconds(off_time_us);
  }


return;
}

