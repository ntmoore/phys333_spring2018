/* This programs encapsulates a "max of three integers" routine.  Note as well that
    string printing via sprintf is also included.
    Placeholders:
      %ld is long int
      %3d is int, fit/truncated into 3 spaces
      %7.3f is a float, allocated 7 spaces, 3 digits after dp, eg 234.567
  */
  void setup() {
  Serial.begin(9600);
  delay(1000);
  }

  void loop() {

  long x, y, z, max_val;
  char output_line[80];

  for (int i = 0; i < 3; i++) {
    x = random(20);
    y = random(20);
    z = random(20);

    // these lines for debugging
    sprintf(output_line, "Sending to function: %2ld,%2ld,%2ld awesome\n", x, y, z);
    Serial.print(output_line);

    max_val = find_max_of_3(x, y, z);

    // these lines for debugging
    sprintf(output_line, "The function returned: %2ld \n\n", max_val);
    Serial.print(output_line);
    delay(5000);
  }
  }

  long find_max_of_3(long a, long b, long c) {
  long max_val = a;
  Serial.print("the function recieved:");
  Serial.print(a);
  Serial.print(",");
  Serial.print(b);
  Serial.print(",");
  Serial.println(c);

  if (b > max_val) {
    max_val = b;
  }
  if (c > max_val) {
    max_val = c;
  }
  Serial.print("\tMax value: ");
  Serial.println(max_val);

  return max_val;
  }

