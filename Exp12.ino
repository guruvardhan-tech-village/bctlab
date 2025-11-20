// Aim: To create a simple sensor-based IoT system. 
// Example: Smart street light using LDR. 
// Program: 
int ldr = A0; 
int led = 13; 
int value; 
void setup() { 
pinMode(led, OUTPUT); 
Serial.begin(9600); 
} 
void loop() { 
value = analogRead(ldr); 
if (value < 300) 
digitalWrite(led, HIGH); 
else 
digitalWrite(led, LOW); 
delay(500); 
} 

// RESULT: LED turns ON in dark and OFF in light.
