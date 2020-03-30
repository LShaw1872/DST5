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
    actuator(int fin, int rin, int en);

    void brake();

    void extendForce(int percentage);

    void retractForce(int percentage);

  private:

    int finPin;
    int rinPin;
    int enPin;
};

#endif
