// Aim: To control an LED using a push button and Arduino. 
// Components: Arduino UNO, LED, Push button, 220Ω resistor, Jumper wires, Breadboard. 
// Circuit: Connect LED to pin 13, button to pin 2 with pull-down resistor. 
// Program: 
int button = 2; 
int led = 13; 
int state = 0; 
void setup() { 
pinMode(button, INPUT); 
pinMode(led, OUTPUT); 
} 
void loop() { 
state = digitalRead(button); 
if (state == HIGH) 
digitalWrite(led, HIGH); 
else 
digitalWrite(led, LOW); 
} 


// RESULT: LED glows when button is pressed.
