#include "main.h"

int stack;
int coneheights[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void autostack()
{
  if(joystickGetDigital(1, 6, JOY_UP))
  {
    roller(127);
    pidRequestedValue = 100; // give a base value
    pidRequestedValue = coneheights[0];
    while(analogRead(5) ){}
    pidRequestedValue = coneheights[stack];
    while(analogRead(5)){}
    secondaryLift(127);
    while(analogRead(6));
    secondaryLift(0);
    roller(-127);
    secondaryLift(-127);
    while(analogRead(6)){}
    secondaryLift(0);
    pidRequestedValue = coneheights[0];
    while(analogRead(5)){}
  }
}
