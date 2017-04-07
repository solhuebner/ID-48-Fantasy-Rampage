#ifndef MENU_H
#define MENU_H

#include "globals.h"
#include "font.h"
#include "song_data.h"

#define SMALL_MONSTERS_ON_ONE_LINE                      8

struct Monsters
{
  public:
    int x, y;
    byte frame;
};

Monsters smallMonster[(SMALL_MONSTERS_ON_ONE_LINE * 2)];

byte smallMonsterLineOne;
byte smallMonsterLineTwo;


void setSmallMonster()
{
  smallMonsterLineOne = 0;
  smallMonsterLineTwo = 0;
  for (byte i = 0; i < (SMALL_MONSTERS_ON_ONE_LINE * 2); i++)
  {
    if (i < SMALL_MONSTERS_ON_ONE_LINE)
    {
      smallMonster[i].x = i * 20;
      smallMonster[i].y = 2;
      smallMonster[i].frame = smallMonsterLineOne;
      smallMonsterLineOne++;
    }
    else
    {
      smallMonster[i].x = (i - SMALL_MONSTERS_ON_ONE_LINE) * 20;
      smallMonster[i].y = 46;
      smallMonster[i].frame = smallMonsterLineTwo;
      smallMonsterLineTwo++;
    }
  }
}


void drawTitleScreen()
{
  if (arduboy.everyXFrames(1))
  {
    for (byte i = 0; i < (SMALL_MONSTERS_ON_ONE_LINE * 2); i++)
    {
      if (i < SMALL_MONSTERS_ON_ONE_LINE)
      {
        smallMonster[i].x--;
        if (smallMonster[i].x < -16)
        {
          smallMonster[i].x = 144;
          smallMonster[i].frame = smallMonsterLineOne;
          smallMonsterLineOne = (++smallMonsterLineOne)%24;

        }
      }
      else
      {
        smallMonster[i].x++;
        if (smallMonster[i].x > 144)
        {
          smallMonster[i].x = -16;
          smallMonster[i].frame = smallMonsterLineTwo;
          smallMonsterLineTwo = (++smallMonsterLineTwo)%24;
        }
      }
    }

  }
  sprites.drawSelfMasked(0, 21, titleName, 0);
  sprites.drawSelfMasked(64, 21, titleName, 1);

  for (byte i = 0; i < (SMALL_MONSTERS_ON_ONE_LINE * 2); i++) sprites.drawSelfMasked(smallMonster[i].x, smallMonster[i].y, monstersSmall, smallMonster[i].frame);
}

void stateMenuIntro()
{
  globalCounter++;
  sprites.drawSelfMasked(34, 0, T_arg, 0);
  if (globalCounter > 120)
  {
    gameState = STATE_MENU_MAIN;
    setSmallMonster();
  }
}

void stateMenuMain()
{
  #ifndef AB_DEVKIT
  ATM.play(music);
  #endif

  drawTitleScreen();
  print_progmem(8, 36, text_help);
  print_progmem(32, 36, text_play);
  print_progmem(56, 36, text_info);
  print_progmem(84, 36, text_sound);

  if (arduboy.justPressed(RIGHT_BUTTON) && (menuSelection < 5)) menuSelection++;
  if (arduboy.justPressed(LEFT_BUTTON) && (menuSelection > 2)) menuSelection--;
  if (arduboy.justPressed(B_BUTTON)) {

  #ifndef AB_DEVKIT
  ATM.stop();
  #endif
  
    gameState = menuSelection;
  }
}

void stateMenuHelp()
{
  //  for (byte i = 0; i < 2; i++) sprites.drawSelfMasked(32, 32 * i, qrcode, i);
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}


void stateMenuInfo()
{
  //  sprites.drawSelfMasked(16, 36, info, 0);
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) gameState = STATE_MENU_MAIN;
}

void stateMenuSoundfx()
{
  //  sprites.drawSelfMasked(28, 8, titleScreen, 0);
  if (arduboy.justPressed(RIGHT_BUTTON)) arduboy.audio.on();
  if (arduboy.justPressed(LEFT_BUTTON)) arduboy.audio.off();
  if (arduboy.justPressed(A_BUTTON | B_BUTTON))
  {
    arduboy.audio.saveOnOff();
    gameState = STATE_MENU_MAIN;
  }
}


#endif
