#include <Servo.h>

Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

int i;
void loop() 
{
  i=0;
  do{
     delay(1500); 
     i++;
servoLeft.write(85);
servoRight.write(85);

    }
    while (i = 0);
 stopRobot(); 
}
  
// Robot Motor Functions 




void stopRobot() 
{
  servoLeft.write(90);
  servoRight.write(90);
}

void The() 
{
  servoLeft.write(85);
  servoRight.write(85);
}

void Forward() 
{
  servoLeft.write(95);
  servoRight.write(85);
}

void AdjustCourseLeft()
{
  servoLeft.write(92);
  servoRight.write(90); 
}

void AdjustCourseRight()
{
  servoLeft.write(95);
  servoRight.write(91); 
}


//Set up I/O
void setup() 
{
servoLeft.attach(2); 
servoRight.attach(7); 
}
