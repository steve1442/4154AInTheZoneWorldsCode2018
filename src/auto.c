#include "main.h"//it includes min h because main h has been bullied

void secondarything()//secondary thing
{
  secondaryLift(127); // have it out already
  wait(500); // because idk if we will have a sensor
  secondaryLift(0); // stop
}

void drivetask(void * ignore)//drive
{
  holdtheline(2000, 127); // go to the mogo
}

void mogotask(void * ignore)//mom go get me 1 cocaine
{
  mogo(127); // open out to get the mogo
  wait(800); // we dont fucking have a sensor on the mogo
  mogo(0); // seriously stop
}

void mogointask(void * ignore)
{
  mogo(-127);
  wait(900);
  mogo(0);
}

void outtaketask()//outtakes the task
{
  roller(-127);//rolls2.0
  wait(100);//waits
  roller(15);//rolls
}

void anothercone(void * ignore)
{
  holdtheline(100, 127);
}

void auton1()
{
  lcdPrint(uart1, 1, "auton");
  TaskHandle UPDATE = taskRunLoop(update, 5); // updates motors throughout the code
  TaskHandle DRIVETASK = taskCreate(drivetask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT); // starts drive task to drive up to the mogo
  TaskHandle MOGOTASK = taskCreate(mogotask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT); // opens the mogo same time as the drive task running to optimize time
  while(taskGetState(DRIVETASK) != TASK_RUNNABLE) {delay(5);} // wait for the drive task to be finished because the mogo task will end first
  taskDelete(DRIVETASK); // clearing up tasks that wont be used
  taskDelete(MOGOTASK);
  outtaketask(); // only runs the out take task because it should be the only thing running at this time
  TaskHandle MOGOINTASK = taskCreate(mogointask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT); // brings the mogo in with a task because i want it to move forward to the next cone same time as bringing the mogo in for better use of time
  wait(100); // giving a short pause inbetween the 2 tasks so that the mogo can be brought in a little so it doenst hit the next cone
  TaskHandle ANOTHERCONE = taskCreate(anothercone, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT); // drives up to the first cone but it should be the same
  while(taskGetState(ANOTHERCONE) != TASK_RUNNABLE){ delay(5);} // waits for the drive task to finish
  /* Not sure what to do with this because timing may be perfet to get cones while driving*/
  taskDelete(MOGOINTASK);
  taskDelete(UPDATE); // Is the end of the code
}

void auton2()
{
  TaskHandle UPDATE = taskRunLoop(update, 5); // updates motors throughout the code
  lift(127, 127);
  wait(100);
  lift(0, 0);
  mogo(127);
  wait(1075);
  mogo(0);
  holdtheline(1660, 100);
  mogo(-127);
  wait(1000);
  mogo(0);
  holdtheline(-1640, -100);
  encoderReset(leftenc);
  encoderReset(rightenc);
  while(abs(encoderGet(leftenc)) < 700)
  {
    drive(-127, 127);
    wait(5);
  }
  drive(0,0);
  holdtheline(600, 100);
  encoderReset(leftenc);
  encoderReset(rightenc);
  while(abs(encoderGet(leftenc)) < 464)
  {
    drive(-127, 127);
    wait(5);
  }
  drive(0,0);
  holdtheline(680, 100);
  mogo(127);
  wait(700);
  mogo(0);
  holdtheline(-100, -100);
  taskDelete(UPDATE);
}

void auton3()
{
  TaskHandle UPDATE = taskRunLoop(update, 5); // updates motors throughout the code
  lift(127, 127);
  wait(100);
  lift(0, 0);
  mogo(127);
  wait(1075);
  mogo(0);
  holdtheline(1660, 100);
  mogo(-127);
  wait(1000);
  mogo(0);
  holdtheline(-1640, -100);
  encoderReset(leftenc);
  encoderReset(rightenc);
  while(abs(encoderGet(leftenc)) < 700)
  {
    drive(127, -127);
    wait(5);
  }
  drive(0,0);
  holdtheline(600, 100);
  encoderReset(leftenc);
  encoderReset(rightenc);
  while(abs(encoderGet(leftenc)) < 464)
  {
    drive(127, -127);
    wait(5);
  }
  drive(0,0);
  holdtheline(680, 100);
  mogo(127);
  wait(700);
  mogo(0);
  holdtheline(-100, -100);
  taskDelete(UPDATE);
}

void auton4()
{
  TaskHandle UPDATE = taskRunLoop(update, 5); // updates motors throughout the code
  lift(127, 127);
  wait(100);
  lift(0, 0);
  mogo(127);
  wait(1075);
  mogo(0);
  holdtheline(1660, 100);
  mogo(-127);
  wait(1000);
  mogo(0);
  holdtheline(-1640, -100);
  encoderReset(leftenc);
  encoderReset(rightenc);
  while(abs(encoderGet(leftenc)) < 700)
  {
    drive(-127, 127);
    wait(5);
  }
  drive(0,0);
  holdtheline(600, 100);
  encoderReset(leftenc);
  encoderReset(rightenc);
  while(abs(encoderGet(leftenc)) < 464)
  {
    drive(-127, 127);
    wait(5);
  }
  drive(0,0);
  holdtheline(680, 100);
  mogo(127);
  wait(700);
  mogo(0);
  holdtheline(-100, -100);
  taskDelete(UPDATE);
}
void autonomous()
{
  switch(selectedauton)
  {
    case 1: auton1(); break;
    case 2: auton2(); break;
    case 3: auton3(); break;
    case 4: auton4(); break;
    default:break;
  }
}
