// Drive the ponytail. Based off of Accel_MultiStepper example sketch from AccelStepper library (v 1.5.1).

#include <AccelStepper.h>

// set motor movement parameters
float MAX_SPEED = 3000.0; // max motor speed (steps/sec)
float ACCEL = 4000.0; // acceleration (steps/sec/sec)
long DIST = 200; // distance (steps) for motor travel
unsigned long pause_time = 1000; // delay between movements (in milliseconds)

// construct an instance of AccelStepper in driver mode (default step pin 2, dir pin 3)
AccelStepper stepper(1);

void setup()
{
  // feed motor object its movement parameters
  stepper.setMaxSpeed(MAX_SPEED);
  stepper.setAcceleration(ACCEL);

  stepper.setEnablePin(4); // sets enable pin to pin 4 on Arduino
  stepper.setPinsInverted(0,0,1); // enable pin inverted on Pololu stepper driver
}

void loop()
{
  stepper.enableOutputs();
  //stepper.runToNewPosition(-DIST);
  stepper.runToNewPosition(DIST);
  stepper.setCurrentPosition(0);
  stepper.disableOutputs(); // disengage (reduce heat buildup) at the limits
  delay(1000); // pause a second between movements
}
