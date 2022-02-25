
#define button = 2;

int buttonState = LOW;
int lastState = LOW;         

int num=0;                       //COUNTER FOE DECIMAL
int ledState[3]={0};             //3 LED'S STATE ARRAY


void setup() 
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  
  pinMode(button,INPUT);
    
  Serial.begin(9600);

}

int DecToBinaryLED(int a)         //CONVERT DECIMAL TO BNARY FOR LED TO READ 
{
  for(int i=0;i<3;i++)
  {
    if(a%2==1)
    ledState[i]=1;
    else
    ledState[i]=0;
    
    a=a/2; 
  }
  return;
}


void loop()
{

  buttonState= digitalRead(button);
  
   while(buttonState==HIGH && lastState==LOW)
    {    

      DecToBinaryLED(num);                           
      
      Serial.print  ("Number : ");
      Serial.println(num);
      Serial.print  ("Binary : ");
      Serial.print  (ledState[2]);               //SERIAL PRINT ALL INFO
      Serial.print  (ledState[1]);
      Serial.println(ledState[0]);

      digitalWrite(10,ledState[2]);
      digitalWrite( 9,ledState[1]);              //SET LED STATE
      digitalWrite( 8,ledState[0]);

      num++;                                     
      if(num==8)                                 //INCREMENT DECIMAL NUMBER TILL 8 AND START OVER
      {
        num=0;
        break;
      } 

      lastState=buttonState;
    }

  lastState=buttonState;                          //UPDATE BUTTONSTATE
  delay(15);

}
