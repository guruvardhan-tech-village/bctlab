// Aim: To detect light intensity using LDR. 
// Components: Arduino UNO, LDR, 10kΩ resistor. 
// Circuit: LDR and resistor form voltage divider connected to A0. 
// Program: 
int ldrPin = A0; 
int ldrValue = 0; 
void setup() { 
Serial.begin(9600); 
} 
void loop() { 
ldrValue = analogRead(ldrPin); 
Serial.println(ldrValue); 
delay(500); 
} 

// RESULT: LDR readings decrease with more light.
