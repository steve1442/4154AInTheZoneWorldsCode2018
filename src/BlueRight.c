#include "main.h"

void auton4()
{
  roller(15);
  mogo(127);
  lift(127);
  wait(250);
  lift(0);
  wait(750);
  mogo(0);
  while(1650 > encoderGet(leftenc)){
    lcdPrint(uart2, 1, "works");
    drive(127, 127);}
  drive(0,0);
  encoderReset(leftenc);
  mogo(-127);
  wait(1500);
  mogo(0);
  wait(10);
  roller(-127);
  wait(200);
  roller(0);
  while(930 > abs(encoderGet(leftenc))){
    lcdPrint(uart2, 1, "works");
    drive(-127, -127);}
  drive(0,0);
  encoderReset(leftenc);
  while(675 > abs(encoderGet(leftenc))){
    lcdPrint(uart2, 1, "works");
    drive(-127, 127);}
  drive(0,0);
  encoderReset(leftenc);
  while(675 > abs(encoderGet(leftenc))){
    lcdPrint(uart2, 1, "works");
    drive(127, 127);}
  drive(0,0);
  encoderReset(leftenc);
  while(200 > abs(encoderGet(leftenc))){
    lcdPrint(uart2, 1, "works");
    drive(127, -127);}
  drive(0,0);
  mogo(127);
  wait(500);
  mogo(0);
  encoderReset(leftenc);
  while(900 > abs(encoderGet(leftenc))){
    lcdPrint(uart2, 1, "works");
    drive(127, 127);}
  drive(0,0);
}
