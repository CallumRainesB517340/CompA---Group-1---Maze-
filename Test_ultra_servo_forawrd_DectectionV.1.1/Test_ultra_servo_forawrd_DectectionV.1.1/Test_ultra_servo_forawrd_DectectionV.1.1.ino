#include <Servo.h>

Servo servoLeft;          // Define left servo
Servo servoRight;         // Define right servo

  // defines pins numbers
const int trigPin = 10;
const int echoPin = 11;

// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
servoLeft.attach(7);  // Set left servo to digital pin 8
servoRight.attach(2);  // Set right servo to digital pin 9
}

void stopRobot() {
  servoLeft.write(92); // 92 degrees stops both wheels dead
  servoRight.write(92);
}

void forward() {
  servoLeft.write(180); //Tells both wheels to move forward one clockwise and the other anti-clockwise 
  servoRight.write(0);
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance = duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

if (distance > 3 || distance < 0) // If a distance less than 0 or greater than 3 is detected it continue forward, if one is then it will stop 
{ forward(); }
else
{  stopRobot();} }

