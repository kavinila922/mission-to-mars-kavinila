// Story 9 - Cliff Detection

// Motor pins
const int LM1 = 12;
const int LM2 = 11;
const int RM1 = 10;
const int RM2 = 9;

// PWM speed pins
const int LEFT_SPEED = 5;
const int RIGHT_SPEED = 6;

// Downward-facing ultrasonic sensor
const int trigPin = 7;
const int echoPin = 8;

bool stopped = false;

void setup()
{
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);

  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  if (stopped)
  {
    stopMotors();
    return;
  }

  long groundDistance = getGroundDistance();

  if (groundDistance > 12)
  {
    stopMotors();
    delay(200);

    reverse();
    delay(500);

    stopMotors();

    stopped = true;
  }
  else
  {
    forward();
  }
}

// Measure distance to the ground
long getGroundDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  return duration * 0.034 / 2;
}

// Forward
void forward()
{
  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, 255);
  analogWrite(RIGHT_SPEED, 255);
}

// Reverse
void reverse()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);

  analogWrite(LEFT_SPEED, 255);
  analogWrite(RIGHT_SPEED, 255);
}

// Stop
void stopMotors()
{
  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 0);

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}