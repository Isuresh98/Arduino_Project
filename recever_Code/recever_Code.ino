#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int CE_pin = 7;
const int CSN_pin = 8;

RF24 radio(CE_pin, CSN_pin);

const byte address[6] = "00001";

char receivedMessage[32];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&receivedMessage, sizeof(receivedMessage));
    Serial.print("Received: ");
    Serial.println(receivedMessage);
  }
}
