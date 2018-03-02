/* Demo DAC sine wave implementation
*/
int output_pin = 13;
void setup() {

  pinMode(output_pin, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {

  unsigned int fundamental_wait_time_us = 10;
  unsigned int brightness = 40; // out of [0,total_cycles-1]
  unsigned int total_cycles = 256;

  /* make 122/500 brightness for 2sec */
  int t1 = millis();
  brightness = (total_cycles * 122) / 500;
  while ((millis()-t1) < 2000) {
    do_pwm(output_pin, fundamental_wait_time_us, brightness, total_cycles );
  }
  digitalWrite(13, LOW);
  delay(1000);

  /* make 377/500 brightness for 3 sec */
  t1 = millis();
  brightness = (total_cycles * 377) / 500;
  while ((millis()-t1) < 3000) {
    do_pwm(output_pin, fundamental_wait_time_us, brightness, total_cycles );
  }
  digitalWrite(13, LOW);
  delay(1000);
  
  /* make sine wave brightness for 5 seconds */
  int frequency = 2;
  // 2*pi*f/1000 = 0.0062831853 * f   note 1000 is to account for millis() returning time in ms
  float omega = 0.0062831853 * frequency;
  t1 = millis();
  while ((millis()-t1) < 5000) {
    brightness = total_cycles * (0.5*(1.0 + sin(omega * millis())));
    do_pwm(output_pin, fundamental_wait_time_us, brightness, total_cycles );
  }
  digitalWrite(13, LOW);
  delay(1000);

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
