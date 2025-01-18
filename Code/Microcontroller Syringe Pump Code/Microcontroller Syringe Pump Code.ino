// Author: Aleks Siemenn <asiemenn@mit.edu>
// Keep file up-to-date: https://github.com/PV-Lab/Archerfish/tree/master/Stepper_motor_controller/Stepper_motor_controller
// =============== VARIABLE SETUP  =============== //
int maxStepSpeed = 400.0; // max stepSpeed = 800 before failure/unreliable
int stepAccel = 1000.0; // don't really need to change this acceleration value
int stepTime =10; // seconds. don't exceed 30 seconds or it will run forever
                   // motors run for stepTime*(number of motors)
int stepDirection = -1; // -1 for CW (plunger goes down) and 1 for CCW (plunger goes up) [motor pin facing down]
char firstMotor = 'A'; // 'A' => first, motor A runs for stepTime then turns off and motor B runs for stepTime
                       // 'B' => first, motor B runs for stepTime then turns off and motor A runs for stepTime

int increment = 2;
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
unsigned long begin_time;
unsigned long begin_time2;
//
// ===== //
// Notes
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
int buffer_time = 1000;
void setup()
{  
    // Stepper 1 settings
    Serial.begin(115200);
    stepperA.setMaxSpeed(maxStepSpeed); //max step speed = 300
    stepperA.setAcceleration(stepAccel); //step acceleration = 1000.0 (rad)?
    stepperA.moveTo(stepDirection*1000000); // keep motor rotating for a very long time. limit by breaking loop sing millis() 
    // Stepper 2 settings
    stepperB.setMaxSpeed(maxStepSpeed);
    stepperB.setAcceleration(stepAccel);
    stepperB.moveTo(stepDirection*1000000); // keep motor rotating for a very long time. limit by breaking loop sing millis() 
    begin_time = millis();
    begin_time2 = millis();
    i = 0;
}
void loop() // loop to end stepper run given stepTime
{
//
  if (millis()-begin_time2 < buffer_time){
    stepperA.setSpeed(0); 
    stepperB.setSpeed(-maxStepSpeed);
  }
  if ((i<maxStepSpeed) && (millis()-begin_time2) >= buffer_time){  
    if ((millis()-begin_time)> maxStepSpeed / 2){
      float Aspeed = (float) i;
      stepperA.setSpeed(stepDirection * Aspeed); 
      Serial.print("A speed:");
      Serial.println(Aspeed);
      float Bspeed = (float) (maxStepSpeed-i);
      stepperB.setSpeed(stepDirection * Bspeed); 
      Serial.print("B speed:");
      Serial.println(Bspeed);
      i+=increment; 
      begin_time = millis();
    }

  if (i >= maxStepSpeed){
    stepperA.setSpeed(-maxStepSpeed); 
    stepperB.setSpeed(0);
  }
  }
//  else if (i>=maxStepSpeed && i<maxStepSpeed * 2){
//    int j = i-maxStepSpeed;
//    if ((millis()-begin_time)> maxStepSpeed / 2){
//    float Aspeed = (float) (maxStepSpeed-j);
//    stepperA.setSpeed(stepDirection * Aspeed);
//    Serial.print("A speed:");
//    Serial.println(Aspeed);
//    float Bspeed = (float) j;
//    stepperB.setSpeed(stepDirection * Bspeed);
//    Serial.print("B speed:");
//    Serial.println(Bspeed);
//    i+=increment; 
//    begin_time = millis();
//  }
//  }
//  else if(i>=maxStepSpeed * 2){
//    i = 0;
//    begin_time = millis();
//  }
//  Serial.print("i:");
//  Serial.println(i);
  stepperA.runSpeed();
  stepperB.runSpeed();
  

}
