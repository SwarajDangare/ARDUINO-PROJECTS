//*****UART_MASTER*****
//COM 3

int button = 8;
int buttonState = LOW;
//int LEDState = 0;

void setup() 
{
  pinMode(button,INPUT);
  Serial.begin(9600);                 //BEGIN THE UART COMUNICATION AT BAUD RATE OF 9600
}

void loop() 
{
  buttonState = digitalRead(button);
  if(buttonState == HIGH)
  {
    Serial.write('1');                //SEND/WRITE DATA 
    //LEDState = 1;
  }
  else
  {
    Serial.write('0');               //SEND/WRITE DATA
    //LEDState = 0;
  }
  
  //Serial.write(LEDState);
  //Serial.println(buttonState);
  delay(100);
}
