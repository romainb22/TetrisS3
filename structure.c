#ifndef _STRUCTURE_C_
#define _STRUCTURE_C_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "structure.h"

block * create_new_block(){
  block * myBlock;
  myBlock = (block *) malloc(sizeof(block));
  myBlock->blockShape = (shape)rand() % last; /* Affecting a random shape to the block, via the shape enum */
  myBlock->blockRotation = zero; /* Considering that zero is the default rotation */
  myBlock->posX = G_BOARD_WIDTH/2; /* block spawn vertically centered */
  myBlock->posY = 0; /* block spawns on top */
  myBlock->blocked = 0; /* a new block falls */
  return myBlock;
}

game * create_new_game(){
  game * myGame;
  int i, j;
  myGame = (game *) malloc(sizeof(game));
  for(j=0;j<G_BOARD_HEIGHT;j++){
    for(i=0;i<G_BOARD_WIDTH;i++){
        myGame->gameBoard[i][j] = 0; /* Setting all the gameBoard values to 0, simulating an empty gameBoard */
    }
  }
  myGame->score = 0; /* Setting the score to zero on startup */
  return myGame;
}

void delete_block(block* myBLock, game* myGame){
  /*
  Update Gboard with 1 where the block stands
  */
  free(myBlock);
  return;
}

#endif
