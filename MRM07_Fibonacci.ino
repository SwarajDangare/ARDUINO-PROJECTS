
int lastNum1=0,lastNum2=1,sum=0;          //VARIABLE TO STORE PREVIOUS NUMBERS
int count=1;                              //COUNTER FOR SERIAL NUMBER

#define button = 2;
int buttonState = LOW;
int lastState = LOW;

#define LED = 8;

void setup() 
{
  pinMode(button,INPUT);
  pinMode(LED,OUTPUT);

  Serial.begin(9600);
  Serial.println("FIBONACCI SERIES");
  Serial.println();
}



int GlowLED(int numOfGlow)               //GLOW THE LED FIBONACCI NUMBER OF TIME
{
  for(int i=0;i<numOfGlow;i++)
    {
      digitalWrite(LED,HIGH);
      delay(300);
      digitalWrite(LED,LOW);
      delay(300);
    }
}


void loop() 
{
  
  buttonState=digitalRead(button);
  
  if(buttonState==HIGH && lastState==LOW)
  {
    Serial.print(count);                    //PRINT THE SERIAL OF FIBONACCI NUMBER
    Serial.print("- Fibonacci number : ");
    Serial.println(lastNum1);               //PRINT FIBONACCI NUMBER
    
    GlowLED(lastNum1);                      //GLOW THW LED
    
    sum=lastNum1+lastNum2;                  //CALCULATE THE NEXT NUMBER
    lastNum1=lastNum2;                      
    lastNum2=sum;                           //UPDATE THE PREVIOUS NUMBERS

    count++;                                //UPDATE THE SERIAL COUNTER
    
    lastState=buttonState;
  }
  
  lastState=buttonState;
}
