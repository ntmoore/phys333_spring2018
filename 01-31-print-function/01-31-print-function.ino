/* 
Using a fucntion to same in the number of lines in the function
*/
void setup() {
  Serial.begin(9600);
}

void loop() {
  int i = 0;
  while (i < 10) {
    delay(1000);
    i = i + 1;
    // using a function to run a couple of print statements
    print_out_int(i);
  }
  Serial.println();

}

void print_out_int(int j) {
  Serial.print(j);
  Serial.print(" ");
  return;
}

