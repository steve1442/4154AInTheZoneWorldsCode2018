#include "main.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  The shit idea alessandro had me follow through with(help i am held aagainst my will HELP HELP HELP HELP HELP HELP.JPEG.POV.PNG.COM.ORG.NET.CO.UK.CO.CE.)                    //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int counter = 0, pass = 0;

// the level they gon be playin
char channel1[2000]={" |                        o                            "};
char channel2[2000]={" |             o                     o                 "};
char channel3[2000]={" |                                            o        "};
char channel4[2000]={" |                                  o                  "};
              //      123456789012345678901234567890
void game(){
  bool brokeit = true; // get out of the whileloop
while(brokeit){ // game loop
  // the display part
  lcdPrint(uart1, 1, "%c|%c%c%c%c%c%c%c%c%c%c%c%c%c%c", channel1[1 + pass], channel1[3 + pass], channel1[4 + pass], channel1[5 + pass], channel1[6 + pass], channel1[7 + pass], channel1[8 + pass], channel1[9 + pass]
  , channel1[10 + pass], channel1[11 + pass], channel1[12 + pass], channel1[13 + pass], channel1[14 + pass], channel1[15 + pass], channel1[16 + pass]);
  lcdPrint(uart1, 2, "%c|%c%c%c%c%c%c%c%c%c%c%c%c%c%c", channel2[1 + pass + pass], channel2[3 + pass], channel2[4 + pass], channel2[5 + pass], channel2[6 + pass], channel2[7 + pass], channel2[8 + pass]
  , channel2[9 + pass], channel2[10 + pass], channel2[11 + pass], channel2[12 + pass], channel2[13 + pass], channel2[14 + pass], channel2[15 + pass], channel2[16 + pass]);
  lcdPrint(uart2, 1, "%c|%c%c%c%c%c%c%c%c%c%c%c%c%c%c", channel3[1 + pass], channel3[3 + pass], channel3[4 + pass], channel3[5 + pass], channel3[6 + pass], channel3[7 + pass], channel3[8 + pass], channel3[9 + pass]
  , channel3[10 + pass], channel3[11 + pass], channel3[12 + pass], channel3[13 + pass], channel3[14 + pass], channel3[15 + pass], channel3[16 + pass]);
  lcdPrint(uart2, 2, "%c|%c%c%c%c%c%c%c%c%c%c%c%c%c%c", channel4[1 + pass + pass], channel4[3 + pass], channel4[4 + pass], channel4[5 + pass], channel4[6 + pass], channel4[7 + pass], channel4[8 + pass]
  , channel4[9 + pass], channel4[10 + pass], channel4[11 + pass], channel4[12 + pass], channel4[13 + pass], channel4[14 + pass], channel4[15 + pass], channel4[16 + pass]);
  wait(1000);
  // the control part
  if(channel1[0] == 'o' && joystickGetDigital(1, 5, JOY_UP))
  {
    counter += 1;
    speakerPlayRtttl("test:d=4,o=5,b=100:16e6");
  }
  else if(channel2[0] == 'o' && joystickGetDigital(1, 5, JOY_DOWN))
  {
    counter += 1;
    speakerPlayRtttl("test:d=4,o=5,b=100:16e6");
  }
  else if(channel3[0] == 'o' && joystickGetDigital(1, 6, JOY_UP))
  {
    counter += 1;
    speakerPlayRtttl("test:d=4,o=5,b=100:16e6");
  }
    else if(channel4[0] == 'o' && joystickGetDigital(1, 6, JOY_DOWN))
    {counter += 1; speakerPlayRtttl("test:d=4,o=5,b=100:16e6");}
    if(pass == 59){ brokeit = false;} // the way out
    delay(5); pass += 1;
  }
  bool borkit = true; // way out of displaying score
  while(borkit){  // display score
    lcdPrint(uart1, 1, "score: %d", counter);
    lcdPrint(uart1, 2, "score: %d", counter);
    lcdPrint(uart2, 1, "score: %d", counter);
    lcdPrint(uart2, 2, "score: %d", counter);
    if(lcdReadButtons(uart1) != 0 || lcdReadButtons(uart2) != 0){ borkit = false;}
    delay(5);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                    Steve's Chad Game Unlike the idea i had above that ale wanted                       //
////////////////////////////////////////////////////////////////////////////////////////////////////////////

char map[2][17] = {{"                "},
{"                "}};

void bettergame()
{
  lcdPrint(uart2, 2, "map[2]");
  lcdPrint(uart1, 1, "map[1]");
  int score = 0, hp = 2, playery = 1, wall1[3], wall2[3], wall3[3], wall4[3];
  bool bettergameloop = true;
  while(bettergameloop){
    //for(int i = 0; i > 16; i++){map[0][i] = ' ';map[1][i] = ' ';}
/*    wall1[0]--;wall1[1]--;
    wall2[0]--;wall2[1]--;
    wall3[0]--;wall3[1]--;
    wall4[0]--;wall4[1]--;
    if(wall1[0] == 0){wall1[2] = 0;}
    if(wall2[0] == 0){wall2[2] = 0;}
    if(wall3[0] == 0){wall3[2] = 0;}
    if(wall4[0] == 0){wall4[2] = 0;}
    if(wall1[2] == 0){wall1[2] = 1;wall1[0] = (rand() % 16) + 16;wall1[1] = rand() % 2;}
    if(wall2[2] == 0){wall2[2] = 1;wall2[0] = (rand() % 16) + 16;wall2[1] = rand() % 2;}
    if(wall3[2] == 0){wall3[2] = 1;wall3[0] = (rand() % 16) + 16;wall3[1] = rand() % 2;}
    if(wall4[2] == 0){wall4[2] = 1;wall4[0] = (rand() % 16) + 16;wall4[1] = rand() % 2;}
    map[wall1[1]][wall1[0]] = '|';
    map[wall2[1]][wall2[0]] = '|';
    map[wall3[1]][wall3[0]] = '|';
    map[wall4[1]][wall4[0]] = '|';
    if(map[playery][4] == '|'){hp--;}*/
    if(joystickGetAnalog(1, 3) > 50){playery = 0;}
    else if(joystickGetAnalog(1, 3) < -50){playery = 1;}
    if(hp == 2){map[playery][4] = 'o';}
    else if(hp > 3){hp = 3;}
    else if(hp == 3){map[playery][4] = '0';}
    else if(hp < 1){bettergameloop = false;}
    else{map[playery][4] = 'O';}
  }
  bettergameloop = true;
  while(bettergameloop)
  {
    lcdPrint(uart1, 1, "   GAME  OVER   ");
    lcdPrint(uart1, 2, "Score: %d       ", score);
    if(lcdReadButtons(uart1) == LCD_BTN_CENTER){bettergameloop=false;}
  }
}
