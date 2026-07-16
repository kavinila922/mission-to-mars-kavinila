// Story 8 - Obstacle Avoidance

// Motor pins
const int LM1 = 12;
const int LM2 = 11;
const int RM1 = 10;
const int RM2 = 9;

// PWM speed pins
const int LEFT_SPEED = 5;
const int RIGHT_SPEED = 6;

// Ultrasonic sensor pins
const int trigPin = 7;
const int echoPin = 8;

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
  long distance = getDistance();

  if (distance <= 12)
  {
    stopMotors();
    delay(500);

    reverse();
    delay(1000);

    turnLeft();
    delay(850);
  }
  else
  {
    forward();
  }
}

// Measure distance using HC-SR04
long getDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  long distance = duration * 0.034 / 2;

  return distance;
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

// Turn left
void turnLeft()
{
  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);

  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);

  analogWrite(LEFT_SPEED, 0);
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
