int LEDPin=12;                //LED PIN
int State=0;                  //CURRENT LED STATE  
int Delay = 500;              //DELAY VARIABLE
unsigned long prevTime = 0;   //REMEMBER THE PREVIOUS TIME TO CHECK HOW MUCH TIME HAS PASSED
                              //UNSIGNED IS USED TO ONLY CONSIDER POSITIVE NUMBER 

void setup() {
  
  pinMode(LEDPin, OUTPUT);    // LED OUTPUT 
  Serial.begin(9600);         
}

void loop() {

  unsigned long currentTime = millis();

  if (currentTime - prevTime >= Delay) //TO CHECK IF DELAY TIME HAS COME
  {
    
    if (State == 0)                    //CHECK IF THE LED IS ON OR OFF
    {
      digitalWrite(LEDPin, HIGH);
      State = 1;                       //CHANGE THE LED STATE
    } 
    else                               //CHECK IF THE LED IS ON OR OFF
    {
      digitalWrite(LEDPin, LOW);
      State = 0;                       //CHANGE THE LED STATE
    }

    
    Serial.println(currentTime);       //TO SEE THE TIME
    prevTime = currentTime;            //CHANGE THE PREVIOUS TIME TO CURRENT TIME
  }
}
