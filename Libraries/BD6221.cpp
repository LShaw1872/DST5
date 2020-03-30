/*
  BD6221.h - Test library for BD6221 H-bridge.
  Written by Boris Yanchev.

*/

#include "BD6221.h"

actuator::actuator(int fin, int rin, int en)
{
  finPin = fin;
  pinMode(finPin, OUTPUT);

  rinPin = rin;
  pinMode(rinPin, OUTPUT);

  enPin = en;
  pinMode(enPin, OUTPUT);

}

void actuator::brake()
{
  digitalWrite(finPin, HIGH);
  digitalWrite(rinPin, HIGH);
}

void actuator::extendForce(int percentage) 
{
  analogWrite(finPin, percentage / 100 * 255);
  digitalWrite(rinPin, LOW);
}

void actuator::retractForce(int percentage) {
  analogWrite(rinPin, percentage / 100 * 255);
  digitalWrite(finPin, LOW);
}