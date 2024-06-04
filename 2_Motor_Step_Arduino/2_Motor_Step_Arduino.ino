// Author: Aleks Siemenn <asiemenn@mit.edu>
// Keep file up-to-date: https://github.com/PV-Lab/Archerfish/tree/master/Stepper_motor_controller/Stepper_motor_controller
// =============== VARIABLE SETUP  =============== //
int maxStepSpeed = 500; // max stepSpeed = 800 before failure/unreliable
int stepAccel = 100; // don't really need to change this acceleration value


int increment = 2;
int stepNum;

// Stepper A pins
int a1 = 13;
int a2 = 12;
int a3 = 11;
int a4 = 10;
// Stepper B pins
int b1 = 5; 
int b2 = 4;
int b3 = 3;
int b4 = 2;

//
// ===== //
// Notes
// - Steps motor speeds from 100% to 0% in 5 steps.
// - Set voltage for Arduino and all stepper motors to ~5V
// ============================================== //
// ============================================== //
//
//
// =========== CONTROLLER CODE BELOW =========== //
#include <AccelStepper.h> // Tools > Manage Libraries ... > search for and install AccelStepper
#define FULLSTEP 4 // number of full steps for 28BYJ-48 stepper motors
AccelStepper stepperA(FULLSTEP,a1,a3,a2,a4); // define stepper 1 pins
AccelStepper stepperB(FULLSTEP,b1,b3,b2,b4); // define stepper 2 pins
int i;
int totCount = 300000 * 2.15;
void setup()
{  
    // Stepper 1 settings
    Serial.begin(115200);
    delay(200);
    Serial.println("setup()");
    stepperA.setMaxSpeed(maxStepSpeed * 1.2); //max step speed = 300
    stepperA.setAcceleration(stepAccel); //step acceleration = 1000.0 (rad)?
    // Stepper 2 settings
    stepperB.setMaxSpeed(maxStepSpeed * 1.2);
    stepperB.setAcceleration(stepAccel);
    i = 0;
}
void loop() // loop to end stepper run given stepTime
{

      i+=increment; 
      stepNum = map(i, 0, totCount, 0, 9);
      Serial.println(stepNum);


      if (stepNum >= 0 && stepNum < 3){  // Extend for 1.5x length to purge
        stepperA.setSpeed(maxStepSpeed); // 100%
        stepperB.setSpeed(maxStepSpeed * 0); // 0%
      }

      if (stepNum >= 3 && stepNum < 5){
        stepperA.setSpeed(maxStepSpeed * 0.75); // 75%
        stepperB.setSpeed(maxStepSpeed * 0.25); // 25%
      }
      
      if (stepNum >= 5 && stepNum < 7){
        stepperA.setSpeed(maxStepSpeed * 0.5); // 50%
        stepperB.setSpeed(maxStepSpeed * 0.5); // 50%
      }


      if (stepNum >= 7 && stepNum < 9){
        stepperA.setSpeed(maxStepSpeed * 0.25); // 25%
        stepperB.setSpeed(maxStepSpeed * 0.75); // 75%
      }

      
      if (stepNum >= 9){
        stepperA.setSpeed(maxStepSpeed * 0); // 0%
        stepperB.setSpeed(maxStepSpeed); // 100%
      }
      

//  Serial.println(i);
  stepperA.runSpeed();
  stepperB.runSpeed();
}
