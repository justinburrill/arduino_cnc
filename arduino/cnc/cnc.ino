#include <Servo.h>
#include <Stepper.h>

// change this to fit the number of steps per revolution for your motor
const int stepsPerRevolution = 100;
const int RPM = 120;

// initialize the stepper library on pins 8 through 11:
Stepper xMotor(stepsPerRevolution, 8, 9, 10, 11);
//Stepper yMotor(stepsPerRevolution, ?, ?, ?, ?);

//int paperWidth;
//int paperHeight;
int imgWidth;
int imgHeight;

int penServoPin = 9;

Servo penServo;


void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);

  penServo.attach(penServoPin);

  // motor 1
  pinMode(2, OUTPUT); // for EN1
  digitalWrite(2, HIGH); // enable EN1
  pinMode(3, OUTPUT); // for EN1
  digitalWrite(3, HIGH); // enable EN2

  //  // motor 2
  //  pinMode(?,OUTPUT);// for EN1
  //  digitalWrite(?,HIGH);// enable EN1
  //  pinMode(?,OUTPUT);// for EN1
  //  digitalWrite(?,HIGH); // enable EN2

  // set the speed at 60 rpm:
  xMotor.setSpeed(RPM);
  resetPen();



  while (!Serial.available());
  int num = Serial.readString().toInt();


  int paper_size;
  int img_size;
  int pixel_size = paper_size / img_size;
  bool data[img_size * img_size];
  for (int i = 0; i < img_size * img_size; i++) {
    if (data[i]) {
      drawPixel(pixel_size);
    }
    if (i % img_size != 0) {
      movePen("down");
      movePen("left");
    } else {
      movePen("right")
    }
  }
  resetPen();
}

void loop() {}


void drawPixel(int pixel_size) {
  pen(true);
  delay(50);
  pen(false);
}

void movePen(String dir) {
  if (dir == "right") {
    // step motors right one px
  }
  if (dir == "down") {
    // step motors right one px
  }
  if (dir == "left") {
    // step motors left all the way
  }
}

//void moveTo(int xin, int yin) {
//
//}

void resetPen() {
  pen(false);
  // move pen to top left corner
  // adjust number of steps and direction (+/-)
  xMotor.step(500);
  //  yMotor.step(500);
}

void pen(bool on) {
  int on_deg = 150;
  int off_deg = 140;
  if (on) {
    penServo.write(on_deg);
  }
  else {
    penServo.write(off_deg);
  }
}
