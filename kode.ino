#include<Servo.h>
const int trigPin = A2;
const int echoPin = A1;
const int servoPin = A0; 
// defines variables
double SetDelay, Input, Output, ServoOutput; 
Servo myServo; //Initialize Servo.
void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
myServo.attach(servoPin); //Attach Servo
Input = readPosition(); 
}
void loop() {
Input = readPosition(); 
ServoOutput=Input; 
myServo.write(ServoOutput);
if(ServoOutput ==140) 
{
SetDelay=3000;
}
else{
SetDelay=100;
} 
delay(SetDelay); 
}
float readPosition() {
delay(40); 
long duration, var;
int distance; 
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance = duration/(29*2); 
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
if(distance <20) {
var=140;
}
else{
var=50;
} 
//Returns distance value.
return var; 
}
