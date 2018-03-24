  #include "main.h"

char motor[11] = {0,0,0,0,0,0,0,0,0,0,0};

void lift(int pwm)
{
  motor[6] = pwm;
  motor[7] = pwm;
}

void secondaryLift(int pwm)
{
  motor[9] = pwm;
}

void drive(int left, int right)
{
  motor[2] = left;
  motor[3] = left;
  motor[4] = right;
  motor[5] = right;
}

void roller(int pwm)
{
  motor[9] = pwm;
}

void mogo(int pwm)
{
  motor[1] = pwm;
  motor[10] = pwm;
}

void encoderreset()
{
  encoderReset(leftenc);
  encoderReset(rightenc);
}

void drivefunc(int ticks, int topspeed)
{
  encoderreset();
  while(abs(ticks) > abs(encoderGet(leftenc)))
  {
    int distance = ticks - encoderGet(leftenc);
    if(abs(distance) > abs(topspeed))
    {
      distance = topspeed * (ticks/abs(ticks));
    }
    drive(distance, distance);
  }
  drive(0,0);
}

void holdtheline(int ticks, int pwm)
{
  encoderreset();
  while(abs(ticks) > abs(encoderGet(leftenc)))
  {
    int error = encoderGet(leftenc) - encoderGet(rightenc);
    int left = pwm;
    int right = pwm + error;
    drive(left, right);
  }
  drive(0, 0);
}

void update()
{
  motorSet(1, motor[1]);motorSet(2, motor[2]);motorSet(3, motor[3]);motorSet(4, motor[4]);motorSet(5, motor[5]);
  motorSet(6, motor[6]);motorSet(7, motor[7]);motorSet(8, motor[8]);motorSet(9, motor[9]);motorSet(10, motor[10]);
  delay(2);
}
