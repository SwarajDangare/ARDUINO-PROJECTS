//****I2C_SLAVE****
//COM 7

#include <Wire.h>          // Include Arduino Wire library for I2C


#define SLAVE_ADDR 8       // Define Slave I2C Address

int LED = 8;

int slaveReceived;         // Variable for received data

void setup() 
{
  pinMode(LED, OUTPUT);

  Wire.begin(SLAVE_ADDR);         // Initialize I2C communications as Slave
  Wire.onReceive(receiveEvent);   // Function to run when data received from master

  Serial.begin(9600);

}


void receiveEvent() 
{
    slaveReceived = Wire.read();   // read one character from the I2C
}

void loop() 
{  
  if (slaveReceived == HIGH) 
  {
    digitalWrite(LED, HIGH);   
  } 
  else                              //ccheck for led state and update led
  {
    digitalWrite(LED, LOW);
  }
  Serial.println(slaveReceived);
  delay(100);

}
