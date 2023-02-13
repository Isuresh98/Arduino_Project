#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9); // RX, TX

void setup() {
  pinMode(2,OUTPUT);//1st moter 
  pinMode(3,OUTPUT);//1st moter 
  pinMode(5,OUTPUT);//2nd moter 
  pinMode(6,OUTPUT);//2nd moter 
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available()) {
    char data = BTSerial.read();
    switch (data) {
      case 'f': // Forward
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        break;
      case 'b': // Backward
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        break;
      case 'l': // Left
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        break;
      case 'r': // Right
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        break;
      case 's': // Stop
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(5, LOW);
        digitalWrite(6, LOW);
        break;
    }
  }
}
