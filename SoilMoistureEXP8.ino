// Aim: To measure soil moisture and post to Firebase. 
// Components: Arduino UNO, Soil sensor, ESP8266. 
// Program : 
#include <ESP8266WiFi.h> 
#include <FirebaseESP8266.h> 
#define WIFI_SSID "YourWiFi" 
#define WIFI_PASSWORD "YourPass" 
#define FIREBASE_HOST "yourproject.firebaseio.com" 
#define FIREBASE_AUTH "YourFirebaseAuth" 
FirebaseData fbData; 
int sensorPin = A0; 
void setup() { 
Serial.begin(115200); 
WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 
} 
void loop() { 
int moisture = analogRead(sensorPin); 
Firebase.setInt(fbData, "/SoilMoisture", moisture); 
delay(5000); 
}

// RESULT: Moisture value visible on Firebase cloud.
