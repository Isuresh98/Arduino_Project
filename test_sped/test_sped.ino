
int motorSpeed = 150; // initial motor speed
int command;
void setup() {
pinMode(2, OUTPUT); //1st motor
pinMode(3, OUTPUT); //1st motor
pinMode(5, OUTPUT); //2nd motor
pinMode(6, OUTPUT); //2nd motor

Serial.begin(9600); // Initialize serial communication for debugging
 
}

void loop() {if (Serial.available() > 0) { // Check if there is incoming data from Bluetooth module
     command = Serial.read(); // Read the incoming data

    // execute the corresponding function based on the command
    switch (command) {
      case '1':
        forward();
        break;
      case '2':
        backward();
        break;
      case '3':
        left();
        break;
      case '4':
        right();
        break;
      case '5':
        stopm();
        break;
      default:
        break;
    }
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
analogWrite(2, motorSpeed);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
analogWrite(6, motorSpeed);
}

void right() {
digitalWrite(2, LOW);
analogWrite(3, motorSpeed);
analogWrite(5, motorSpeed);
digitalWrite(6, LOW);
}

void stopm() {
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(5, LOW);
digitalWrite(6, LOW);
}
