// Aim: To control motor direction using Arduino and L293D. 
// Components: Arduino UNO, L293D, DC motor. 
// Program: 
int in1 = 7; 
int in2 = 8; 
void setup() { 
pinMode(in1, OUTPUT); 
pinMode(in2, OUTPUT); 
} 
void loop() { 
digitalWrite(in1, HIGH); 
digitalWrite(in2, LOW); 
delay(2000); 
digitalWrite(in1, LOW); 
digitalWrite(in2, HIGH); 
delay(2000); 
} 

// RESULT: Motor changes direction every 2 seconds.
