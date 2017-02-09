
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
int avergae; 
int mode;

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
digitalWrite(trigPinLS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinLS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinLS, LOW);
durationLS = pulseIn(echoPinLS, HIGH);
distanceLS = durationLS*0.034/2;
ArraySizeLS[i]= distanceLS;

delayMicroseconds(100);
 
digitalWrite(trigPinFS, LOW);
delayMicroseconds(2);
digitalWrite(trigPinFS, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinFS, LOW);
durationFS = pulseIn(echoPinFS, HIGH);
distanceFS = durationFS*0.034/2;
ArraySizeFS[i]=distanceFS;
delayMicroseconds(100);
 
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
int mode = ArraySizeLS[i];
    Serial.print(" ---New Set Of Readings--- ");    // This set of code simply output the data values to the computer instead of say LCD screen. 
    Serial.print("Ls-"); Serial.print(mode);
    Serial.print("Fs-"); Serial.print(ArraySizeFS[i]);
    Serial.print("Rs-"); Serial.print(ArraySizeRS[i]);
    Serial.println(" ");
}


