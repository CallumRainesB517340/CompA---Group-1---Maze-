

int T;
void setup()
{
  Serial.begin (9600);
}

void loop()
{

  T = 2;

  if ( T == 2 )
  {
    T --;
  }
  
  else
  {
    T++;
  }

  Serial.print(" T = "); 
  Serial.print(T);
    Serial.println("  ");
}





