/* This program shows how you can average a number of readings to provide more detail that
 *  a single 10-bit ADC reading suggests. 
*/

#define N 100
int sensorPin = A0;    // select the input pin for the potentiometer

void setup() {
  Serial.begin(9600);
  Serial.print("Measuring temperature via analog read.  \nReadings are averaged over ");
  Serial.print(N);
  Serial.print(" consecutive measurements:\n\t dv is standard deviation, dT is averaging interval)\n");
  Serial.print("time (ms), dT, v (Volts), dv\n");
}

void loop() {

  int i, r[N];
  unsigned long t1 = millis();
  for (i = 0; i < N; i++) {
    r[i] = analogRead(sensorPin);
  }
  unsigned long t2 = millis();

  /* compute averages */
  double sum = 0.0;
  double sum_sqr = 0.0;
  for (i = 0; i < N; i++) {
    sum += 1.0 * r[i];
    sum_sqr += 1.0 * r[i] * r[i];
  }
  double avg = sum / (double)N;
  double avg_sqr = sum_sqr / (double)N;
  double  sigma = sqrt(avg_sqr - avg * avg);

  Serial.print("{");
  Serial.print(    0.5 * (t1 + t2));
  Serial.print(",\t");
  Serial.print(t2 - t1);
  Serial.print(",\t");
  Serial.print(avg * (5.0 / 1023.0), 6);
  Serial.print(",\t");
  Serial.print(sigma * (5.0 / 1023.0), 6);
  Serial.println("},");
}
