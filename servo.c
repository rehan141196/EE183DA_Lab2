#include <Servo.h>  // Includes the Servo Library

Servo myservo;  // Declaring variables
int val;
const short int SWITCH = 6;
const short int SERVO = 12;

void setup()
{
  myservo.attach(SERVO); // Servo receives signal from PWM pin 12 on the Zero
  pinMode(SWITCH, INPUT); // Pin 6 receives 3.3V input from 2nd microcontroller = Arduino Mega 
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(SWITCH));
  if (digitalRead(SWITCH) == HIGH) //Light Dependent Servo Circuit works only when input to PWM pin 6 is high
  {
    Serial.println("HIGH");
    val = analogRead(0);  // Microcontroller reads the input to the analog pin 0
    val = map(val, 0, 1023, 0, 179);
    myservo.write(val); // Controls the shaft of the servo
    delay(15);
  }
  else
  {
    myservo.write(90);  // Prevents Servo from rotating when input is low
  }
}