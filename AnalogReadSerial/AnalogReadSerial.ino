int micPin = A0;
void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(micPin);
  Serial.write(sensorValue); /*for parsing into .wav*/
//  Serial.print("0 ");
//  Serial.print(sensorValue);
//  Serial.println(" 1024"); /*for debugging*/
}
