#include <Servo.h>

Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

/*
  Standard Servo Position.c
 
  Moves servo to 0, 90 and 180 degrees.  Holds each position for 2 s.
  Connect servo to P16 port on Propeller Activity Board.
*/
void loop()

{
  servoLeft.write(92);
 servoRight.write(92);
 delay(1500);
  servoLeft.write(90);
 servoRight.write(90); 
}

//Set up I/O
void setup() 
{
servoLeft.attach(2); 
servoRight.attach(7); 
}
