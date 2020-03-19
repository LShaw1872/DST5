/*
 * DESRIPTION:
 * Program to calibrate FSR sensor using a calibrated actuator.
 * Loops through force values at key press and prints out resultant resistance. 
 * Prompts for load resistance for maximum versatility of testing hardware.
 * To be used when calibrating FSR sensor for accurate control of robot motion.
 *
 * WRITTEN BY: Boris Yanchev
 * 
 * REVISION: 1.0
 * 
 * FIXES AND COMMENTS:
 * 
 * -19/03 - created v1.0.
 */

#include <math.h>

#define MinForce 0
#define MaxForce 50
#define StepSize 5

int analoguePin = A0;
int PWMout = A1;

/*
 * Function returns PWM value for actuator based on calibration curve and desired force.
 */
float ForceToPWM(float forceValue){
  return forceValue;       //Replace with actual correction factor once known!
  }

float ADCtoRes(float ADCvalue){
  float loadRes = 1;
  return (loadRes * (pow(2,10)/ADCvalue - 1));
  }


void setup() {
  pinMode(analoguePin, INPUT);
  pinMode(PWMout, OUTPUT);
  
  Serial.begin(9600);
  Serial.print("\nFSR Calibration Code\n");
  
  for (int i=0; i<=MaxForce; i+=StepSize){
    float PWMvalue = ForceToPWM(i);
    Serial.printf("\nSetting force to %d N", i);
    analogWrite(PWMout, PWMvalue);
    delay(1);

    float FSRvalue = ADCtoRes(analogRead(analoguePin));
    Serial.printf("\tFSR resistance is: %fOhm\n", FSRvalue);
    }

}

void loop() {

}
