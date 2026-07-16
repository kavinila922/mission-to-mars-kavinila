// Story 6 - Drive forward 2 metres and stop

// Left Motor direction
const int LM1 = 12;
const int LM2 = 11;

// Right Motor direction
const int RM1 = 10;
const int RM2 = 9;

// Motor speed pins
const int LEFT_SPEED = 5;
const int RIGHT_SPEED = 6;

bool completed = false;

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
  if (completed == false)
  {
    moveForward();

    // Adjust this value after testing:
    // Time needed to travel 2 metres
    delay(5000);

    stopMotors();

    completed = true;
  }
}


// Move rover forwards
void moveForward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, 255);
  analogWrite(RIGHT_SPEED, 255);
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