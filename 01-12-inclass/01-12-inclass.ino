/*
  Nathan Moore
  Jan 12
  Examples related to variables and printing.
*/

int i; // integer
bool a; // boolean
float b; // number with a decimal point
char letter; // character variable

void setup() {
  // put your setup code here, to run once:
  i = 2;
  a = true;
  b = acos(-1.0); // this is PI to machine precision
  letter = 'f'; // note, "f" doesn't work 

  // start up the serial (USB) connection
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(i);
  Serial.println(a);
  Serial.println(a, HEX);
  Serial.println(b, 30);
  Serial.print("\t"); // this is a tab
  Serial.println(letter);
  Serial.print("\n"); // this is a newline

  delay(1000);
}


















