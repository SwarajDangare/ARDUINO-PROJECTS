
int buttonPin = 8;    
int ledPin = 12; 
     
int ledState = LOW;        
int buttonState;             
int lastButtonState = LOW;   
int wait = 50;   

unsigned long buttonPressedTime;
unsigned long currentTime;

void setup() {
  
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
  
  buttonState = digitalRead(buttonPin);
  currentTime =millis();

  if (buttonState == HIGH && lastButtonState==LOW) 
  {
    buttonPressedTime = currentTime;
    Serial.println(buttonPressedTime);
  }
  
  if ((currentTime - buttonPressedTime) >= wait)  
  {
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) 
      {
        ledState = !ledState;
        Serial.println(ledState);
  
      }
  }
  digitalWrite(ledPin, ledState);

  lastButtonState = buttonState;
}
