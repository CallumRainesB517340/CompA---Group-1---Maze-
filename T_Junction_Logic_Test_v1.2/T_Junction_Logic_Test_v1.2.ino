

int T;
int X=1;
void setup()
{
  Serial.begin (9600);
}

void loop()
{

  if ( X == 1 )
  {
    T++;
  }
  
  else
    {
      T--;
    }

Serial.print(" T = ");
Serial.print(T);
Serial.println("  ");
}





