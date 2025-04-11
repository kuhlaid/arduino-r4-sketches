/*
This sketch simply outputs the MAC (hardware) address of the device to the serial monitor. Useful if you need the address to register an R4 with DHCP.
Code courtesy of https://forum.arduino.cc/t/finding-the-mac-address-of-the-arduino-uno-r4/1308027/7
*/
#include <WiFiS3.h>

void setup() {

  Serial.begin(115200);
  while (!Serial) ;
  Serial.println("START");

  WiFi.begin("dummy");

  uint8_t mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC Address: ");
  printMacAddress(mac);
}

void loop() {
}

void printMacAddress(byte mac[]) {
  for (int i = 0; i < 6; i++) {
    if (i > 0) {
      Serial.print(":");
    }
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
  }
  Serial.println();
}
