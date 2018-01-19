// Variable Scope
// Why doesn't this program work?
int i;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  i=0;
  Serial.print(i);
  Serial.print("\t");
  Serial.println(millis());
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  i=i+1;
  Serial.print(i);
  Serial.print("\t");
  Serial.println(millis());
  delay(1000);
}
