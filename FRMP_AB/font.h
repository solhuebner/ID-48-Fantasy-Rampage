#ifndef FONT_H
#define FONT_H

#include "globals.h"

void print_progmem(uint8_t x, uint8_t y, const char str[]) {
  char c;
  while ((c = pgm_read_byte(str))) {
    str++;
    sprites.drawSelfMasked(x,y,fontSmall, c-32);
    x+= 4;
  }
}

void print_p(uint8_t x, uint8_t y, const char* s) {
  for (char c=0; s[c] != '\0'; c++)
  {
    sprites.drawSelfMasked(x,y,fontSmall, s[c]-32);
    x +=4;
  }
}

void print_number(uint8_t x, uint8_t y, int n) {
  char buf[8];
  print_p(x,y,itoa(n, buf, 10));

}
#endif
