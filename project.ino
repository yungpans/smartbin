#include <Servo.h>

//define Pins
int led = 13;
int trigPin = 9;
int echoPin = 8;
int servoPin = 6;
Servo myServo;

//defines variables
long duration;
int distance;

void setup()
{
  myServo.attach( servoPin );  
  //Sets the Led as an Output
  pinMode(led, OUTPUT);
  //Sets the trigPin as an Output
  pinMode(trigPin, OUTPUT);
  //Sets the echoPin as an Input
  pinMode(echoPin, INPUT);
  // Starts the serial communication
  Serial.begin(9600);
}
void loop()
{
// Clears the trigPin
     digitalWrite(trigPin, LOW);
     delayMicroseconds(2);
//Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
//Reads the echoPin, returns the sounds wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
//Calculating the distance
    distance=duration*0.034/2;
//Prints the distance on the Seril Monitor
    Serial.print("Distance");
    Serial.println(distance);
    if( distance <= 14)//Change Distance according to Ultrasonic Sensor Plcement
    {
        digitalWrite(led, HIGH);
        myServo.write( 0 );
    }
    else
    {
        digitalWrite(led,LOW);
        myServo.write( 90 );
    }
   delay( 500 );
}
