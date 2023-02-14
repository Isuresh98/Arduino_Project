


void setup() {
pinMode(2, OUTPUT); //1st motor
pinMode(3, OUTPUT); //1st motor
pinMode(5, OUTPUT); //2nd motor
pinMode(6, OUTPUT); //2nd motor
char command;
Serial.begin(9600); //Initialize serial communication
}

void loop() {
if (Serial.available()>0) { //Check if there is incoming data
char command = Serial.read(); //Read the incoming data

// execute the corresponding function based on the command
switch (command) {
  case 'f':
    forward();
    break;
  case 'b':
    backward();
    break;
  case 'l':
    left();
    break;
  case 'r':
    right();
    break;
     case 's':
    stopm();
    break;
  default:
    break;
}



}//if
}//loop

void forward() {
digitalWrite(2, LOW);
analogWrite(3, HIGH);
digitalWrite(5, LOW);
analogWrite(6, HIGH);
}

void backward() {
analogWrite(2, HIGH);
digitalWrite(3, LOW);
analogWrite(5, HIGH);
digitalWrite(6, LOW);
}

void left() {
analogWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
analogWrite(6, HIGH);
}

void right() {
digitalWrite(2, LOW);
analogWrite(3, HIGH);
analogWrite(5, HIGH);
digitalWrite(6, LOW);
}

void stopm() {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
}
