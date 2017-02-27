#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "globals.h"
#include "card_info.h"

#define DECK_SIZE 48

#define HAND_SIZE  5
#define IN_PLAY_SIZE 2
#define MAX_ROUNDS 24

#define PLAYER_P 0
#define PLAYER_C 1

#define GAME_MODE_BASIC 0
#define GAME_MODE_ADVANCED 1

#define IMG_BONUS      21
#define IMG_BLANK      0

#define GAME_START_ROUND               0
#define GAME_SHOW_START_ROUND          1
#define GAME_SHOW_DRAW_CARD            2
#define GAME_SHOW_HAND                 3
#define GAME_START_PLAYER_HAND         4
#define GAME_COMPUTER_PLAY_HAND        5
#define GAME_SHOW_COMPUTER_CARD_PLAYED 6
#define GAME_DETERMINE_ROUND_WINNER    7
#define GAME_SHOW_CARDS_IN_PLAY        8
#define GAME_SHOW_WINNER               9

 char deck[DECK_SIZE];
 char player_p_hand[HAND_SIZE];
 char player_c_hand[HAND_SIZE];
 char in_play[IN_PLAY_SIZE];

 char player_p_hand_size = HAND_SIZE;
 char player_c_hand_size = HAND_SIZE;

 char deck_set_up = false;
 char deck_ptr = 0;
 bool card_in_play = false;
 bool deck_drawn = false;
 char drawn_card = -1;

 char last_winner = PLAYER_P;
 char round_count = 0;
 char PLAYER_P_score = 0;
 char PLAYER_C_score = 0;

 char hand_ptr = 0;

 char game_mode = GAME_MODE_BASIC;
 char disp_state = GAME_SHOW_DRAW_CARD;
 char current_suit = SUIT_EARTH;
 
//------------------------

CardInfo get_card_info ( char card) {
  int index = (card * 4);
  CardInfo ret;

  if (card > -1) {
    ret.suit = pgm_read_byte_near(card_info_data + index);
    ret.power = pgm_read_byte_near(card_info_data + (index+1));
    ret.img = pgm_read_byte_near(card_info_data + (index+2));
    ret.text = pgm_read_byte_near(card_info_data + (index+3));
  } else {
    ret.suit = 0;
    ret.power = 0;
    ret.img = 0;
    ret.text = 0;
  }
  return ret;
}

