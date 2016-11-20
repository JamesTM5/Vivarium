#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_PRINT Serial 
#define server "blynk.cloud-com"
//#define server "192.168.0.12"
char auth[] = "86dc4118de9842ba99b611b61c1c2276";
char ssid[] = "virginmedia6125068";
char pass[] = "jnaascuw";


void reconnectBlynk() {
  Serial.print("Checking connection");
  if (!Blynk.connected()) {
    if(Blynk.connect()) {
      BLYNK_LOG("Reconnected");
    } else {
      BLYNK_LOG("Not reconnected");
    }
  }
}

void serverConnect() {
  int mytimeout = millis() / 1000;
  while (Blynk.connect() == false) { // try to connect to server for 10 seconds
    if((millis() / 1000) > mytimeout + 8){ // try local server if not connected within 9 seconds
       break;
    }
  }
}
