/* this is a simple PWM implementation */
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {

  int i, j;

  int num_pwm_bins = 50;
  int brightness = 1; // out of [0,50], see line above

  for (brightness = 0; brightness <= num_pwm_bins; brightness++) {
    /* as each pwm loop takes 1ms, repeat 200x to get a visible
       brightness level */
    int num_cycles = 200;
    for (i = 0; i < num_cycles; i++) {

      /* this cycle will take 20us*50x = 1000us = 1ms */
      /* BROKEN? What happens when brightness==50? */
      digitalWrite(13, HIGH);
      for (j = 0; j < num_pwm_bins; j++) {
        delayMicroseconds(20);
        if (j == brightness) {
          digitalWrite(13, LOW);
        }
      }
    }
    /* these spaces are inserted to make the different brightness
      levels visible */
    digitalWrite(13, LOW);
    delay(100);
  }
}



