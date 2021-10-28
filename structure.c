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


void get_all_block_parts(block * myBlock, int * myShape){
  /*
  Get all block's part from myBlock->posX and myBlock->posY
  depending on the block shape, and with a zero rotation.
  */
  /* All tetris' blocks have 4 parts composing it */
  myShape[0] = myBlock->posX;
  myShape[1] = myBlock->posY;
  switch(myBlock->blockShape){
    case ZShape:
      switch(myBlock->blockRotation){
        case zero:
        case hundredEighty:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX+1;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX+2;
          myShape[7] = myBlock->posY+1;
          break;
        case ninety:
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY+2;
          break;
        default:
          break;
      }
      break;
    case SShape:
      switch(myBlock->blockRotation){
        case zero:
        case hundredEighty:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX+1;
          myShape[7] = myBlock->posY;
          break;
        case ninety:
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY-1;
          break;
        default:
          break;
      }
      break;
    case LineShape:
      switch (myBlock->blockRotation) {
        case zero:
        case hundredEighty:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX+2;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX+3;
          myShape[7] = myBlock->posY;
          break;
        case ninety:
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+2;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+3;
          break;
        default:
          break;
      }
      break;
    case TShape:
      switch(myBlock->blockRotation){
        case zero:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX+1;
          myShape[7] = myBlock->posY+1;
          break;
        case ninety:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+2;
          break;
        case hundredEighty:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX-2;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY-1;
          break;
        case twoHundredSeventy:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY-1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY-2;
          break;
        default:
        break;
      }
      break;
    case SquareShape:
      myShape[2] = myBlock->posX+1;
      myShape[3] = myBlock->posY;
      myShape[4] = myBlock->posX;
      myShape[5] = myBlock->posY+1;
      myShape[6] = myBlock->posX+1;
      myShape[7] = myBlock->posY+1;
      break;
    case LShape:
      switch(myBlock->blockRotation){
        case zero:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+2;
          break;
        case ninety:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX-2;
          myShape[7] = myBlock->posY+1;
          break;
        case hundredEighty:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY-2;
          break;
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY-1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX+2;
          myShape[7] = myBlock->posY-1;
          break;
        default:
        break;
      }
      break;
    case MirroredLShape:
      switch(myBlock->blockRotation){
        case zero:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+2;
          break;
        case ninety:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-2;
          myShape[7] = myBlock->posY;
          break;
        case hundredEighty:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY-2;
          break;
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY-1;
          myShape[4] = myBlock->posX+1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX+2;
          myShape[7] = myBlock->posY;
          break;
      }
      break;
    default:
      break;
  }
  return;
}


void delete_block(block* myBlock, game* myGame){
  /*
  Update Gboard with 1 where the block stands
  */
  free(myBlock);
  return;
}

#endif
