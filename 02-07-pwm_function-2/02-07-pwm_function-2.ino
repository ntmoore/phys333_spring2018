/* Demo PWM implementation.  PWM routine is encapsulated in a funtion.
  Only sending one voltage level */
int output_pin = 13;
void setup() {

  pinMode(output_pin, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  int fundamental_wait_time_us = 10;
  int brightness = 32; // out of [0,total_cycles-1]
  int total_cycles = 64;
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
  int fundamental_wait_time_us,
  int brightness,
  int total_cycles
)
{
  int j;

  /* This if statement treats the "edge case" of no brightness.
      The normal situation is on for "brightness" intervals
      and then off for the remainder of the period,
      "brightness-(num_pwm_bins-1)" intervals
  */
  if (brightness > 0) {
    digitalWrite(output_pin, HIGH);
  } else {
    digitalWrite(output_pin, LOW);
  }

  /* iterate until you reach the HIGH->LOW transition time */
  for (j = 0; j < total_cycles; j++) {
    if (j == brightness) {
      digitalWrite(output_pin, LOW);
    }
    delayMicroseconds(fundamental_wait_time_us);
  }

  return;
}

