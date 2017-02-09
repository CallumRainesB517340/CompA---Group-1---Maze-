#include <Average.h>


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
int ArraySizeLS[5];

long durationFS;
int distanceFS;
int ArraySizeFS[5];

long durationRS;
int distanceRS;
int ArraySizeRS[5];

int i;
int average; 

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
}


void loop () 
{
  i=0;
  
  do{

digitalWrite(trigPinRS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinRS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinRS, LOW);
durationRS = pulseIn(echoPinRS, HIGH);
distanceRS = durationRS*0.034/2;
ArraySizeRS[i]=distanceRS;
delayMicroseconds(100);
i++;
  } while (i<=4);  

    delay(500);
    Serial.print("New Set Of Readings--- ");    // This set of code simply output the data values to the computer instead of say LCD screen. 
    Serial.print("  Rs1-  "); Serial.print(ArraySizeRS[0]);
        Serial.print("  Rs2-  "); Serial.print(ArraySizeRS[1]);
            Serial.print("  Rs3-  "); Serial.print(ArraySizeRS[2]);
                Serial.print("  Rs4-  "); Serial.print(ArraySizeRS[3]);
                    Serial.print("  Rs5-  "); Serial.print(ArraySizeRS[4]);
                    Serial.print("  RsTOT "); Serial.print(ArraySizeRS[i]);
                        Serial.print("  Rs6-  "); Serial.print(ArraySizeRS[5]);
                        Serial.print("  Rs7-  "); Serial.print(ArraySizeRS[6]);
                        Serial.print("  Rs8-  "); Serial.print(ArraySizeRS[7]);
                        Serial.print("  Rs9-  "); Serial.print(ArraySizeRS[8]);
                        Serial.print("  Rs10-  "); Serial.print(ArraySizeRS[9]);
                        
    Serial.println(" ");
}


