#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "globals.h"
#include "card_info.h"

#define DECK_SIZE 48

#define HAND_SIZE  5
#define IN_PLAY_SIZE 2
#define MAX_ROUNDS 24

#define PLAYER_1 0
#define PLAYER_2 1

#define GAME_MODE_BASIC 0
#define GAME_MODE_ADVANCED 1

#define GAME_SHOW_DRAW_CARD   0
#define GAME_SHOW_HAND        1
#define GAME_SHOW_CARD_PLAYED 2


 char deck[DECK_SIZE];
 char player1_hand[HAND_SIZE];
 char player2_hand[HAND_SIZE];
 char in_play[IN_PLAY_SIZE];

 char deck_ptr = 0;
 bool card_in_play = false;
 bool deck_drawn = false;
 char drawn_card = -1;

 char last_winner = PLAYER_1;
 char round_count = 0;
 char player_1_score = 0;
 char player_2_score = 0;

 char hand_ptr = 0;

 char game_mode = GAME_MODE_BASIC;
 char disp_state = GAME_SHOW_DRAW_CARD;
 char current_suit = SUIT_EARTH;
 
//------------------------

CardInfo get_card_info ( char card) {
  int index = (card * 4);
  CardInfo ret;
  ret.suit = pgm_read_byte_near(card_info_data + index);
  ret.power = pgm_read_byte_near(card_info_data + (index+1));
  ret.img = pgm_read_byte_near(card_info_data + (index+2));
  ret.text = pgm_read_byte_near(card_info_data + (index+3));
  return ret;
}

void setup_deck () {
  for ( char i=0; i< DECK_SIZE; i++) {
    deck[i] = i;
  }
}

void shuffle_deck() {
  for ( char a=DECK_SIZE-1; a> 0; a--)
  {
     char r = random(a+1);
    if (r != a)
   {
      char temp = deck[a];
     deck[a] = deck[r];
     deck[r] = temp;
   }
  }
}

char draw_from_deck( char *hand) {
  //find first empty space in hand
   char empty_spot_ptr = 0;
  for (char i=0; i < HAND_SIZE; i++) {
    if (hand[i] == -1) {
      empty_spot_ptr = i;
      break;
    }
  }
 char draw = deck[deck_ptr];
 hand[empty_spot_ptr] = draw;
 deck_ptr++;
 if (deck_ptr == DECK_SIZE) deck_drawn = true; 

 return draw;
}

void display_card (char x, char y, char card) {
  char curr_x = x;
  char curr_y = y;
  CardInfo inf = get_card_info(card);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, inf.suit + 1);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 11);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 11);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, inf.power + 1);
  curr_y+=8;
  curr_x = x;
  for (char i=0; i< 4; i++) {
    sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 12);
    sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 0);
    sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 0);
    sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 13);
    curr_y+=8;
    curr_x = x;
  }
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 14);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 15);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 15);
  sprites.drawOverwrite(curr_x+=8, curr_y, card_8x8, 16);
  
  sprites.drawOverwrite(x+16, y+16, monsters, inf.img);
}

void start_play_round() {
    //empty out in play cards
   card_in_play = false;
   memset(in_play,-1,sizeof(in_play));

   //players draw cards
   if (!deck_drawn) drawn_card = draw_from_deck(player1_hand);
   if (!deck_drawn) draw_from_deck(player2_hand);

   disp_state = GAME_SHOW_DRAW_CARD;
}

void startGame() {
     setup_deck();
     shuffle_deck();
     if (game_mode == GAME_MODE_ADVANCED) current_suit = SUIT_EARTH;

     drawn_card = -1;
     
     //empty hand
     memset(player1_hand,-1,sizeof(player1_hand));
     memset(player2_hand,-1,sizeof(player2_hand));

     //draw initial cards
     for (char i=0; i < 4; i++) {
      draw_from_deck(player1_hand);
      draw_from_deck(player2_hand);
     }

     start_play_round();
}

//------------------------
void stateMenuPlay()
{
  gameState = STATE_GAME_SELECT_MODE;
};

void stateGameSelectGameMode() {
  gameState = STATE_GAME_SELECT_MODE;
  print_progmem(24,12,text_select_game_mode);
  print_progmem(32,24,text_basic);
  print_progmem(32,36,text_advanced); 

  if (arduboy.justPressed(UP_BUTTON)) game_mode = GAME_MODE_BASIC;
  if (arduboy.justPressed(DOWN_BUTTON)) game_mode = GAME_MODE_ADVANCED;
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    startGame();
    gameState = STATE_GAME_PLAYING;
  }
  print_progmem(26,24 + (game_mode * 12),text_pointer);
}

void stateShowDrawCard() {
    print_progmem(36, 0, text_your_draw);
    display_card (36,8,drawn_card);
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) disp_state = GAME_SHOW_HAND;
}

void stateShowHand () {
  print_progmem(20, 0, text_pick_card_to_play);
  
  //draw forward to hand_ptr
  for (char i=0; i < hand_ptr; i++) {
    display_card((i*8) + 16,8,player1_hand[i]);
  }
  for (char i=HAND_SIZE-1; i > (hand_ptr-1); i--) {
    display_card((i*8) + 16,8,player1_hand[i]);
  }
  if (arduboy.justPressed(RIGHT_BUTTON) && (hand_ptr < HAND_SIZE)) hand_ptr++;
  if (arduboy.justPressed(LEFT_BUTTON) && (hand_ptr > 0)) hand_ptr--;
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) disp_state = GAME_SHOW_CARD_PLAYED;
}

void stateShowCardPlayed() {
    display_card (36,8,player1_hand[hand_ptr]);
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) disp_state = GAME_SHOW_HAND;
}
void stateGamePlaying()
{
  gameState = STATE_GAME_PLAYING;
  switch (disp_state) {
    case GAME_SHOW_DRAW_CARD:
       stateShowDrawCard();
       break;
       
    case GAME_SHOW_HAND:
       stateShowHand();
       break;      

    case GAME_SHOW_CARD_PLAYED:
       stateShowCardPlayed();
       break;
  }
};

void stateGamePause()
{
  if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_PLAYING;
};

void stateGameOver()
{
};

//-----------

#endif
