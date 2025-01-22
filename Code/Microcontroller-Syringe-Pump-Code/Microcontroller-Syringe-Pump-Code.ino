// Author: Aleks Siemenn <asiemenn@mit.edu>
// Keep file up-to-date: https://github.com/PV-Lab/Archerfish
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
#include <AccelStepper.h> // Include the AccelStepper library for controlling stepper motors

#define FULLSTEP 4 
// The 28BYJ-48 stepper can be driven in FULLSTEP mode using 4 steps.
// (There are also other modes like HALFSTEP, but here we define FULLSTEP = 4.)

// Create two stepper motor objects using the AccelStepper library.
// The constructor arguments are (interface, pin1, pin2, pin3, pin4).
// 'interface' is set to FULLSTEP to match the driver/motor mode.
AccelStepper stepperA(FULLSTEP, a1, a3, a2, a4); 
AccelStepper stepperB(FULLSTEP, b1, b3, b2, b4);

// Declare global/local variables for usage in setup() and loop().
int i;               // A variable used as a dynamic speed control index.
int buffer_time = 1000;  // A delay threshold in milliseconds, used to delay stepping logic.

void setup() {
    Serial.begin(115200); // Start serial communication at 115200 baud for debugging.

    // -------------------- Stepper A (stepperA) Settings --------------------
    stepperA.setMaxSpeed(maxStepSpeed);    
    // Set the maximum stepping speed (steps per second) for stepperA.
    // maxStepSpeed is presumably defined elsewhere, e.g. 300 steps/s.

    stepperA.setAcceleration(stepAccel);
    // Set the acceleration (in steps per second^2) for stepperA.
    // stepAccel is presumably defined elsewhere, e.g. 1000.0.

    stepperA.moveTo(stepDirection * 1000000);
    // Command stepperA to move a large number of steps in the specified direction.
    // This effectively makes it run 'indefinitely' until we stop or change conditions.

    // -------------------- Stepper B (stepperB) Settings --------------------
    stepperB.setMaxSpeed(maxStepSpeed);
    // Set the maximum stepping speed for stepperB.

    stepperB.setAcceleration(stepAccel);
    // Set the acceleration for stepperB.

    stepperB.moveTo(stepDirection * 1000000);
    // Same idea as with stepperA: move a large number of steps so it keeps running.

    begin_time = millis();   // Initialize a timestamp variable (declared elsewhere).
    begin_time2 = millis();  // Another timestamp for different logic in loop.
    i = 0;                   // Initialize the speed-incrementing variable to 0.
}

void loop() {
    // If less time than buffer_time has passed since begin_time2,
    // set stepperA speed to 0 and stepperB speed to negative maxStepSpeed.
    // This creates an initial delay or 'buffer' condition for stepperA,
    // while stepperB moves in the negative direction (for demonstration or positioning).
    if (millis() - begin_time2 < buffer_time) {
        stepperA.setSpeed(0); 
        // Stepper A does not move during the buffer time.
        stepperB.setSpeed(-maxStepSpeed);
        // Stepper B moves at maximum speed in the negative direction.
    }

    // Once buffer_time has elapsed, incrementally change speeds of both motors
    // until stepperA reaches maxStepSpeed and stepperB's speed goes to 0.
    if ((i < maxStepSpeed) && ((millis() - begin_time2) >= buffer_time)) {

        // Only update speeds every so often, based on the begin_time interval.
        if ((millis() - begin_time) > (maxStepSpeed / 2)) {
            float Aspeed = (float)i; // Cast i to float for clarity.
            stepperA.setSpeed(stepDirection * Aspeed);
            // Gradually increase stepperA's speed from 0 to maxStepSpeed in 'stepDirection'.
            Serial.print("A speed: ");
            Serial.println(Aspeed);

            float Bspeed = (float)(maxStepSpeed - i);
            stepperB.setSpeed(stepDirection * Bspeed);
            // Decrease stepperB's speed from maxStepSpeed down to 0 in 'stepDirection'.
            Serial.print("B speed: ");
            Serial.println(Bspeed);

            // Increase i by some defined increment. This controls how quickly
            // stepperA speeds up and stepperB slows down.
            i += increment;

            // Update the time checkpoint so we don't update too frequently.
            begin_time = millis();
        }

        // Once i reaches or exceeds maxStepSpeed, stepperA is set to run
        // at -maxStepSpeed (reversing direction), and stepperB is stopped (speed 0).
        if (i >= maxStepSpeed) {
            stepperA.setSpeed(-maxStepSpeed);
            stepperB.setSpeed(0);
        }
    }

    // The runSpeed() function advances the motor at the most recently set speed.
    // This must be called frequently (ideally each loop) to keep the motor stepping.
    stepperA.runSpeed();
    stepperB.runSpeed();
}
