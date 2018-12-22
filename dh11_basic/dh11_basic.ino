
#include <SimpleDHT.h>

/*
   Basic demo of DH11.
   Uses v1.3.0 of the Adafruit DHT library
   Refer to: https://learn.adafruit.com/dht
*/

#define DHTPIN 8

SimpleDHT11 dht11(DHTPIN);

uint32_t delayMS;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(10000);

  byte h = 0;
  byte t = 0;

  int err;

  if ((err = dht11.read(&t, &h, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("DHT11 error: ");
    Serial.print(err);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.print("Humidity: ");
    Serial.print((int) h);
    Serial.print(" %\n");
    Serial.print("Temperature: ");
    Serial.print((int) t);
    Serial.print(" *C\n");
  }
}
