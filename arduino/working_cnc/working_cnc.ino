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

float canvas_length = 2.6;


void setup() {
  Serial.begin(9600);
  penServo.attach(penServoPin);
  pen(false);
  setup_lower();
  setup_upper();

  reset_motors();


  // draw!
  drawImg("bwtest");

}

void y(float amt, bool dot = false, int count = 1) {
  float scale = 1.025; // adjst if one goes faster
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

void reset_motors() {
  x(canvas_length);
  y(canvas_length);
}

void drawImg(String type) {
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
  else if (type == "bwtest") {
    int side_length = 2;
    bool data[] = {true, true, false, false};
  }
}

void printImg(int side_length, bool data[]) {
  for (int i = 0; i < side_length; i++) {
    for (int j = 0; j < side_length; j++) {
      if ( data[side_length * i + j] == true ) {
        drawdot();
      }
      x(canvas_length/side_length);
    }
    y(canvas_length/side_length);
  }
  //  int paper_size;
  //
  //  int pixel_size = paper_size / img_size;
  //  for (int i = 0; i < img_size * img_size; i++) {
  //    if (data[i]) {
  //      drawPixel(pixel_size);
  //    }
  //    if (i % img_size != 0) {
  //      movePen("down");
  //      movePen("left");
  //    } else {
  //      movePen("right");
  //    }
  //  }
}

void pen(bool on) {
  int off_deg = 140;
  int on_deg = 147;
  if (on) {
    penServo.write(on_deg);
  }
  else {
    penServo.write(off_deg);
  }
}



void drawdot() {
  pen(true);
  delay(150);
  pen(false);
  delay(150);
}

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



void loop() {
}
