// LED pins
const int forwardRed = 11;
const int forwardGreen = 10;
const int forwardYellow = 9;

const int reverseYellow = 8;
const int reverseGreen = 7;
const int reverseRed = 6;

void setup() {
  // Set all pins as OUTPUT
  pinMode(forwardRed, OUTPUT);
  pinMode(forwardGreen, OUTPUT);
  pinMode(forwardYellow, OUTPUT);
  
  pinMode(reverseYellow, OUTPUT);
  pinMode(reverseGreen, OUTPUT);
  pinMode(reverseRed, OUTPUT);
}

void loop() {
  // 1️⃣ Forward sequence (simulate moving forward)
  digitalWrite(forwardRed, HIGH);
  digitalWrite(forwardGreen, HIGH);
  digitalWrite(forwardYellow, HIGH);
  
  digitalWrite(reverseRed, LOW);
  digitalWrite(reverseGreen, LOW);
  digitalWrite(reverseYellow, LOW);
  
  delay(5000); // 5 seconds forward

  // 2️⃣ Stop (all LEDs off)
  digitalWrite(forwardRed, LOW);
  digitalWrite(forwardGreen, LOW);
  digitalWrite(forwardYellow, LOW);
  digitalWrite(reverseRed, LOW);
  digitalWrite(reverseGreen, LOW);
  digitalWrite(reverseYellow, LOW);
  
  delay(1000); // 1 second stop

  // 3️⃣ Reverse sequence (simulate moving backward)
  digitalWrite(reverseRed, HIGH);
  digitalWrite(reverseGreen, HIGH);
  digitalWrite(reverseYellow, HIGH);
  
  digitalWrite(forwardRed, LOW);
  digitalWrite(forwardGreen, LOW);
  digitalWrite(forwardYellow, LOW);
  
  delay(2000); // 2 seconds reverse

  // Loop back to forward
}