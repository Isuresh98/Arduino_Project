int motorSpeed = 145; // initial motor speed
char input;
void setup() {
pinMode(2, OUTPUT); //1st motor
pinMode(3, OUTPUT); //1st motor
pinMode(5, OUTPUT); //2nd motor
pinMode(6, OUTPUT); //2nd motor
Serial.begin(9600); // Initialize serial communication for debugging
 
}

void loop(){
  if(Serial.available()){
 input= Serial.read();
    Serial.println(input);
    }
    
 if(input=='s'){
  stopm();
  }

else if(input=='f'){
  forward();
  }
else if(input=='b'){
  backward();
  }
else if(input=='r'){
    right();
  }
else if(input=='l'){
  left();
  }

    
  
  }//loop

  void forward() {
digitalWrite(2, LOW);
analogWrite(3, motorSpeed);
digitalWrite(5, LOW);
analogWrite(6, motorSpeed);
}

void backward() {
analogWrite(2, motorSpeed);
digitalWrite(3, LOW);
analogWrite(5, motorSpeed);
digitalWrite(6, LOW);
}

void left() {
analogWrite(2, 175);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
}

void right() {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
analogWrite(5, 175);
digitalWrite(6, LOW);
}

void stopm() {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
}
