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

delayMicroseconds(10000);
 
digitalWrite(trigPinFS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinFS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinFS, LOW);
durationFS = pulseIn(echoPinFS, HIGH);
distanceFS = durationFS*0.034/2;

delayMicroseconds(10000);
 
digitalWrite(trigPinRS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinRS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRS, LOW);
durationRS = pulseIn(echoPinRS, HIGH);
distanceRS = durationRS*0.034/2;

delay(10);
    Serial.print(" ---New Set Of Readings--- ");    // This set of code simply output the data values to the computer instead of say LCD screen. 
    Serial.print("Ls-"); Serial.print(distanceLS);
    Serial.print("Fs-"); Serial.print(distanceFS);
    Serial.print("Rs-"); Serial.print(distanceRS);
    Serial.println(" ");

}
//Set up I/O
void setup() 
{
Serial.begin (9600);
pinMode(trigPinLS, OUTPUT);
pinMode(echoPinLS, INPUT); 
pinMode(trigPinFS, OUTPUT);
pinMode(echoPinFS, INPUT);
pinMode(trigPinRS, OUTPUT); 
pinMode(echoPinRS, INPUT);
}
