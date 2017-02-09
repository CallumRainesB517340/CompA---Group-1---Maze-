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


// defines variables
long durationLS;
int distanceLS;
long durationFS;
int distanceFS;
long durationRS;
int distanceRS;


void loop() 
{
digitalWrite(trigPinLS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinLS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinLS, LOW);
durationLS = pulseIn(echoPinLS, HIGH);
distanceLS = durationLS*0.034/2;

delayMicroseconds(50);
 
digitalWrite(trigPinFS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinFS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinFS, LOW);
durationFS = pulseIn(echoPinFS, HIGH);
distanceFS = durationFS*0.034/2;

delayMicroseconds(50);
 
digitalWrite(trigPinRS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinRS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRS, LOW);
durationRS = pulseIn(echoPinRS, HIGH);
distanceRS = durationRS*0.034/2;


if (distanceLS > 2 || distanceLS < 0  && distanceFS > 2 || distanceFS < 0  && distanceRS > 2 || distanceRS < 0 )
    {
    stopRobot();  
    }
         else
            { 
          TurnLeft();
            }
        }
  
// Robot Motor Functions 

void stopRobot() 
{
  servoLeft.write(92);
  servoRight.write(92);
}

void Forward() 
{
  servoLeft.write(100);
  servoRight.write(84);
}

void TurnRight() 
{
  servoLeft.write(100);  
  servoRight.write(92);
}

void TurnLeft() 
{
  servoLeft.write(92);
  servoRight.write(84);
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
servoLeft.attach(7); 
servoRight.attach(2); 
}
