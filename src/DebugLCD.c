#include "main.h"

int debugScreen = 0, lastDebugJT = 0, lcddebuglastvaluart1 = 0, lcddebuglastvaluart2 = 0;
const int maxMenus = 6, bound = 100;
char fuck[] = {" shit it worked "};
void LCDDebugScreens()
{
  int debugJT = joystickGetAnalog(1, 4);
  if(bound <= abs(debugJT) && bound > abs(lastDebugJT)){debugScreen = (debugScreen + maxMenus + debugJT/abs(debugJT)) % maxMenus;}
  if((lcdReadButtons(uart1) == LCD_BTN_LEFT && lcddebuglastvaluart1 != LCD_BTN_LEFT) || (lcdReadButtons(uart2) == LCD_BTN_LEFT && lcddebuglastvaluart2 != LCD_BTN_LEFT)){debugScreen-=1;}
  else if((lcdReadButtons(uart1) == LCD_BTN_CENTER && lcddebuglastvaluart1 != LCD_BTN_CENTER) || (lcdReadButtons(uart2) == LCD_BTN_CENTER && lcddebuglastvaluart2 != LCD_BTN_CENTER)){}
  else if((lcdReadButtons(uart1) == LCD_BTN_RIGHT && lcddebuglastvaluart1 != LCD_BTN_RIGHT) || (lcdReadButtons(uart2) == LCD_BTN_RIGHT && lcddebuglastvaluart2 != LCD_BTN_RIGHT)){debugScreen+=1;}
  if(debugScreen > maxMenus){debugScreen=0;}
  else if(debugScreen < 0){debugScreen=maxMenus;}
  switch(debugScreen)
  {
    case 0:
    lcdPrint(uart2, 1, "   Main Bat %d", powerLevelMain());
    lcdPrint(uart2, 2, "Back-up Bat %d", powerLevelMain());
    lcdPrint(uart1, 1, "   Main Bat %d", powerLevelMain());
    lcdPrint(uart1, 2, "Back-up Bat %d", powerLevelMain());
    break;
    case 1:
    lcdPrint(uart2, 1, fuck);
    lcdPrint(uart2, 2, "runtime:  %lum%lus", millis()/60000, millis()%60000/1000);
    lcdPrint(uart1, 1, fuck);
    lcdPrint(uart1, 2, "runtime:  %lum%lus", millis()/60000, millis()%60000/1000);
    break;
    case 2:
    lcdPrint(uart2, 1, "Left Lift %d", encoderGet(leftliftenc));
    lcdPrint(uart2, 2, "Right Lift %d", encoderGet(rightliftenc));
    lcdPrint(uart1, 1, "Left Lift %d", encoderGet(leftliftenc));
    lcdPrint(uart1, 2, "Right Lift %d", encoderGet(rightliftenc));
    break;
    case 3:
    lcdPrint(uart2, 1, "leftD %d", encoderGet(leftenc));
    lcdPrint(uart2, 2, "rightD %d", encoderGet(rightenc));
    lcdPrint(uart1, 1, "leftD %d", encoderGet(leftenc));
    lcdPrint(uart1, 2, "rightD %d", encoderGet(rightenc));
    break;
    case 4:
    lcdPrint(uart2, 1, "leftL %d", analogRead(1));
    lcdPrint(uart2, 2, "rightL %d", analogRead(2));
    lcdPrint(uart1, 1, "leftL %d", analogRead(1));
    lcdPrint(uart1, 2, "rightL %d", analogRead(2));
    break;
    case 5:
    lcdPrint(uart2, 1, "Gyro %d", analogRead(2));
    lcdPrint(uart2, 2, "Light %d", analogRead(3));
    lcdPrint(uart1, 1, "Gyro %d", analogRead(2));
    lcdPrint(uart1, 2, "Light %d", analogRead(3));
    break;
    case 6:
    lcdPrint(uart2, 1, "X %d", joystickGetAnalog(1, 5));
    lcdPrint(uart2, 2, "Y %d", joystickGetAnalog(1, 6));
    lcdPrint(uart1, 1, "X %d", joystickGetAnalog(1, 5));
    lcdPrint(uart1, 2, "Y %d", joystickGetAnalog(1, 6));
    break;
    default:
    lcdPrint(uart2, 1, "Error");
    lcdPrint(uart2, 2, "No Debug Screen");
    lcdPrint(uart1, 1, "Error");
    lcdPrint(uart1, 2, "No Debug Screen");
    break;
  }
  lcddebuglastvaluart1 = lcdReadButtons(uart1);
  lcddebuglastvaluart2 = lcdReadButtons(uart2);
  lastDebugJT = debugJT;
  konamicodefunc();
  delay(2);
}

void LCDSetUp(bool backlight)
{
  lcdInit(uart2);
  lcdSetBacklight(uart2, backlight);
  lcdInit(uart1);
  lcdSetBacklight(uart1, backlight);
}
