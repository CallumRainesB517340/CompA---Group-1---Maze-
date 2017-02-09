    #define trigPin1 3  // Defines each pin from the board for wiring up physical connections. 
    #define echoPin1 2
    #define trigPin2 4
    #define echoPin2 5
    #define trigPin3 7
    #define echoPin3 8

    long duration, distance, RightSensor,FrontSensor,LeftSensor; // Defines the variables that will be used within the code, can be named anything
    void setup()
    {
    Serial.begin (9600); // Sets the data rate in bits per second 
    pinMode(trigPin1, OUTPUT);
    pinMode(echoPin1, INPUT); // declares what ech pin is in terms of I/O
    pinMode(trigPin2, OUTPUT);
    pinMode(echoPin2, INPUT);
    pinMode(trigPin3, OUTPUT);
    pinMode(echoPin3, INPUT);
    }

    void loop() {       // This loop cycles trough each of the sensors with a small delay to obtain values for each
    SonarSensor(trigPin1, echoPin1);
    RightSensor = distance;
    delay(500);
    SonarSensor(trigPin2, echoPin2);
    LeftSensor = distance;
    delay(500); // The delay is needed to reduce echo, can be set as low as 30ms but recomended that 50 is used. 
    SonarSensor(trigPin3, echoPin3);
    FrontSensor = distance;
    delay(500);

    Serial.print(" ---New Set Of Readings--- ");    // This set of code simply output the data values to the computer instead of say LCD screen. 
    Serial.print("Ls-"); Serial.print(LeftSensor);
    Serial.print("Fs-"); Serial.print(FrontSensor);
    Serial.print("Rs-"); Serial.print(RightSensor);
    Serial.println(" ");
    }

    void SonarSensor(int trigPin,int echoPin)
    {
    digitalWrite(trigPin, LOW); // Sets the pin low to make sure it is clear for the next instructions. 
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); // Requires the trig pin to be set high for 10us so that it can trigger. Look on data sheet for more details. 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;  // This is the math to work out distance. 

    }

