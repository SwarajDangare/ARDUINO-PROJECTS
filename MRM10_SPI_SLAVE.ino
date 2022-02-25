//****SLAVE****
//COM 7

#include<SPI.h>           // INCLUDE THE SPI LIBRARY      
#define LED 8

volatile boolean received;
volatile byte SlaveReceived;

void setup()

{
  Serial.begin(9600);
   
  pinMode(LED,OUTPUT);               
  pinMode(MISO,OUTPUT);                  

  SPCR |= _BV(SPE);                  
  received = false;

  SPI.attachInterrupt();                  
  
}

ISR (SPI_STC_vect)                        
{
  SlaveReceived = SPDR;         
  received = true;                        
}

void loop()
{  
 if(received)                           
   {
      if (SlaveReceived==1) 
      {
        digitalWrite(LED,HIGH);       
      }
      else
      {
        digitalWrite(LED,LOW);          
      }
                             
  delay(100);
}
}
