/**
 * @file wifi.ino
 * @author Revant Koriya (revant.koriya.dev@gmail.com)
 * @brief This is a simple code to test the wifi connection of your esp8266.
 * @version 0.1
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <ESP8266WiFi.h>  // Include the Wi-Fi library for ESP8266

// Replace with your network credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
  // Start the Serial communication
  Serial.begin(115200);
  delay(10);

  // Begin Wi-Fi connection attempt
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  // Verbose output during the connection attempt
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    retries++;
    if (retries > 20) {  // Fail after 10 seconds
      Serial.println("\nFailed to connect to WiFi");
      return;
    }
  }

  // On successful connection
  Serial.println("\nConnected to WiFi!");
  Serial.print("SSID: ");
  Serial.println(ssid);
  Serial.print("Password: ");
  Serial.println(password);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Put your main code here, to run repeatedly
}
// @note :  you can retry connecting using the reset button on the board.