void setup_deck () {
     memset(deck,0,sizeof(deck));
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

void sort_hand(char *hand) {
      for(char i=0; i<(HAND_SIZE-1); i++) {
        for(char o=0; o<(HAND_SIZE-(i+1)); o++) {
                CardInfo currCard  = get_card_info(hand[o]);
                CardInfo nextCard  = get_card_info(hand[o+1]);

                //in advanced game mode, if the current suit == the card's 
                //suit it gets a +1 power boost
                if (game_mode == GAME_MODE_ADVANCED) {
                  if (currCard.suit == current_suit) currCard.power++;
                  if (nextCard.suit == current_suit) nextCard.power++;
                }
                
                if(currCard.power < nextCard.power) {
                    char t = hand[o];
                    hand[o] = hand[o+1];
                    hand[o+1] = t;
                }
        }
    }
}

char get_hand_size(char *hand) {
  char hand_size = HAND_SIZE;
  for(char i=0; i<(HAND_SIZE); i++) {
    if (hand[i] == -1) hand_size--;
  }
  return hand_size;
}

void display_card (char x, char y, char card) {
  char curr_x = x;
  char curr_y = y;
  CardInfo inf = get_card_info(card);

  if (game_mode == GAME_MODE_ADVANCED) {
    if (inf.suit == current_suit) {
      sprites.drawOverwrite(curr_x+32, curr_y, card_8x8, IMG_BONUS);    
    }
  }
  curr_y+=8;
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
  round_count++;
  if (round_count <= MAX_ROUNDS) {
    //empty out in play cards
   card_in_play = false;
   memset(in_play,-1,sizeof(in_play));
   drawn_card = -1;

   //players draw cards
   if (!deck_drawn) drawn_card = draw_from_deck(player_p_hand);
   if (!deck_drawn) draw_from_deck(player_c_hand);

   disp_state = GAME_SHOW_START_ROUND;
  } else {
   disp_state = GAME_SHOW_WINNER;
  }
}

void computer_play_hand(){
  sort_hand(player_c_hand);
  player_c_hand_size = get_hand_size(player_c_hand);

  //if no cards are in play
  if (!card_in_play) {
    //play highest rank card in the hand
    in_play[PLAYER_C] = player_c_hand[0];
    player_c_hand[0] = -1;   
  } else {
    //otherwise 
    //compare card in play to cards in hand
    char card_in_play = in_play[PLAYER_P];
    CardInfo currCard  = get_card_info(card_in_play);
    
    //in advanced game mode, if the current suit == the card's 
    //suit it gets a +1 power boost
    if (game_mode == GAME_MODE_ADVANCED) {
       if (currCard.suit == current_suit) currCard.power++;
    }
    
    //start with lowest rank card by default
    char card_to_play = player_c_hand_size -1;
    //play lowest rank card that has greater power than what is in play
    for (char i=player_c_hand_size-1; i >=0; i--) {
      //cannot play an empty slot
      if (player_c_hand[i] > -1) {
        CardInfo thisCard = get_card_info(player_c_hand[i]);

        if (game_mode == GAME_MODE_ADVANCED) {
          if (thisCard.suit == current_suit) thisCard.power++;
        }
        
        if (thisCard.power > currCard.power) {
          card_to_play = i;
          break;
        }
      } else {
        card_to_play--;
      }
    }
    
    in_play[PLAYER_C] = player_c_hand[card_to_play];
    player_c_hand[card_to_play] = -1;
  }
  if (last_winner == PLAYER_C) {
     disp_state = GAME_SHOW_COMPUTER_CARD_PLAYED;
  } else {
     disp_state = GAME_DETERMINE_ROUND_WINNER;
  }
}

void determine_round_winner() {
   CardInfo pCard  = get_card_info(in_play[PLAYER_P]);
   CardInfo cCard  = get_card_info(in_play[PLAYER_C]);
   
   //in advanced game mode, if the current suit == the card's 
   //suit it gets a +1 power boost
   if (game_mode == GAME_MODE_ADVANCED) {
    if (pCard.suit == current_suit) pCard.power++;
    if (cCard.suit == current_suit) cCard.power++;
   }

   if(pCard.power == cCard.power) {
    if (last_winner == PLAYER_P) {
    //player still wins
    PLAYER_P_score++;
    } else {
    PLAYER_C_score++;      
    }
   } else {
     if(pCard.power > cCard.power) {
      last_winner = PLAYER_P;
      PLAYER_P_score++;
     } else {
      last_winner = PLAYER_C;
      PLAYER_C_score++;
     }
   }
  disp_state = GAME_SHOW_CARDS_IN_PLAY;
}

void startGame() {
     setup_deck();
     shuffle_deck();
     if (game_mode == GAME_MODE_ADVANCED) current_suit = SUIT_EARTH;

     drawn_card = -1;
     round_count = 0;
     
     hand_ptr = 0;

     last_winner = PLAYER_P;
     PLAYER_P_score = 0;
     PLAYER_C_score = 0;

     card_in_play = false;
     deck_drawn = false;
 
     player_p_hand_size = HAND_SIZE;
     player_c_hand_size = HAND_SIZE;
 
     //empty hand
     memset(player_p_hand,-1,sizeof(player_p_hand));
     memset(player_c_hand,-1,sizeof(player_c_hand));
     
     memset(in_play,-1,sizeof(in_play));

     //draw initial cards
     for (char i=0; i < 4; i++) {
      draw_from_deck(player_p_hand);
      draw_from_deck(player_c_hand);
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

void stateShowStartRound() {
      print_progmem(0, 0, text_player);
      print_number(32,0, PLAYER_P_score);
      print_progmem(64, 0, text_computer);
      print_number(104,0, PLAYER_C_score);
    
      print_progmem(36, 16, text_start_round);
      
     if (game_mode == GAME_MODE_ADVANCED) {
       print_progmem(36, 32, text_element);
       sprites.drawOverwrite(48, 48, card_8x8, current_suit + 17);
     }
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
      
         if (!deck_drawn) {
             disp_state = GAME_SHOW_DRAW_CARD;
         } else {
            //use last_winner to detremine who can play first:
            //if last_winner was computer (PLAYER_C) then 
            //call computer_play_hand
            if (last_winner == PLAYER_C) {
              computer_play_hand();
            } else {
               disp_state = GAME_START_PLAYER_HAND;
            }
         }
    }
}

void stateShowDrawCard() {
    print_progmem(36, 0, text_your_draw);
    display_card (36,8,drawn_card);
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
      //use last_winner to detremine who can play first:
      //if last_winner was computer (PLAYER_C) then 
      //call computer_play_hand
      if (last_winner == PLAYER_C) {
          computer_play_hand();
      } else {
          disp_state = GAME_START_PLAYER_HAND;
      }      
    }
}

void stateStartPlayerHand () {
  hand_ptr = 0;
  sort_hand(player_p_hand);
  player_p_hand_size = get_hand_size(player_p_hand);
  disp_state = GAME_SHOW_HAND;
}

void stateShowHand () {
  print_progmem(20, 0, text_pick_card_to_play);
  print_number (100, 0, player_p_hand_size);
  
  //draw forward to hand_ptr
  for (char i=0; i < hand_ptr; i++) {
       display_card((i*8) + 16,8,player_p_hand[i]);
  }

  for (char i=player_p_hand_size-1; i > (hand_ptr-1); i--) {
       display_card((i*8) + 16,8,player_p_hand[i]);
  }
  if (arduboy.justPressed(RIGHT_BUTTON) && (hand_ptr < player_p_hand_size)) hand_ptr++;
  if (arduboy.justPressed(LEFT_BUTTON) && (hand_ptr > 0)) hand_ptr--;
  if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
    in_play[PLAYER_P] = player_p_hand[hand_ptr];
    player_p_hand[hand_ptr] = -1;

    if (last_winner == PLAYER_C) {
        disp_state = GAME_DETERMINE_ROUND_WINNER;
    } else {
        card_in_play = true;
        disp_state = GAME_COMPUTER_PLAY_HAND;
    }

  }
}

