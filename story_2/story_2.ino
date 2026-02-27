// Arduino: alternate flashing LEDs with no pause

const int led1 = 13;  // LED 1
const int led2 = 12;  // LED 2

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);  // LED 1 on
  digitalWrite(led2, LOW);   // LED 2 off
  delay(1000);                // wait 1 second

  digitalWrite(led1, LOW);   // LED 1 off
  digitalWrite(led2, HIGH);  // LED 2 on
  delay(1000);                // wait 1 second
}