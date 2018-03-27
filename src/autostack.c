#include "main.h"

int stack = 0;
int coneheights[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void autostack()
{
  autoStackRunning = true;
  breakstack = true;
  while(autoStackRunning)
  {
    if(joystickGetDigital(1, 6, JOY_UP))
    {
      while(breakstack)
      {
        if(breakstack)
        {
          roller(127);
          pidRequestedValue = coneheights[0];
        }
        while(analogRead(5) < coneheights[0]){delay(20);}
        if(breakstack)
        {
          roller(15);
          pidRequestedValue = coneheights[stack];
        }
        while(analogRead(5) < coneheights[stack]){delay(20);}
        if(breakstack)
        {
          secondaryLift(127);
        }
        while(analogRead(6) < 1000);
        if(breakstack)
        {
          secondaryLift(0);
          roller(-127);
          secondaryLift(-127);
        }
        while(analogRead(6) > 500){delay(20);}
        if(breakstack)
        {
          secondaryLift(0);
          pidRequestedValue = coneheights[0];
        }
        while(analogRead(5) > coneheights[0]){delay(20);}
        if(breakstack)
        {
          stack++;
        }
      }
    }
    if(joystickGetDigital(1, 6, JOY_DOWN)){autoStackRunning = false;}
    delay(20);
  }
}
