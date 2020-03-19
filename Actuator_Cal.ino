/*
   DESCRIPTION:
   Program to calibrate actuator using external set of scales.
   Loops through PWM cycles on keypress by chosen step.
   To be used for actuator calibration for accurate control.

   WRITTEN BY: Boris Yanchev

   VERSION: 1.0

   NOTES:
   -19/03 - initial creation.

*/

#define MinPWM 0
#define MaxPWM 255

int PWMout = A1;
int step = 0;


void waitForPress() {
  while (true) {
    if (Serial.available() > 0) {
      break;
    }
  }
}

void getStep(){
  Serial.printf("\nInput step size:\n");
  while (true){
    if(Serial.available()>0){
      step = Serial.read();
      break;
      }
    }
  }

void setup() {
  pinMode(PWMout, OUTPUT);

  Serial.begin(9600);
  Serial.print("\nActuator Calibration Code\n");
  getStep();

  for (int i = MinPWM; i <= MaxPWM; i += step) {
    analogWrite(PWMout, i);
    Serial.printf("\nPWM set to %f%\n", i / 255 * 100);
    waitForPress();
  }
}

void loop() {

}
