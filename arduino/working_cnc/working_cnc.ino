/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.

  The motor should revolve one revolution in one direction, then
  one revolution in the other direction.


  Created 11 Mar. 2007
  Modified 30 Nov. 2009
  by Tom Igoe

  Modefied by Ahmad S. for Robojax.com
  on May 19, 2018 at 19:31, at Ajax, Ontario, Canada

*/

#include <Stepper.h>
#include <Servo.h>

const int stepsPerRevolution = 100;  // change this to fit the number of steps per revolution for your motor

int penServoPin = A5;
int RPM = 60;
Servo penServo;

// initialize the stepper library on pins 8 through 11:
Stepper upperStepper(stepsPerRevolution, 9, 10, 11, 12);
Stepper lowerStepper(stepsPerRevolution, 3, 4, 5, 6);

void setup_lower() {
  lowerStepper.setSpeed(RPM);
  pinMode(2, OUTPUT); // for EN1
  digitalWrite(2, HIGH); // enable EN1
  pinMode(7, OUTPUT); // for EN1
  digitalWrite(7, HIGH); // enable EN2
}

void setup_upper() {
  upperStepper.setSpeed(RPM);
  pinMode(8, OUTPUT); // for EN1
  digitalWrite(8, HIGH); // enable EN1
  pinMode(13, OUTPUT); // for EN1
  digitalWrite(13, HIGH); // enable EN2
}

void y(float amt, bool dot = false, int count = 1) {
  float scale = 1.0; // adjst if one goes faster
  for (int i = 0; i < count; i++) {
    upperStepper.step(stepsPerRevolution * amt * scale);
    if (dot) {
      drawdot();
    }
  }
}

void x(float amt, bool dot = false, int count = 1) {
  float scale = 1.0; // adjst if one goes faster
  for (int i = 0; i < count; i++) {
    lowerStepper.step(stepsPerRevolution * amt * scale);

    if (dot) {
      drawdot();
    }
  }
}

void setup() {
  Serial.begin(9600);
  penServo.attach(penServoPin);
  pen(false);
  setup_lower();
  setup_upper();

  reset_motors();
  

  // draw!
//  drawimg("square");

}

void drawimg(String type) {
  if (type == "square") {
    int scale = 6;
    x(0.3, true, scale);
    y(0.3, true, scale);

    x(-0.3, true, scale);
    y(-0.3, true, scale);
  }
  else if (type == "circle") {
    float r = 6;
    float step_size = 0.05;

    // r^2 = x^2 + y^2
    for (int x = 0; x <= r; x += step_size) {
//      y = sqrt(r * r - x * x)
    }
  }
}

void pen(bool on) {
  int off_deg = 140;
  int on_deg = 148;
  if (on) {
    penServo.write(on_deg);
  }
  else {
    penServo.write(off_deg);
  }
}

void reset_motors() {
  int amt = -3;
  x(amt);
  y(amt);
}

void drawdot() {
  pen(true);
  delay(150);
  pen(false);
  delay(150);
}

void loop() {
  //  // step one revolution  in one direction:
  //  Serial.println("clockwise");
  //  lowerStepper.step(3 * stepsPerRevolution);
  //  upperStepper.step(3 * stepsPerRevolution);
  //  pen(true);
  //  delay(500);
  //
  //  // step one revolution in the other direction:
  //  Serial.println("counterclockwise");
  //  lowerStepper.step(-3 * stepsPerRevolution);
  //  upperStepper.step(-3 * stepsPerRevolution);
  //  pen(false);
  //  delay(500);


  //  for (int i = 0; i < 6; i++) {
  //    upperStepper.step(0.25 * stepsPerRevolution);
  //    dot();
  //  }
  //  for (int i = 0; i < 6; i++) {
  //    lowerStepper.step(0.25 * stepsPerRevolution);
  //    dot();
  //  }
  //  for (int i = 0; i < 6; i++) {
  //    upperStepper.step(-0.25 * stepsPerRevolution);
  //    dot();
  //  }
  //  for (int i = 0; i < 6; i++) {
  //    lowerStepper.step(-0.25 * stepsPerRevolution);
  //    dot();
  //  }
}
