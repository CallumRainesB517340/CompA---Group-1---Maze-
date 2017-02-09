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

delayMicroseconds(100);
 
digitalWrite(trigPinFS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinFS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinFS, LOW);
durationFS = pulseIn(echoPinFS, HIGH);
distanceFS = durationFS*0.034/2;

delayMicroseconds(100);
 
digitalWrite(trigPinRS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinRS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRS, LOW);
durationRS = pulseIn(echoPinRS, HIGH);
distanceRS = durationRS*0.034/2;

delayMicroseconds(100);

if (distanceLS < 4  &&  distanceFS > 4 && distanceRS > 4 )
    {
    TurnRight();  
    }
       else if (distanceLS > 4  &&  distanceFS > 4 && distanceRS < 4 )
          { 
          TurnLeft();
           }
               else if (distanceLS < 4  &&  distanceFS > 4 && distanceRS < 4 )
               //(distanceLS < 4 || distanceLS > 0 &&  distanceFS > 4 || distanceFS < 0 && distanceRS > 4 || distanceRS < 0 )             
               { 
               Forward();
               }
           else         
               { 
               stopRobot();
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
  servoLeft.write(0);  
  servoRight.write(0);
}

void TurnLeft() 
{
  servoLeft.write(180);
  servoRight.write(180);
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
