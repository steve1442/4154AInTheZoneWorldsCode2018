#include "main.h"

bool breakstack;
const unsigned int TrueSpeed[128] = // array used as a converter to make joy vals linear with motor accerlation
{
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0, 21, 21, 21, 22, 22, 22, 23, 24, 24,
 25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
 28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
 33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
 37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
 41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
 46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
 52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
 61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
 71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
 80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
 88, 89, 89, 90, 90,127,127,127
};

void operatorControl() {
	TaskHandle UPDATE = taskRunLoop(update, 10); // starts motor update task
	TaskHandle LCDDEBUG = taskRunLoop(LCDDebugScreens, 10); // runs the debug task that displays important values like sensors
  TaskHandle PID = taskRunLoop(pidController, 10); // runs the pid control loop calculating our pid for our lift allowing it to be stable
	while (1) { // main loop, everything inside this is constantly refreshed
    pidRequestedValue += 1 * (joystickGetDigital(1, 5, JOY_UP) - joystickGetDigital(1, 5, JOY_DOWN)); // simple way to do the work of 2 if statements
		drive(TrueSpeed[abs(joystickGetAnalog(1, 3))] * (joystickGetAnalog(1, 3)/abs(joystickGetAnalog(1, 3))), // drive control
		TrueSpeed[abs(joystickGetAnalog(1, 2))] * (joystickGetAnalog(1, 2)/abs(joystickGetAnalog(1, 2))));      // that uses the treeSpeed array
		mogo(-127 * (joystickGetDigital(1, 5, JOY_UP) - joystickGetDigital(1, 5, JOY_DOWN))); // no need for complex mogo so we do the same with the pid but for the motor val
		stabalizationcode(127 * (joystickGetDigital(1, 6, JOY_UP) - joystickGetDigital(1, 6, JOY_DOWN))); // original stabalization code that is still being tested
		secondaryLift(127 * (joystickGetDigital(1, 8, JOY_UP) - joystickGetDigital(1, 8, JOY_DOWN))); // dont need a advance fb because its just going to 2 points
		if(joystickGetDigital(1, 7, JOY_UP)){roller(50);}       // 15 + (joy * 45) + (-joy * 100);
		else if(joystickGetDigital(1, 7, JOY_DOWN)){roller(-100);}
		else{roller(15);}
    if(joystickGetDigital(1, 6, JOY_UP)){breakstack = false;}
    else if(joystickGetDigital(1, 7, JOY_LEFT)){}
    else {}
		delay(20);
	}
	taskDelete(UPDATE);
	taskDelete(LCDDEBUG);
  taskDelete(PID);
}
