#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {
// put your setup code here, to run once:
BTSerial.begin(38400);
Serial.begin(38400);
Serial.println("Received from HC-05: ");
}

void loop() {
// put your main code here, to run repeatedly:
if (BTSerial.available())
{
Serial.print((char)BTSerial.read());
}

if (Serial.available())
{
BTSerial.write(Serial.read());
}
}
