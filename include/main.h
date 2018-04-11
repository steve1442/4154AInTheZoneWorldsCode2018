
#ifndef MAIN_H_

// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define MAIN_H_

#include <API.h>

extern char motor[11];

Gyro gyro;

Encoder leftenc;

Encoder rightenc;

Encoder leftliftenc;

Encoder rightliftenc;

extern float PIDDebug[5][3];

extern int PIDDesired[5];

extern int selectedauton;

extern int pidRequestedValue;

extern bool breakstack;

extern int autoStackRunning;

void primaryLiftPID(int desired);

void secondaryLiftPID(int desired);

extern int leftime, rightime;

void lift(int left, int right); // A basic function to control the lift whether it be an elevator or a four bar

void secondaryLift(int pwm); // A basic function to control the secondary lift system whether that be chain bar or four bar

void drive(int left, int right); // A basic function to control the chassis or drive of the robot using seperate integers for left and right control

void roller(int pwm); // A basic function for controlling the claw or in this case a roller

void mogo(int pwm); // A basic function for controlling the mobile goal or mogo

void update();

void LCDDebugScreens();

void LCDSetUp(bool backlight);

void konamicodefunc();

void DebugHub();

void distanceDrivePID(int Desired, int distance);

void gyroTurn(int desired);

void auton1(); // blue left

void auton2(); // blue right

void auton3(); // red left

void auton4();// red right

void autonselect();

void pid();

void holdtheline(int ticks, int pwm);

void drivefunc(int ticks, int topspeed);

void bettergame();

void game();

void stabalizationcode(int pwm);

void pidController();

void liftlift(int pwm);

// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

void autonomous();

void initializeIO();

void initialize();

void operatorControl();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
