#include "main.h"

float PIDDebug[5][3] = {
  /*Primary Lift*/  {0.2,0.0,0.0},
  /*Secondary Lift*/{0.0,0.0,0.0},
  /*LeftDrive*/     {0.1,0.0,0.0},
  /*RightDrive*/    {0.1,0.0,0.0},
  /**/              {0.0,0.0,0.0}};

int PIDDesired[5] = {300,0,0,0,0};

int primaryLastVal = 0;
int pidIntegral = 0;
void primaryLiftPID(int desired)
{
  int currentVal = analogRead(1);
  float error = desired - currentVal;
  if(PIDDebug[0][1] != 0){
             // If we are inside controlable window then integrate the error
             if(abs((int)(error + 0.5)) < 100){pidIntegral = pidIntegral + error;}
             else{pidIntegral = 0;}
        }
        else
        {
          pidIntegral = 0;
        }
  float derivitive = (currentVal - primaryLastVal);
  float output = PIDDebug[0][0] * error + PIDDebug[0][1] * pidIntegral + PIDDebug[0][2] * derivitive;
  lift(output, output);
  primaryLastVal = currentVal;
}

int secondaryLastVal = 0;
void secondaryLiftPID(int desired)
{
  int pidIntegral = 0;
  int currentVal = analogRead(3);
  float error = desired - currentVal;
  if(PIDDebug[0][1] != 0){if(error < 0){pidIntegral = pidIntegral + error;} else{pidIntegral = 0;}}else{pidIntegral = 0;}
  float derivitive = currentVal - secondaryLastVal;
  float output = PIDDebug[1][0] * error + PIDDebug[1][1] * pidIntegral + PIDDebug[1][2] * derivitive;
  secondaryLift(output);
  secondaryLastVal = currentVal;
}
void pid()
{
  if(joystickGetDigital(1, 6, JOY_UP))
  {
    PIDDesired[0] = analogRead(1);
    lift(127, 127);
  }
  else if(joystickGetDigital(1, 6, JOY_DOWN))
  {
    PIDDesired[0] = analogRead(1);
    lift(-127, -127);
  }
  else
  {
    primaryLiftPID(PIDDesired[0]);
  }
}
/*
int leftDriveLastVal = 0;
int rightDriveLastVal = 0;
void drivePID(int leftDesired, int rightDesired)
{
  int leftCurrentVal = encoderGet(leftEnc);
  float leftError = leftDesired - leftCurrentVal;
  float leftDerivitive = leftCurrentVal - leftDriveLastVal;
  float leftOutput = PIDDebug[2][0] * leftError + PIDDebug[2][2] * leftDerivitive;
  leftDriveLastVal = leftCurrentVal;

  int rightCurrentVal = encoderGet(rightEnc);
  float rightError = rightDesired - rightCurrentVal;
  float rightDerivitive = rightCurrentVal - rightDriveLastVal;
  float rightOutput = PIDDebug[3][0] * rightError + PIDDebug[3][2] * rightDerivitive;
  rightDriveLastVal = rightCurrentVal;

  drive(leftOutput, rightOutput);
}
*/

#define PID_INTEGRAL_LIMIT 50
#define PID_LIFT_MAX 127
#define PID_LIFT_MIN 0

bool pidRunning;
int pidRequestedValue;
float pid_Ki = 0,
      pid_Kd = 0,
      pid_Kp = 0;
void pidController()
{
    float  pidSensorCurrentValue = 0;

    float  pidError;
    float  pidLastError;
    float  pidIntegral;
    float  pidDerivative;
    float  pidLift;

    pidLastError  = 0;
    pidIntegral   = 0;

    while( true )
        {
        // Is PID control active ?
        if( pidRunning )
            {
            // calculate error
            pidError = pidSensorCurrentValue - pidRequestedValue;

            // integral - if Ki is not 0
            if( pid_Ki != 0 )
                {
                int integralcheck =  pidError * 10 ;
                // If we are inside controlable window then integrate the error
                if( abs(integralcheck) < PID_INTEGRAL_LIMIT * 10)
                    pidIntegral = pidIntegral + pidError;
                else
                    pidIntegral = 0;
                }
            else
                pidIntegral = 0;

            // calculate the derivative
            pidDerivative = pidError - pidLastError;
            pidLastError  = pidError;

            // calculate drive
            pidLift = (pid_Kp * pidError) + (pid_Ki * pidIntegral) + (pid_Kd * pidDerivative);

            // limit drive
            if( pidLift > PID_LIFT_MAX )
                pidLift = PID_LIFT_MAX;
            if( pidLift < PID_LIFT_MIN )
                pidLift = PID_LIFT_MIN;

            // update motor
            stabalizationcode(pidLift);
            }
        else
            {
            // clear all
            pidError      = 0;
            pidLastError  = 0;
            pidIntegral   = 0;
            pidDerivative = 0;
            stabalizationcode(0);
            }
        // Run at 50Hz
        wait( 15 );
        }
}
