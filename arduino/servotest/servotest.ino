#include <Servo.h>

/*
  Into Robotics
*/


int servoPin = 9;

Servo servo;

int servoAngle = 0;   // servo position in degrees

void setup()
{
  Serial.begin(9600);
  servo.attach(servoPin);
}


void loop()
{
  servo.write(130);
  delay(500);
  servo.write(140);
  delay(500);

}
