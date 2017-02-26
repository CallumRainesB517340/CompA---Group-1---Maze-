

static int T = 1;


void setup()
{
  Serial.begin (9600);
}
  void loop()
  {
    if ( T == 1 )
    {

      T++;
    }

    else if (T == 2)
    {
      T--;
    }
    else
    {
      T = 6;
    }

    Serial.print(" T = ");
    Serial.print(T);
    Serial.println("  ");
  }





