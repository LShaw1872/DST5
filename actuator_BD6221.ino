/*
   Actuator class definition using BD6221 H-bridge driver.

   Written by: Boris Yanchev

   Version: 1.0

   Notes:

*/

class actuator
{
    int finPin;
    int rinPin;
    int enPin;

  public:
    actuator(int fin, int rin, int en)
    {
      finPin = fin;
      pinMode(finPin, OUTPUT);

      rinPin = rin;
      pinMode(rinPin, OUTPUT);

      enPin = en;
      pinMode(enPin, OUTPUT);
    }

    void brake()
    {
      digitalWrite(finPin, HIGH);
      digitalWrite(rinPin, HIGH);
    }

    void extendForce(int percentage) {
      analogWrite(finPin, percentage / 100 * 255);
      digitalWrite(rinPin, LOW);
    }

    void retractForce(int percentage) {
      analogWrite(rinPin, percentage / 100 * 255);
      digitalWrite(finPin, LOW);
    }

};
