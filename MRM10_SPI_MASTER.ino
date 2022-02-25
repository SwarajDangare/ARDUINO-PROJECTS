//****MASTER****
//COM 3

#include<SPI.h>           // INCLUDE THE SPI LIBRARY      
#define button 8          

int LEDState;
int buttonState;

void setup (void)

{
  Serial.begin(9600);               
  
  pinMode(button,INPUT);                                
  
  SPI.begin();                         // BEGIN COMMUNICATION        
  SPI.setClockDivider(SPI_CLOCK_DIV8); // SET CLOCK SPEED
  digitalWrite(SS,HIGH);               // SET SLAVE PIN HIGH   
}

void loop(void)
{
  byte masterSend;                           

  buttonState = digitalRead(button); 

  if(buttonState == HIGH)                
  {
    LEDState = 1;
  }
  else                                 //SET LED STATE TO SEND
  {
    LEDState = 0;
  }
  
  digitalWrite(SS, LOW);               // SET SLAVE PIN LOW TO INITIATE COM
  
  masterSend = LEDState;                            
  SPI.transfer(masterSend);            // SEND DATA 
  
  delay(100);
}
