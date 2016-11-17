
// Variable that define the pin number, controlling each LED’s outputs
int ledPin1 = 5;
int ledPin2 = 2;


//Variables that define the pin number, controlling each Button’s inputs
int switchPin1 = 8;
int switchPin2 = 10;
int switchPin3 = 12;


//Variable that keeps track of the state that each LED is in throughout the program.
boolean ledOn1 = LOW;
boolean ledOn2 = LOW;


//Keeps track of the state that the buttons are in throughout the program. 
boolean switchMode1 = LOW;
boolean switchMode2 = LOW;
boolean switchMode3 = LOW;


unsigned long randnumber; //Stores a random number that controls how long the program waits to light up an LED 


unsigned long minrandnumber = 2000; //Defines  the min/max range of the random numbe
unsigned long maxrandnumber = 5000;


unsigned long time1; //Keep track of the time when the LED lights up each time
unsigned long time2; //Keeps track of the time when the button corresponding to each LED is pressed.


unsigned long time3; //Keeps track of the time from when the LED lights up to when the button is pressed.


void setup()
{
  pinMode(ledPin1, OUTPUT);//sets led pins to output 
  pinMode(ledPin2, OUTPUT);
  
  pinMode(switchPin1, INPUT);//sets buttons pints to input 
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);

  Serial.begin(9600); //initializes serial monitor 

  Serial.println("Welcome to the Reaction Time Tester!"); //print statements that interact with the users 
  Serial.println("Press Button 1 when you're ready to begin the Test");
}


void loop() 
{
boolean start = digitalRead(switchPin1);// creates a boolean variable that keeps track of the state of button that initializes the program
 
if (start == HIGH) //Checks if a button is pressed to initialize the program 


{
  Serial.println("Button 1 Pressed Initializing Test"); //print statement that tells user button press has been registered 
  //delay(500); 

  randnumber = random(minrandnumber,maxrandnumber);
  Serial.println(randnumber);
  delay(randnumber); 
  
  if ( randnumber> 3500) //Determines whether LED 1 lights up or LED 2 lights up
  {
    Serial.println("LED 1 Turning ON");
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, LOW);
    
    time1 = millis(); //Keep track of the time when the LED lights up each time


    while(switchMode2 == LOW)
    {
      switchMode2 = digitalRead(switchPin2);
    }
    
    time2 = millis();//Keeps track of the time when the button corresponding to each LED is pressed.
    time3 = time2-time1; //Keeps track of the time from when the LED lights up to when the button is pressed. 
    
    Serial.println("Your reaction is");
    Serial.println(time3);
    Serial.println("milliseconds");
    
    switchMode2 = LOW;
    
    Serial.println("Press button 1 to test again! :)");
    
  }


  else ///Determines whether LED 1 lights up or LED 2 lights up
  {
    Serial.println("LED 2 Turning ON");
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin1, LOW);
    
    time1 = millis(); // Keep track of the time when the LED lights up each time


    while(switchMode3 == LOW)
    {
      switchMode3 = digitalRead(switchPin3);
    }
    
    time2 = millis();//Keeps track of the time when the button corresponding to each LED is pressed.
    time3 = time2-time1; //Keeps track of the time from when the LED lights up to when the button is pressed. 
    
    Serial.println("Your reaction is");
    Serial.println(time3); 
    Serial.println("milliseconds");
    
    switchMode3 = LOW;
    
    Serial.println("Press button 1 to test again! :)");
  }
}

//updates the variable 
start= LOW; 
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin2, LOW); 
}