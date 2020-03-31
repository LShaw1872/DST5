/*
  L298.h - Test library for L298 H-bridge.
  Written by Boris Yanchev.

*/

#include "L298.h"

actuator::actuator(int in1, int in2, int en)
{
  in1Pin = in1;
  pinMode(in1Pin, OUTPUT);

  in2Pin = in2;
  pinMode(in2Pin, OUTPUT);

  enPin = en;
  pinMode(enPin, OUTPUT);

}


void actuator::extending()
{
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
}


void actuator::retracting()
{
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
}


void actuator::reverse()
{
  digitalWrite(in1Pin, !digitalRead(in1Pin));
  digitalWrite(in2Pin, !digitalRead(in2Pin));
}


void actuator::changeForce(int percentage) {
  analogWrite(enPin, percentage / 100 * 255);
}