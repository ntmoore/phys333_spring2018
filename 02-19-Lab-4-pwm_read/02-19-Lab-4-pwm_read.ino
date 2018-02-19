void setup() {
  // put your setup code here, to run once:
  pinMode(13, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // system PWM output on 3, duty = 48/255
  analogWrite(3, 48);
  // run a wire from pin 3 to pin 13
  Serial.println(digitalRead(13));
  Serial.println(digitalRead(13));
  Serial.println(digitalRead(13));
  delay(500);
  Serial.println(digitalRead(13));
  Serial.println(digitalRead(13));
  Serial.println(digitalRead(13));
  delay(500);
  Serial.println(digitalRead(13));
  Serial.println(digitalRead(13));
  Serial.println(digitalRead(13));
  delay(2000);
}
