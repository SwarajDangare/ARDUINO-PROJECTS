//****I2C_MASTER****
//COM 3

#include <Wire.h>          // Include Arduino Wire library for I2C

#define SLAVE_ADDR 8       // Define Slave I2C Address

#define button = 8;
int buttonState = 0;


void setup() 
{
  pinMode(button,INPUT);
  
  Wire.begin();            // Initialize I2C communications as Master

}

void loop() 
{
  buttonState = digitalRead(button);

  Wire.beginTransmission(SLAVE_ADDR);  // Begin the comunication with slave address
  Wire.write(buttonState);             // Write a charatre to the Slave
  Wire.endTransmission();              // End the comunication 
  
  delay(100);

}
