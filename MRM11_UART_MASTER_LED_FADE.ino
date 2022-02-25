//*****MASTER*****
//COM 3

#include <SoftwareSerial.h>  //INCLUDE SOFTWARE SERIAL TO CHANGE rx & tx PINS
SoftwareSerial serial(2,3);  // (RX,TX)

#define pot = A0;
int fade;


void setup() 
{
  pinMode(pot,INPUT);
  serial.begin(9600);      //BEGIN THE UART COMUNICATION AT BAUD RATE OF 9600
}

void loop() 
{
  fade = analogRead(pot);         // READ POTENTIAL METER VALUE    
  fade = map(fade,0,1023,0,255);  // MAP TO DESIRE VALUE
  
  serial.write(fade);             //Send fade value 
  
  delay(10);
}
