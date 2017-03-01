// Simple Web client example
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

char ssid[] = "********";           // your network SSID (name)
char pass[] = "********";           // your network password (use for WPA, or use as key for WEP)
char server[] = "www.google.co.uk";   // name address for Google (using DNS)
int port = 80;

WiFiClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  Serial.println("Connected to wifi");
  Serial.println("\nStarting connection to server...");
  if (client.connect(server, port)) {
    client.println("GET /search?q=how+far+to+the+moon& HTTP/1.1");    // Make a HTTP request:
    client.println("Host: www.google.co.uk");
    client.println("Connection: close");
    client.println();
  }
}

void loop() {
  while (client.available()) {// if there are incoming bytes availableread them and print them:
    char c = client.read();
    Serial.write(c);
    if (c=='\n' || c=='\r') Serial.println();
  }
}