void stateShowComputerCardPlayed() {
    print_progmem(36, 0, text_computer_played);
    display_card (36,8,in_play[PLAYER_C]);
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) {
      disp_state = GAME_START_PLAYER_HAND;
    }
}

void stateShowCardsInPlay() {
    print_progmem(0, 0, text_player);
    print_number(32,0, PLAYER_P_score);
    print_progmem(64, 0, text_computer);
    print_number(104,0, PLAYER_C_score);
    if (in_play[PLAYER_P] > -1) {
      if (last_winner == PLAYER_P) print_progmem(8, 8, text_win);
      display_card (0,8,in_play[PLAYER_P]);
    }
    if (in_play[PLAYER_C] > -1) {
      if (last_winner == PLAYER_C) print_progmem(72, 8, text_win);
      display_card (64,8,in_play[PLAYER_C]);
    }
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) 
    {
      if (game_mode == GAME_MODE_ADVANCED) current_suit++;
      if (current_suit > 3) current_suit = 0;
      disp_state = GAME_START_ROUND;
    }
}

void stateShowWinner() {
    print_progmem(0, 0, text_player);
    print_number(32,0, PLAYER_P_score);
    print_progmem(64, 0, text_computer);
    print_number(104,0, PLAYER_C_score);

    if (PLAYER_P_score > PLAYER_C_score) {
      //player wins
      print_progmem(44, 16, text_win);
      sprites.drawSelfMasked(44, 24, player_win_24x24, 0);
      print_progmem(44, 56, text_player);
      
    } else {
      if (PLAYER_C_score > PLAYER_P_score) {
        //computer wins
        print_progmem(44, 16, text_win);
        sprites.drawSelfMasked(44, 24, computer_win_24x24, 0);
        print_progmem(44, 56, text_computer);
      } else {
        //tie
        print_progmem(44, 16, text_tie);
      }
    }
    
    if (arduboy.justPressed(A_BUTTON | B_BUTTON)) 
    {
      gameState = STATE_MENU_MAIN;
    }
}

void stateGamePlaying()
{
  gameState = STATE_GAME_PLAYING;
  switch (disp_state) {
    case GAME_START_ROUND:
       start_play_round();
       break;
    
    case GAME_SHOW_START_ROUND:
       stateShowStartRound();
       break;
    
    case GAME_SHOW_DRAW_CARD:
       stateShowDrawCard();
       break;

    case GAME_START_PLAYER_HAND:
       stateStartPlayerHand();
       break;
       
    case GAME_SHOW_HAND:
       stateShowHand();
       break;      

    case GAME_COMPUTER_PLAY_HAND:
       computer_play_hand();
       break; 

    case GAME_SHOW_COMPUTER_CARD_PLAYED:
       stateShowComputerCardPlayed();
       break;

    case GAME_DETERMINE_ROUND_WINNER:
       determine_round_winner();
       break;        

    case GAME_SHOW_CARDS_IN_PLAY:
       stateShowCardsInPlay();
       break;

    case GAME_SHOW_WINNER:
       stateShowWinner();
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
