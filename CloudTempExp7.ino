// Aim: To post room temperature data to ThingSpeak cloud platform. 
// Components: Arduino UNO, LM35, ESP8266. 
// Program  
#include <ESP8266WiFi.h> 
const char* ssid = "YourWiFi"; 
const char* password = "YourPass"; 
const char* server = "api.thingspeak.com"; 
String apiKey = "YOUR_API_KEY"; 
int tempPin = A0; 
WiFiClient client; 
void setup() { 
Serial.begin(115200); 
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) delay(1000); 
} 
void loop() { 
float value = analogRead(tempPin) * (5.0 / 1023.0) * 100; 
if (client.connect(server, 80)) { 
String postStr = apiKey + "&field1=" + String(value) + "\r\n\r\n"; 
client.print("POST /update HTTP/1.1\nHost: api.thingspeak.com\nX-THINGSPEAKAPIKEY: " + apiKey + "\nContent-Length: " + String(postStr.length()) + "\n\n" + postStr); 
} 
delay(20000); 
} 

// RESULT: Temperature uploaded to ThingSpeak cloud. 
