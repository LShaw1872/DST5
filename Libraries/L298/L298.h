/*
  L298.h - Test library for L298 H-bridge.
  Written by Boris Yanchev.

*/

// ensure this library description is only included once
#ifndef L298_h
#define L298_h

# include "Arduino.h"

// library interface description
class actuator
{
  public:
    actuator(int in1, int in2, int en);

    void extending();

    void retracting();

    void reverse();

    void changeForce(int percentage);

  private:

    int in1Pin;
    int in2Pin;
    int enPin;
};

#endif