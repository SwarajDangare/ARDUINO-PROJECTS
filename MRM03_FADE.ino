
int brightness=0;              //DELAY VARIABLE
int LED=11;                    //LED PIN

void setup()
{
  pinMode(LED, OUTPUT);        // LED OUTPUT 
  pinMode(A0, INPUT);          // POTENTIOMETER INPUT
  
  Serial.begin(9600);
  Serial.print("Brightness");
}

void loop()
{
  for(brightness=0 ; brightness<255 ; brightness++)                                 
  {
    
    analogWrite(LED,brightness);        // INBUILT PWM //TO CONTROLE THE BRIGHTNESS LOW-TO-HIGH
    Serial.println(brightness);
  }
  
  for( ; brightness>0 ; brightness--)                                 
  {
    analogWrite(LED,brightness);        // INBUILT PWM //TO CONTROLE THE BRIGHTNESS HIGH-TO-LOW
    Serial.println(brightness);       
  }
  
  
}
