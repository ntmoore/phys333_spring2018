/*
    Nathan Moore, 03-11-2018

    Simple program to read the input from a digital "morse" communication line.
    Code looks for risin or falling edges from a digital transmission.  Times
    that an edge are detected, as wells as R-rising or F-Falling are printed to
    the serial console.  Data processing could be added on to this.
*/

int data_in = 13;
int d0, d1, t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(data_in, INPUT);
  d0 = digitalRead(data_in);
}

void loop() {
  /* note, this code runs falt out with no delay.  This is not the optimal
    way to look for clock edges. */
  d1 = digitalRead(data_in);
  t = millis();
  // look for 01, rising
  if ( !d0 && d1 ) {
    Serial.print("R ");
    Serial.println(t);
  }
  // look for 10, falling
  if ( d0 && !d1 ) {
    Serial.print("F ");
    Serial.println(t);
  }
  // get ready for the next cycle
  d0 = d1;

}

