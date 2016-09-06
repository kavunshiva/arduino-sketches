/*
I do this...for the jellyfish!
*/
#include <stdio.h>

int led1 = 3; // this is the pin to which LED1 is attached
int led2 = 5; // this is the pin to which LED2 is attached
int led3 = 6; // this is the pin to which LED3 is attached
int led4 = 9; // this is the pin to which LED4 is attached
int led5 = 10; // this is the pin to which LED5 is attached
int led6 = 11; // this is the pin to which LED6 is attached
int brightness = 0; // this controls how bright the LED is
int fadeAmount = 5; // this is how many points out of 255 to fade the LED by

// setup routine (runs once on reset)
void setup(){
  pinMode(led1, OUTPUT); // declare LED1 pin to be an output
  pinMode(led2, OUTPUT); // declare LED2 pin to be an output
  pinMode(led3, OUTPUT); // declare LED3 pin to be an output
  pinMode(led4, OUTPUT); // declare LED4 pin to be an output
  pinMode(led5, OUTPUT); // declare LED5 pin to be an output
  pinMode(led6, OUTPUT); // declare LED6 pin to be an output
}

// the loop runs forever after the setup
void loop(){
  blink(led1);
  blink(led2);
  blink(led3);
  blink(led4);
  blink(led5);
  blink(led6);
}

void blink(int pin){
  while (1 == 1){
    analogWrite(pin, brightness); // send current to pin at PWM level
    brightness = brightness + fadeAmount; // increase brightness by increment
    //if brightness hits max (255) or min (0), reverse direction of fade increment
    if (brightness == 0 || brightness == 255){
      fadeAmount = -fadeAmount;
    }
    delay(30); // wait 30 ms before changing brightness again (33 bfps)
    if (brightness < 5){
      break;
    }
  }
}
