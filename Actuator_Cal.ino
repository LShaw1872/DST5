/*
   DESCRIPTION:
   Program to calibrate actuator using external set of scales.
   Loops through PWM cycles on keypress by chosen step.
   To be used for actuator calibration for accurate control.

   UNTESTED!

   WRITTEN BY: Boris Yanchev

   VERSION: 1.1

   NOTES:
   -19/03 - initial creation.
   -19/03 - added comments and fixed variables.

*/

#define MinPWM 0
#define MaxPWM 255

int PWMout = A1;


//Intinite loop until key is pressed.
void waitForPress() {
  while (true) {
    if (Serial.available() > 0) {
      break;
    }
  }
}

//Function returns step value input on serial terminal.
int getStep(){
  Serial.printf("\nInput step size:\n");
  while (true){
    if(Serial.available()>0){
      break;
      }
    }
  return Serial.read();
  }

void setup() {
  pinMode(PWMout, OUTPUT);

  Serial.begin(9600);
  Serial.print("\nActuator Calibration Code\n");
  int step = getStep();

  for (int i = MinPWM; i <= MaxPWM; i += step) {
    analogWrite(PWMout, i);
    Serial.printf("\nPWM set to %f%\n", i / 255 * 100);
    waitForPress();
  }
}

void loop() {

}
