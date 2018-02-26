/* This program shows how you can read a PWM output by reading repeatedly with
    digital read.  The method is like a monte-carlo integration scheme in that
    you are repeatedly reading (at random times) the output value.  Via the central
    limit theorum, as the number of reads approaches infinity, the measured duty
    level approaches the value specified in the code.

    The PWM measurement (duty level, out of 1.0) is estimated to be
      sum/num_reads
    The uncertainty in sum is poisson, \sqrt(sum), so you could say that the
    uncertainty in num is
      +/- sqrt(sum)/num_reads

  Nathan Moore, Winona State University
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(13, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // system PWM output on 3, duty = 48/255 ~= 0.188
  int d = 48;
  analogWrite(3, d);
  Serial.print("\nPWM duty level is ");
  Serial.print(d);
  Serial.print(" out of 255, d ~= ");
  Serial.println((float)d / (float)255, 5);

  // run a wire from pin 3 to pin 13
  long sum = 0;
  long num_reads = 100000;
  for (long i = 0; i < num_reads; i++) {
    sum += digitalRead(13);
  }
  Serial.print(" Measuring: ");
  Serial.print(sum);
  Serial.print(" of ");
  Serial.println(num_reads);
  Serial.print("Estimating duty level to be: ");
  float duty_level = (float)sum / (float)num_reads;
  Serial.print(duty_level, 5);
  Serial.print(" (+/-) ");
  float uncertainty  =  sqrt((float)sum) / (float)num_reads;
  Serial.println(uncertainty, 5);

  delay(2000);

}
