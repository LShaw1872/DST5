/*
 * DESRIPTION:
 * Program to calibrate FSR sensor using a calibrated actuator.
 * Loops through force values at key press and prints out resultant resistance. 
 * To be used when calibrating FSR sensor for accurate control of robot motion.
 * Written for the Teensy 4.0 microcontroller.
 * 
 * UNTESTED!
 *
 *
 * WRITTEN BY: Boris Yanchev
 * 
 * REVISION: 1.1
 * 
 * FIXES AND COMMENTS:
 * 
 * -19/03 - created v1.0.
 * -19/03 - fixed comments and added functions.
 */

#include <math.h>

#define MinForce 0    //All in Newtons!
#define MaxForce 50
#define StepSize 5

#define LoadRes 1     //Replace with load resistance as per circ. diagram.

int analoguePin = A0;
int PWMout = A1;

//Function returns PWM value for actuator based on calibration curve and desired force.
float ForceToPWM(float forceValue){
  return forceValue;       //Replace with actual correction factor once known!
  }

//Returns FSR resistance based on ADC reading for 10-bit DAC.
float ADCtoRes(float ADCvalue){
  return (LoadRes * (pow(2,10)/ADCvalue - 1));
  }


//Infinite loop until key is pressed on terminal.
void WaitForKeypress(){
  while (true) {
    if (Serial.available() > 0) {
      break;
    }
  }
}

void setup() {
  pinMode(analoguePin, INPUT);
  pinMode(PWMout, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("\nFSR Calibration Code\n");
  
  for (int i = 0; i <= MaxForce; i += StepSize) {
    float PWMvalue = ForceToPWM(i);
    Serial.printf("\nSetting force to %d N", i);
    analogWrite(PWMout, PWMvalue);
    delay(1);

    float FSRvalue = ADCtoRes(analogRead(analoguePin));
    Serial.printf("\tFSR resistance is: %fOhm\n", FSRvalue);
    WaitForKeypress();
    
    }
}

void loop() {

}
