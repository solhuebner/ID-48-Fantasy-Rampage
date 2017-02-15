#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"

struct Players
{
  public:
    int x;
    int y;
    boolean walking;
    byte direction;
    byte frame;
    unsigned long score; 
};

Players player = { .x = 20, .y = 20, .walking = false, .direction = FACING_SOUTH, .frame = 0 };

void drawPlayer()
{
  if (arduboy.everyXFrames(6) && player.walking) player.frame++;
  if (player.frame > 3 ) player.frame = 0;
  sprites.drawErase(player.x, player.y, player_4D_mask, player.frame + 4 * player.direction);
  sprites.drawSelfMasked(player.x, player.y, player_4D, player.frame + 4 * player.direction);
}

#endif
