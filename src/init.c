#include "main.h"

void initializeIO() {

}

void initialize() {
  LCDSetUp(true);
  leftenc = encoderInit(5, 6, false);
  rightenc = encoderInit(3, 4, false);
  leftliftenc = encoderInit(7, 8, false);
  rightliftenc = encoderInit(9, 10, false);
  gyro = gyroInit(5, 1);
  autonselect();
}
