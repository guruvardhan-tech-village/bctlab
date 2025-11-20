// Aim: To measure distance using HC-SR04 and upload to Google Cloud. 
// Components: Arduino UNO, HC-SR04, ESP8266. 
// Program : 
#include <ESP8266WiFi.h> 
const char* ssid = "YourWiFi"; 
const char* password = "YourPass"; 
const char* host = "script.google.com"; 
#define trig 9 
#define echo 10 
void setup() { 
Serial.begin(115200); 
WiFi.begin(ssid, password); 
while (WiFi.status() != WL_CONNECTED) delay(500); 
pinMode(trig, OUTPUT); 
pinMode(echo, INPUT); 
} 
void loop() { 
digitalWrite(trig, LOW); 
delayMicroseconds(2); 
digitalWrite(trig, HIGH); 
delayMicroseconds(10); 
digitalWrite(trig, LOW); 
long duration = pulseIn(echo, HIGH); 
int distance = duration * 0.034 / 2; 
WiFiClient client; 
if (client.connect(host, 80)) { 
String url = String("/macros/s/YourScriptID/exec?distance=") + distance; 
client.print(String("GET ") + url + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n"); 
} 
delay(10000); 
} 

// RESULT: Distance uploaded to Google Sheet via cloud.
