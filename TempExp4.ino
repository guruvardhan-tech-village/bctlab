// Aim: To measure temperature using LM35 sensor. 
// Components: Arduino UNO, LM35. 
// Circuit: LM35 output to A0, Vcc to 5V, GND to GND. 
// Program: 
int tempPin = A0; 
float tempC; 
void setup() { 
Serial.begin(9600); 
} 
void loop() { 
int val = analogRead(tempPin); 
tempC = (val * 5.0 * 100.0) / 1024; 
Serial.print("Temperature: "); 
Serial.print(tempC); 
Serial.println(" °C"); 
delay(1000); 
} 

// RESULT: Temperature displayed on serial monitor. 
