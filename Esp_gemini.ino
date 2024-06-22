#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>
#include <LiquidCrystal.h>

// Wi-Fi connection information
const char* ssid = "a";
const char* password = "1234567890";
LiquidCrystal lcd(D6, D5, D1, D2, D3, D4);

// API URL and Key
const char* url = "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash-latest:generateContent?key=AIzaSyCYCkim3poZsB7po2ggAyJRFcMX6IBZoF0";

void setup() {
    lcd.begin(16, 2);  // Initialize 16x2 LCD Display
  // Start the serial communication
  Serial.begin(115200);
  delay(10);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println("...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Make HTTP POST request
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClientSecure client;
    client.setInsecure(); // Disable SSL certificate verification (use with caution)

    HTTPClient http;
    http.setTimeout(15000); // Increase timeout to 15 seconds
    http.begin(client, url); // Specify the URL with the WiFi client
    http.addHeader("Content-Type", "application/json"); // Specify content-type header

    // Define the payload (data)
    String payload = "{\"contents\":[{\"parts\":[{\"text\":\"Hi.....reply in one or two words only\"}]}]}";

    int httpResponseCode = http.POST(payload); // Send the request

    // Check the returning code
    if (httpResponseCode > 0) {
      String response = http.getString(); // Get the response to the request
      Serial.println(httpResponseCode); // Print the response code

      // Parse JSON response
      DynamicJsonDocument doc(4096);
      DeserializationError error = deserializeJson(doc, response);

      if (!error) {
        const char* text = doc["candidates"][0]["content"]["parts"][0]["text"];
        Serial.println("Parsed Text:");
        Serial.println(text);
        lcd.clear();
      lcd.print(text);
      } else {
        Serial.print("JSON deserialization failed: ");
        Serial.println(error.c_str());
      }
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }

    http.end(); // Free the resources
  }
}

void loop() {
  // Nothing to do here
}
