/*
 * Description: Main test code for a single section using the L298 H-bridge.
 * 
 * Written by: Boris Yanchev
 * 
 * Version: 1.0
 * 
 * Notes:
 * 
 */


#include "L298.h"

#define encoderPin 14
#define fsrPin 18

#define extendedTh 1            //REPLACE WITH ACTUAL NUMBER!
#define retractedTh 1           //REPLACE WITH ACTUAL NUMBER!
#define maxRetractionTime 1     //REPLACE WITH ACTUAL NUMBER!
#define PWMStep 10


bool hasMoved = false;

float prevEnc = 0;
int PWMvalue = 0;


//declarations
actuator myActuator(15,16,17);
IntervalTimer myTimer;
void changeState();


// placeholder for function which responds to error codes
void raiseError(int errorCode){  
  switch(errorCode)P{
    case(1){
      // segment initialisation error
      break;
    while(1){}
    }
    case(2){
      // "I'm stuck!" error
      break;
    }
  }  

/*
 * Placeholder for function to get force value of front sensor via CAN bus,
 * should return 1 if maximum force at drill head reached.
 */

void frontForceMax(){
  return 0;

}


/* Function to control actuator PWNM value.
 * If movement has been completed succesfully, call changeState
 * If no movement registered, but force sensor on first segment 
 * does not indicate maximum force, actuator not completely retracted,
 * but motion can continue. If max force, raise "I'm stuck!" error.
 */
void updatePWM(){
  float newEnc = analogRead(encoderPin);      // data might need filtering
  if(newEnc == extendedTh OR newEnc == retractedTh){
    hasMoved = 1;
    myTimer.end();
    changeState();
  }
  else if(prevEnc == newEnc){
    if(PWMvalue == 100){
      if(frontForceMax()){
      raiseError(2);      // stuck!
      }
     else{                // actuator has not moved, but force sensor is not at max force, i.e is retracting
     hasMoved = 1;
     myTimer.end();
     changeState();
       // Need function to send command to next Teensy.
    }
    else{
      PWMvalue+=PWMStep;
      myActuator.changeForce(force);
      prevEnc = newEnc;
    }
  }

/*
 * Function to initialise movement of segment.
 * If movement completed successfully, send command to next segment.
 * Attaches updatePWM to timer interrupt.
 */
void changeState(){
  if(!hasMoved){
    myActuator.reverse();
    myTimer.begin(updatePWM, 1000);
    }
    else{
      hasMoved = 0;
      // Need function to send command to next Teensy.
      }
}


/*
 * Setup function to make sure segment starts in contracted position for proper gait.
 * Raises error if segment not contracted within a certain time.
 */
void setup() {
  pinMode(encoderPin, INPUT);
  if(analogRead(encoderPin) > retractedTh){     // data might need filtering
    myActuator.retracting();
    myActuator.changeForce(100);
    }
  delay(maxRetractionTime);
  if(analogRead(encoderPin) > retractedTh){  
    myActuator.changeForce(0);
    raiseError(1);      // Raise segment initialisation error.
    }
}


void loop() {
  // need function to check for incoming messages on CAN bus
  // If a "ready to move" message is received, run changeState()

}
