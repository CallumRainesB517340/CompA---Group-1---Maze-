#include <Servo.h>

Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

// defines pins numbers
const int trigPinLS = 8;
const int echoPinLS = 9;
const int trigPinFS = 10;
const int echoPinFS = 11;
const int trigPinRS = 12;
const int echoPinRS = 13;


const int trigPinPLS = 3;
const int echoPinPLS = 4;
const int trigPinPRS = 6;
const int echoPinPRS = 5;


// defines variables
long durationLS;
int distanceLS;
long durationFS;
int distanceFS;
long durationRS;
int distanceRS;

int distancePLS;
long durationPLS;
int distancePRS;
long durationPRS;


static int T = 1 ;

void loop()
{
  digitalWrite(trigPinLS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinLS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLS, LOW);
  durationLS = pulseIn(echoPinLS, HIGH);
  distanceLS = durationLS * 0.034 / 2;

  delayMicroseconds(50);

  digitalWrite(trigPinFS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinFS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinFS, LOW);
  durationFS = pulseIn(echoPinFS, HIGH);
  distanceFS = durationFS * 0.034 / 2;

  delayMicroseconds(50);

  digitalWrite(trigPinRS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinRS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinRS, LOW);
  durationRS = pulseIn(echoPinRS, HIGH);
  distanceRS = durationRS * 0.034 / 2;

  delayMicroseconds(50);

  digitalWrite(trigPinPLS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinPLS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinPLS, LOW);
  durationPLS = pulseIn(echoPinPLS, HIGH);
  distancePLS = durationPLS * 0.034 / 2;

  delayMicroseconds(50);

  digitalWrite(trigPinPRS, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinPRS, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinPRS, LOW);
  durationPRS = pulseIn(echoPinPRS, HIGH);
  distancePRS = durationPRS * 0.034 / 2;


  if (distanceLS >= 10 && distanceFS <= 10 && distanceRS >= 10 && T == 1 )

  {
    TurnLeft();
    delay(1750);
  }

  else if (distanceLS >= 10 && distanceFS <= 10 && distanceRS >= 10 && T == 2)
  {
    TurnRight();
    delay(1750);
  }

  else if ( distanceLS <= 6 && distanceFS <= 6 && distanceRS <= 6)
  {
    TurnRight();
    delay(2250);
    T ++;
  }

  else
  {
    Forward();
  }
}




void stopRobot()
{
  servoLeft.write(90);
  servoRight.write(90);
}

void Forward()
{
  servoLeft.write(88);
  servoRight.write(92);
}

void AdjustCourseLeft()
{
  servoLeft.write(88);
  servoRight.write(93);
}

void AdjustCourseRight()
{
  servoLeft.write(87);
  servoRight.write(92);
}

void AdjustCourseReverseLeft()
{
  servoLeft.write(92);
  servoRight.write(90);
}

void AdjustCourseReverseRight()
{
  servoLeft.write(90);
  servoRight.write(88);
}

void Reverse()
{
  servoLeft.write(92);
  servoRight.write(88);
}


void TurnRight()
{
  servoLeft.write(93);
  servoRight.write(93);
}

void TurnLeft()
{
  servoLeft.write(87);
  servoRight.write(87);
}



//Set up I/O
void setup()
{
  pinMode(trigPinLS, OUTPUT);
  pinMode(echoPinLS, INPUT);
  pinMode(trigPinFS, OUTPUT);
  pinMode(echoPinFS, INPUT);
  pinMode(trigPinRS, OUTPUT);
  pinMode(echoPinRS, INPUT);
  Serial.begin (9600);
  pinMode(trigPinPLS, OUTPUT);
  pinMode(echoPinPLS, INPUT);
  pinMode(trigPinPRS, OUTPUT);
  pinMode(echoPinPRS, INPUT);
  servoLeft.attach(7);
  servoRight.attach(2);
}
