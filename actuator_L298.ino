/*
   Actuator class definition using L298 H-bridge driver.

   Written by: Boris Yanchev

   Version: 1.0

   Notes:

*/

class actuator
{
    int in1Pin;
    int in2Pin;
    int enPin;

  public:
    actuator(int in1, int in2, int en)
    {
      in1Pin = in1;
      pinMode(in1Pin, OUTPUT);

      in2Pin = in2;
      pinMode(in2Pin, OUTPUT);

      enPin = en;
      pinMode(enPin, OUTPUT);
    }

    void extending()
    {
      digitalWrite(in1Pin, HIGH);
      digitalWrite(in2Pin, LOW);
    }

    void retracting()
    {
      digitalWrite(in1Pin, LOW);
      digitalWrite(in2Pin, HIGH);
    }


    void changeForce(int percentage) {
      analogWrite(enPin, percentage / 100 * 255);
    }

};
