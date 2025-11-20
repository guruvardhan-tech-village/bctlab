// Aim: To control relay module using Arduino. 
// Components: Arduino UNO, Relay module, LED/load. 
// Circuit: Relay IN -> Pin 7, VCC -> 5V, GND -> GND. 
// Program: 
int relay = 7; 
void setup() { 
pinMode(relay, OUTPUT); 
} 
void loop() { 
digitalWrite(relay, HIGH); 
delay(2000); 
digitalWrite(relay, LOW); 
delay(2000); 
}

// RESULT: Relay toggles ON and OFF every 2 seconds. 
