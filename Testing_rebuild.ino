#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "Blynk.h"
#include <SimpleTimer.h>
#include <TimeLib.h>


SimpleTimer timer;

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, server);
  serverConnect();

  timer.setInterval(30000L, reconnectBlynk);  // check every 30s if still connected to server 
  }

void loop() {
  if (Blynk.connected()) {
    Blynk.run();
  }

  timer.run();
};
