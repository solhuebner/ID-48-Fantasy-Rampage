#ifndef FONT_H
#define FONT_H

#include "globals.h"

void print_progmem(uint8_t x, uint8_t y, const char str[]) {
  char c;
  while ((c = pgm_read_byte(str))) {
    str++;
    x+= 4;
    sprites.drawSelfMasked(x,y,font_4x6, c-32);
  }
}
#endif
