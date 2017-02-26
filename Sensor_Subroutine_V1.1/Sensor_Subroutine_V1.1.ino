const int trigPinx = x;
const int echoPinx = x;

long durationx;
int distancex;

void loop()
{
 UltrasoincSesnorX();
 Serial.print("X-"); Serial.print(distanceX);
}


void UltrasoincSesnorX()
{
digitalWrite(trigPinX, LOW);
delayMicroseconds(2);
digitalWrite(trigPinX, HIGH);
delayMicroseconds(10);
digitalWrite(trigPinX, LOW);
durationX = pulseIn(echoPinX, HIGH);
distanceX = durationX*0.034/2;
delayMicroseconds(100);
}
void setup()
{
  Serial.begin (9600); 
pinMode(trigPinX, OUTPUT);
pinMode(echoPinX, INPUT);
}
