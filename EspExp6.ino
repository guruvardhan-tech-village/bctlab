// Aim: To send/receive data from web server using Arduino and ESP8266. 
// Components: Arduino UNO, ESP8266 module. 
// Program: 
#include <SoftwareSerial.h> 
SoftwareSerial esp(2, 3); 
void setup() { 
Serial.begin(9600); 
esp.begin(115200); 
Serial.println("Sending HTTP GET request..."); 
esp.println("AT+CIPSTART="TCP","example.com",80"); 
delay(2000); 
esp.println("AT+CIPSEND=50"); 
delay(1000); 
esp.println("GET /testdata HTTP/1.1\r\nHost: example.com\r\n\r\n"); 
} 
void loop() {} 


// RESULT: Arduino communicates with server via ESP8266.
