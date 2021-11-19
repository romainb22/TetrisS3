#ifndef _MAIN_C_
#define _MAIN_C_

#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <unistd.h>
#include <time.h>
#include "display.h"
#include "structure.h"

int check_if_full(game *myGame){
  int i,j;
  for(i=0;i<G_BOARD_WIDTH;i++){
    for(j=0;j<2;j++){
      if(myGame->gameBoard[i][j]){
        return 1;
      }
    }
  }
  return 0;
}

int convert_move(MLV_Keyboard_button myKey){
  if(myKey == MLV_KEYBOARD_LEFT || myKey == MLV_KEYBOARD_q){
    return 1;
  }
  if(myKey == MLV_KEYBOARD_UP || myKey == MLV_KEYBOARD_z){
    return 5;
  }
  if(myKey == MLV_KEYBOARD_RIGHT || myKey == MLV_KEYBOARD_d){
    return 3;
  }
  if(myKey == MLV_KEYBOARD_DOWN || myKey == MLV_KEYBOARD_s){
    return 2;
  }
  return 0;
}

int main(){
  int i,j=0, t=0;
  int myShape[8];
  game * myGame;
  MLV_Keyboard_button myKey;
  block * myBlock, * myNextBlock;
  MLV_Music* music;
  MLV_Sound* oof;
  MLV_Button_state myState;

  MLV_init_audio();
  music = MLV_load_music( "Music/tetris.mp3" );
  oof = MLV_load_sound( "Music/oof.wav" );
  for(i=0;i<8;i++){
    myShape[i]=0;
  }
  srand(time(NULL));
  start_display();
  while(i!=-10){
    i = menu();
    switch(i){
      case 1:
        myGame = create_new_game();
        MLV_play_music( music, 0.7, -1 );
        while(!check_if_full(myGame)){
            display_game(myGame);
            if(!j){
              myBlock = create_new_block();
            }
            else{
              myBlock->blockShape = myNextBlock->blockShape;
              myNextBlock = NULL;
            }
            myNextBlock = create_new_block();
            display_next_block(myNextBlock);
            while(!myBlock->blocked){
              get_all_block_parts(myBlock, myShape);
              MLV_get_event( &myKey, NULL, NULL, NULL, NULL, NULL, NULL, NULL , &myState );
              if( myState ==  MLV_RELEASED){
                move_block(myGame, myBlock, myShape, convert_move(myKey), oof);
                display_next_block(myNextBlock);
                MLV_flush_event_queue();
                myKey = MLV_KEYBOARD_NONE;
              }
              delete_lines(myGame);
              MLV_actualise_window();
              display_next_block(myNextBlock);
              MLV_wait_milliseconds(50);
              t+=50;
              if(t==500){
                move_block(myGame, myBlock, myShape, 4, oof);
                display_next_block(myNextBlock);
                t=0;
              }
              display_game(myGame);
              display_next_block(myNextBlock);
            }
        }
        MLV_stop_all_sounds();
        MLV_free_sound(oof);
        MLV_stop_music();
        MLV_free_music(music);
        MLV_free_audio();
        break;
      case 2:
        break;
      case 3:
        i = menu_saves(myGame);
        break;
      case 4:
        break;
      default:
        i = 10;
        break;
    }
  }
  exit(EXIT_SUCCESS);
}

#endif
