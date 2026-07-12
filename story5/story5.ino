// Story 5 - Mission to Mars
// Rover snakes forwards using PWM motor speed control

// Left Motor
const int LM1 = 12;
const int LM2 = 11;

// Right Motor
const int RM1 = 10;
const int RM2 = 9;

// PWM Speed Pins
const int LEFT_SPEED = 5;
const int RIGHT_SPEED = 6;

void setup()
{
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);

  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
}

void loop()
{
  snakeMovement();
}

void forward(int leftSpeed, int rightSpeed)
{
  // Left motor forward
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  // Right motor forward
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, leftSpeed);
  analogWrite(RIGHT_SPEED, rightSpeed);
}

void stopMotors()
{
  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 0);
}

void straight()
{
  forward(255, 255);
  delay(2000);
}

void left()
{
  // Left motor slower
  forward(120, 255);
  delay(2000);
}

void right()
{
  // Right motor slower
  forward(255, 120);
  delay(2000);
}

void snakeMovement()
{
  straight();   // 2 seconds
  left();       // 2 seconds
  right();      // 2 seconds
  left();       // 2 seconds
  right();      // 2 seconds

  stopMotors();
  while(true);   // Stops program after one complete sequence
}