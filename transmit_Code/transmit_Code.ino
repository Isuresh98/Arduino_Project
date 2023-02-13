#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <DHT.h>

const int CE_pin = 7;
const int CSN_pin = 8;
const int DHT_pin = 3;

RF24 radio(CE_pin, CSN_pin);
DHT dht(DHT_pin, DHT11);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  String data = "T:" + String(temperature, 1) + ",H:" + String(humidity, 1);

  radio.write(data.c_str(), data.length() + 1);
  Serial.println("Sent: " + data);
  delay(1000);
}
