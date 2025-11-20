// Aim: To detect intrusion using ultrasonic sensor. 
// Components: Arduino UNO, HC-SR04, Buzzer, LED. 
// Program: 
#define trig 9 
#define echo 10 
#define led 13 
#define buzzer 8 
void setup() { 
pinMode(trig, OUTPUT); 
pinMode(echo, INPUT); 
pinMode(led, OUTPUT); 
pinMode(buzzer, OUTPUT); 
Serial.begin(9600); 
} 
void loop() { 
digitalWrite(trig, LOW); 
delayMicroseconds(2); 
digitalWrite(trig, HIGH); 
delayMicroseconds(10); 
digitalWrite(trig, LOW); 
long duration = pulseIn(echo, HIGH); 
int distance = duration * 0.034 / 2; 
if (distance < 20) { 
digitalWrite(led, HIGH); 
digitalWrite(buzzer, HIGH); 
} else { 
digitalWrite(led, LOW); 
digitalWrite(buzzer, LOW); 
} 
delay(500); 
} 

// RESULT: Alarm activates when object detected within 20 cm.
