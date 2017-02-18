#ifndef MENU_H
#define MENU_H

#include "globals.h"
#include "font.h"

void stateMenuIntro()
{
  globalCounter++;
  sprites.drawSelfMasked(34, 0, T_arg, 0);
  if (globalCounter > 180) gameState = STATE_MENU_MAIN;
}

void stateMenuMain()
{
  sprites.drawSelfMasked(38, 0, logo_48x42, 0);
  print_progmem(38,52,text_2017_trodoss);
  print_progmem(8,58,text_help);
  print_progmem(32,58,text_play);
  print_progmem(56,58,text_info);
  print_progmem(84,58,text_sound);
  
  if (arduboy.justPressed(RIGHT_BUTTON) && (menuSelection < 5)) menuSelection++;
  if (arduboy.justPressed(LEFT_BUTTON) && (menuSelection > 2)) menuSelection--;
  if (arduboy.justPressed(B_BUTTON)) gameState = menuSelection;
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
