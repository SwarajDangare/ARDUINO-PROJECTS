//*****SLAVE*****
//COM 7

int LED = 8;
char LEDState;

void setup() 
{
  pinMode(LED,OUTPUT);
  Serial.begin(9600);            //BEGIN THE UART COMUNICATION AT BAUD RATE OF 9600
}

void loop() 
{  
  if (Serial.available())        //CHECK IF DATA IS RECIVED
  {
    LEDState = Serial.read();    //READ THE INCOMING DATA AND SAVE IT
    if (LEDState == '1') 
    digitalWrite(LED, HIGH);     // SWITCH LED ON
    if (LEDState == '0') 
    digitalWrite(LED, LOW);
    
    Serial.println(LEDState);    //PRINT DATA ON SERIAL MONITOR
    delay(100);
  }
}
