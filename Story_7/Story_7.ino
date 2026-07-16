// Story 7 - Rover Figure of Eight

// Left Motor
const int LM1 = 12;
const int LM2 = 11;

// Right Motor
const int RM1 = 10;
const int RM2 = 9;

// PWM speed pins
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
  // Leave garage
  forward();
  delay(2000);

  // Left hand square
  for (int i = 0; i < 4; i++)
  {
    forward();
    delay(2000);

    turnLeft();
    delay(850);
  }


  // Right hand square
  for (int i = 0; i < 4; i++)
  {
    forward();
    delay(2000);

    turnRight();
    delay(850);
  }


  stopMotors();

  // Prevent repeating
  while(true);
}


// Move forward
void forward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, 255);
  analogWrite(RIGHT_SPEED, 255);
}


// Turn left
void turnLeft()
{
  // Left wheel slower, right wheel faster
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 255);
}


// Turn right
void turnRight()
{
  // Right wheel slower, left wheel faster
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, 255);
  analogWrite(RIGHT_SPEED, 0);
}


// Stop rover
void stopMotors()
{
  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 0);

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}