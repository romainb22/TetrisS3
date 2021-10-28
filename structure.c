#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "structure.h"

block * create_new_block(){
  block * myBlock;
  myBlock = (block *) malloc(sizeof(block));
  myBlock->blockShape = (shape)rand() % last;
  myBlock->blockRotation = zero;
  myBlock->posX = G_BOARD_WIDTH/2;
  myBlock->posY = 0;
  myBlock->blocked = 0;
  return myBlock;
}

game * create_new_game(){
  game * myGame;
  int i, j;
  myGame = (game *) malloc(sizeof(game));
  for(j=0;j<G_BOARD_HEIGHT;j++){
    for(i=0;i<G_BOARD_WIDTH;i++){
        myGame->gameBoard[i][j] = 0;
    }
  }
  myGame->score = 0;
  return myGame;
}
