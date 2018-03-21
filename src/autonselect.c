#include "main.h"

int selectedauton=0, var=0, max=5, min=1, lcdlastvaluart1 = 0, lcdlastvaluart2 = 0;

void autonselect()
{
  int breakloop = true;
  while(breakloop)
  {
    if((lcdReadButtons(uart1) == LCD_BTN_LEFT && lcdlastvaluart1 != LCD_BTN_LEFT) || (lcdReadButtons(uart2) == LCD_BTN_LEFT && lcdlastvaluart2 != LCD_BTN_LEFT)){var-=1;}
    else if((lcdReadButtons(uart1) == LCD_BTN_CENTER && lcdlastvaluart1 != LCD_BTN_CENTER) || (lcdReadButtons(uart2) == LCD_BTN_CENTER && lcdlastvaluart2 != LCD_BTN_CENTER)){selectedauton=var; breakloop = false;}
    else if((lcdReadButtons(uart1) == LCD_BTN_RIGHT && lcdlastvaluart1 != LCD_BTN_RIGHT) || (lcdReadButtons(uart2) == LCD_BTN_RIGHT && lcdlastvaluart2 != LCD_BTN_RIGHT)){var+=1;}
    if(var > max){var=min;}
    else if(var < min){var=max;}
    switch(var)
    {
      case 1:
      lcdPrint(uart2, 1, "Auton 1");
      lcdPrint(uart2, 2, "Red left");
      lcdPrint(uart1, 1, "Auton 1");
      lcdPrint(uart1, 2, "Red left");
      break;
      case 2:
      lcdPrint(uart2, 1, "Auton 2");
      lcdPrint(uart2, 2, "Red right");
      lcdPrint(uart1, 1, "Auton 2");
      lcdPrint(uart1, 2, "Red right");
      break;
      case 3:
      lcdPrint(uart2, 1, "Auton 3");
      lcdPrint(uart2, 2, "Blue left");
      lcdPrint(uart1, 1, "Auton 3");
      lcdPrint(uart1, 2, "Blue left");
      break;
      case 4:
      lcdPrint(uart2, 1, "Auton 4");
      lcdPrint(uart2, 2, "Blue right");
      lcdPrint(uart1, 1, "Auton 4");
      lcdPrint(uart1, 2, "Blue right");
      break;
      default:
      lcdPrint(uart2, 1, "No Auton");
      lcdPrint(uart2, 2, ";( sad times");
      lcdPrint(uart1, 1, "No Auton");
      lcdPrint(uart1, 2, ";( sad times");
      break;
    }
    lcdlastvaluart1 = lcdReadButtons(uart1); lcdlastvaluart2 = lcdReadButtons(uart2);
    delay(5);
  }
}
