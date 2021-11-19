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
    printf("left\n");
    return 1;
  }
  if(myKey == MLV_KEYBOARD_UP || myKey == MLV_KEYBOARD_z){
    printf("rotate\n");
    return 5;
  }
  if(myKey == MLV_KEYBOARD_RIGHT || myKey == MLV_KEYBOARD_d){
    printf("right\n");
    return 3;
  }
  if(myKey == MLV_KEYBOARD_DOWN || myKey == MLV_KEYBOARD_s){
    printf("down\n");
    return 2;
  }
  return 0;
}

int main(){
  int i,j=0, t=0, blockBottom;
  int myShape[8];
  game * myGame;
  MLV_Keyboard_button myKey;
  block * myBlock, * myNextBlock;
  MLV_Music* music;

  MLV_init_audio();
  music = MLV_load_music( "Music/tetris.mp3" );
  for(i=0;i<8;i++){
    myShape[i]=0;
  }
  srand(time(NULL));
  start_display();
  i = menu();
  myGame = create_new_game();
  switch(i){
    case 1:
      MLV_play_music( music, 1.0, -1 );
      while(!check_if_full(myGame)){
          display_game(myGame);
          if(!j){
            myBlock = create_new_block();
          }
          else{
            myBlock = myNextBlock;
            myNextBlock = NULL;
          }
          myNextBlock = create_new_block();
          while(!myBlock->blocked){
            blockBottom = get_all_block_parts(myBlock, myShape);
            MLV_get_event( &myKey, NULL, NULL, NULL, NULL, NULL, NULL, NULL , NULL );
            move_block(myGame, myBlock, myShape, convert_move(myKey));
            myKey = MLV_KEYBOARD_NONE;
            printf("%d\n", myBlock->blockRotation);
            MLV_wait_milliseconds(50);
            t+=50;
            if(t==500){
              move_block(myGame, myBlock, myShape, 4);
              printf("%d\n", myBlock->blockRotation);
              t=0;
            }
            display_game(myGame);
          }

      }
      MLV_stop_music();
      MLV_free_music(music);
      MLV_free_audio();
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      break;
  }
  exit(EXIT_SUCCESS);
}

#endif
