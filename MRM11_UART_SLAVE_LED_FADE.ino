//*****SLAVE*****
//COM 7
#include <SoftwareSerial.h>  //INCLUDE SOFTWARE SERIAL TO CHANGE rx & tx PINS
SoftwareSerial serial(2,3);  // (RX,TX)

#define LED = 9;
int fade;
void setup() 
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);      //BEGIN SERIAL COM FOR SHOWING DATA
  serial.begin(9600);      //BEGIN THE UART COMUNICATION AT BAUD RATE OF 9600
}

void loop() 
{  
  if (serial.available() >0)  //CHECK IF DATA IS RECIVED
  {
    fade = serial.read();     //READ THE FADE VALUE
    
    analogWrite(LED, fade);   //UPDATE THE LED VALUE
    Serial.println(fade);     //Print data on Serial Monitor
    
    delay(10);
  }
}
