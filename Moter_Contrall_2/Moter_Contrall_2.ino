int motorSpeed = 200; // initial motor speed

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
  case 'i':
    increaseSpeed();
    break;
  case 'd':
    decreaseSpeed();
    break;
  default:
    break;
}
}
}

void forward() {
analogWrite(2, motorSpeed);
digitalWrite(3, HIGH);
analogWrite(5, motorSpeed);
digitalWrite(6, HIGH);
}

void backward() {
digitalWrite(2, HIGH);
analogWrite(3, motorSpeed);
digitalWrite(5, HIGH);
analogWrite(6, motorSpeed);
}

void left() {
digitalWrite(2, HIGH);
analogWrite(3, motorSpeed);
digitalWrite(5, LOW);
analogWrite(6, motorSpeed);
}

void right() {
analogWrite(2, motorSpeed);
digitalWrite(3, HIGH);
analogWrite(5, motorSpeed);
digitalWrite(6, LOW);
}

void stopm() {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
}

void increaseSpeed() {
if (motorSpeed < 255) {
motorSpeed += 25;
}
}

void decreaseSpeed() {
if (motorSpeed > 55) {
motorSpeed -= 25;
}
}
