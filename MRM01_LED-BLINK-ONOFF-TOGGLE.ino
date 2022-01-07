int button1=5;
int button2=4;                     //DECLARE ALL BUTTON PIN
int button3=3;

int button1State = 0;
int button2State = 0;              //DECLARE ALL BUTTONSTATE
int button3State = 0;

int last3State = LOW;              //LAST STATE OF BUTTON 3(TOGGLE)

int a=0;                           //TO REMEMBER THE STATE OF ON-OFF
                       
int state=LOW;                     //TO REMEMBER THE STATE OF TOGGLE 
int prev=0;

void setup()
{
  pinMode(2, OUTPUT);                  //DECLARE LED OUTPUT
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);             //DECLARE ALL BUTTON AS OUTPUT
  pinMode(button3, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
    
  button1State = digitalRead(button1);
  button2State = digitalRead(button2);    //READ ALL BUTTON STATES
  button3State = digitalRead(button3);
  
  Serial.print(button1State);
  Serial.print(button2State);
  Serial.println(button3State);
  
//---------------------------------------------------------
  
  if(button1State == HIGH)
    {
    digitalWrite(2, HIGH);
    delay(500);                            //LED BLINK
    digitalWrite(2, LOW);
    delay(500);
    }
  
//----------------------------------------------------------  
  
  if(button2State == HIGH)
    {
    digitalWrite(2, HIGH);
    a=1; 
    }                                      //LED ON-OFF
  else if (button2State == LOW && a==1)
    {
    digitalWrite(2, LOW);
     a=0; //used it because the loop didt'n understand for which button to led has to go low

    }

//---------------------------------------------------------- 
  
  if(last3State == HIGH && button3State == LOW )
  {
    state = (state == HIGH) ? LOW: HIGH;//to check the current state of led     
    digitalWrite(2, state);                  //LED TOGGLE
    
    /*if(prev == 0)
    {
      digitalWrite(2,HIGH);
      prev =1;
    }
    else if(prev == 1)
    {
      digitalWrite(2,LOW);                
      prev = 0;
    }*/
    
    }
  last3State = button3State;            //REMEMBER THE LAST STATE OF BUTTON 
  
  
  delay(100);//to make arduino stable
}
