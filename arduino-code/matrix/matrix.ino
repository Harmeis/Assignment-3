#include "config.h"

AdafruitIO_Feed *Light = io.feed("light");
int luminosite;

void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  io.run();

  luminosite = analogRead(A2);

  Serial.print("sending -> ");
  Serial.println(luminosite);
  Light->save(luminosite);

  delay(3000);

}
