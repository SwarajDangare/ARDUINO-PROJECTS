
int wait=0;               //DELAY VARIABLE
int LED=12;               //LED PIN

void setup()
{
  pinMode(LED, OUTPUT);   // LED OUTPUT 
  pinMode(A0, INPUT);     // POTENTIOMETER INPUT
  
  Serial.begin(9600);
  Serial.print("Brightness");
}

void loop()
{
  wait= analogRead(0);     //READ THE INPUT OF POTENTIOMETER
  
  //Serial.print(wait);
  //Serial.print("    ");
  
  wait= map(wait,200,1000,1,10);    //map the input value to 1-10 milisecond                                
  
//USING PWM TO CONTROLE BRIGHTNESS

  digitalWrite(LED,HIGH);             
  delay(wait);                    //DUTYCYCLE
  
  digitalWrite(LED,LOW);
  delay(10-wait);                //OFF TIME
  
  
  //Serial.println(wait);
  
}
