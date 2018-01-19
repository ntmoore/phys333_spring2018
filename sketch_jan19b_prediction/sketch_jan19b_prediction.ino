// What will this program print?
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  i=0;
}

void loop() {
  // put your main code here, to run repeatedly:
  i=i+1;
  Serial.print(i);
  Serial.print("\t");
  Serial.print(millis());
  Serial.print("\n");
  delay(1000);
}
