#include <Servo.h>  //Includes the Servo Library

Servo myservo;  //Declaring variables
int val;

void setup()
{
  myservo.attach(12); //Servo receives signal from PWM pin 12 on the Zero
  pinMode(6, INPUT); //Pin 6 receives 3.3V input from 2nd microcontroller = Arduino Mega 
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(6));
  if (digitalRead(6) == HIGH) //Light Dependent Servo Circuit works only when input to PWM pin 6 is high
  {
    Serial.println("HIGH");
    val = analogRead(0);  //Microcontroller reads the input to the analog pin 0
    val = map(val, 0, 1023, 0, 179);
    myservo.write(val); //Controls the shaft of the servo
    delay(15);
  }
  else
  {
    myservo.write(90);  //Prevents Servo from rotating when input is low
  }
}
