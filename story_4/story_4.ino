// ===== Pin Definitions =====
const int forwardRed = 11;
const int forwardGreen = 10;
const int forwardYellow = 9;

const int reverseYellow = 8;
const int reverseGreen = 7;
const int reverseRed = 6;

// ===== Setup =====
void setup() {
  pinMode(forwardRed, OUTPUT);
  pinMode(forwardGreen, OUTPUT);
  pinMode(forwardYellow, OUTPUT);
  
  pinMode(reverseYellow, OUTPUT);
  pinMode(reverseGreen, OUTPUT);
  pinMode(reverseRed, OUTPUT);
}

// ===== Main Loop =====
void loop() {
  moveForward();
  stopRover();
  moveReverse();
}

// ===== Movement Functions =====

void moveForward() {
  digitalWrite(forwardRed, HIGH);
  digitalWrite(forwardGreen, HIGH);
  digitalWrite(forwardYellow, HIGH);

  digitalWrite(reverseRed, LOW);
  digitalWrite(reverseGreen, LOW);
  digitalWrite(reverseYellow, LOW);

  delay(5000); // Forward for 5 seconds
}

void stopRover() {
  digitalWrite(forwardRed, LOW);
  digitalWrite(forwardGreen, LOW);
  digitalWrite(forwardYellow, LOW);
  digitalWrite(reverseRed, LOW);
  digitalWrite(reverseGreen, LOW);
  digitalWrite(reverseYellow, LOW);

  delay(1000); // Stop for 1 second
}

void moveReverse() {
  digitalWrite(reverseRed, HIGH);
  digitalWrite(reverseGreen, HIGH);
  digitalWrite(reverseYellow, HIGH);

  digitalWrite(forwardRed, LOW);
  digitalWrite(forwardGreen, LOW);
  digitalWrite(forwardYellow, LOW);

  delay(2000); // Reverse for 2 seconds
}