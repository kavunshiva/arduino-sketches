#include <AccelStepper.h>
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield shield = Adafruit_MotorShield(0x60); // Default address, no jumpers

Adafruit_StepperMotor *myStepper = shield.getStepper(200, 2);

AccelStepper stepper(myStepper->onestep(FORWARD, DOUBLE));

void setup() {
  shield.begin(); // gentlemen, start your shields

  stepper.setMaxSpeed(100.0);
  stepper.setAcceleration(100.0);
  stepper.moveTo(1000000);
}

void loop() {
  // Change direction at the limits
      if (stepper.distanceToGo() == 0)
  stepper.moveTo(-stepper.currentPosition());

  stepper.run();
}
