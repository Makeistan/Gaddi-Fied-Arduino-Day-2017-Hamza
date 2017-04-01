
String voice;

//Initialize Motor 1
int motor1Pin1 = 2;
int motor1Pin2 = 3;
int enable1Pin = 9;
 
//Initialize Motor 2
int motor2Pin1 = 5; 
int motor2Pin2 = 6; 
int enable2Pin = 10;

void setup() {
    // sets the pins as outputs:
    
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 

  if(voice == "*forward") {
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      analogWrite(enable1Pin, 180);
      analogWrite(enable2Pin, 180);
      Serial.println("Forward");} 

  else if (voice == "*left")  // left
    {
      //turn left
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enable1Pin, 250);
        analogWrite(enable2Pin, 250);
        
        delay(150);
        
        voice == "*stop";
        Serial.println("left");
    }
    
    else if (voice == "*stop") //  Stop
    {
        digitalWrite(enable1Pin, 0);
        digitalWrite(enable2Pin, 0);
        delay(300);
        Serial.println("stop");
    }
 
    else if (voice == "*right") // right
    {
      //TURN RIGHT
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enable1Pin, 250);
        analogWrite(enable2Pin, 250);
        
        delay(150);
        
        voice == "*stop";
        
        Serial.println("right");
      
    }
    
    else if (voice == "*reverse") //reverse
    {
        
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enable1Pin, 180);
        analogWrite(enable2Pin, 180);
        
        Serial.println("reverse");
    }
    voice="";}}
  
