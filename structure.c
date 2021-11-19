#ifndef _STRUCTURE_C_
#define _STRUCTURE_C_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structure.h"
#include "display.h"


block * create_new_block(){
  block * myBlock;
  myBlock = (block *) malloc(sizeof(block));
  myBlock->blockShape = (shape)rand() % lastShape; /* Affecting a random shape to the block, via the shape enum */
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


int get_all_block_parts(block * myBlock, int * myShape){
  /*
  Get all block's part from myBlock->posX and myBlock->posY
  depending on the block shape, and with a zero rotation.
  maybe return an int that states the lowest part of the block ?
  */
  /*
  All tetris' blocks have 4 parts composing it
  */
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
          return myBlock->posY+1;
        case ninety:
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY+2;
          return myBlock->posY+2;
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
          return myBlock->posY+1;
        case ninety:
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY-1;
          return myBlock->posY+1;
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
          return myBlock->posY;
        case ninety:
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+2;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+3;
          return myBlock->posY+3;
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
          return myBlock->posY+1;
        case ninety:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+2;
          return myBlock->posY+2;
        case hundredEighty:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX-2;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-1;
          myShape[7] = myBlock->posY-1;
          return myBlock->posY;
        case twoHundredSeventy:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY-1;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY-2;
          return myBlock->posY;
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
      return myBlock->posY+1;
    case LShape:
      switch(myBlock->blockRotation){
        case zero:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX+2;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+1;
          return myBlock->posY+1;
        case ninety:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY+1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY+2;
          return myBlock->posY+2;
        case hundredEighty:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY-1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-2;
          myShape[7] = myBlock->posY;
          return myBlock->posY;
        case twoHundredSeventy:
          myShape[2] = myBlock->posX+1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY-2;
          return myBlock->posY;
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
          return myBlock->posY+2;
        case ninety:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY+1;
          myShape[4] = myBlock->posX-1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX-2;
          myShape[7] = myBlock->posY;
          return myBlock->posY+1;
        case hundredEighty:
          myShape[2] = myBlock->posX-1;
          myShape[3] = myBlock->posY;
          myShape[4] = myBlock->posX;
          myShape[5] = myBlock->posY-1;
          myShape[6] = myBlock->posX;
          myShape[7] = myBlock->posY-2;
          return myBlock->posY;
        case twoHundredSeventy:
          myShape[2] = myBlock->posX;
          myShape[3] = myBlock->posY-1;
          myShape[4] = myBlock->posX+1;
          myShape[5] = myBlock->posY;
          myShape[6] = myBlock->posX+2;
          myShape[7] = myBlock->posY;
          return myBlock->posY;
        default:
        break;
      }
      break;
    default:
      break;
  }
  return 5; /*Error code*/
}

void rotate_block(block* myBlock){
  myBlock->blockRotation=(myBlock->blockRotation+1)%lastRotation;
  return;
}


void move_block(game * myGame, block * myBlock, int * myShape, int movement){
  /*
  movement = 1 -> left
  movement = 2 -> bottom
  movement = 3 -> right
  movement = 5 -> rotate
  */
  int moveable = 1 /* a block is not moveable at first */, i,j;
  if(!myBlock->blocked){
    switch(movement){
      case 1:
        for(i=0;i<8;i+=2){
          if(myShape[i] == 0){
            moveable = 0;
          }
        }
        if(moveable){
          myBlock->posX--;
          j = get_all_block_parts(myBlock, myShape);
        }
        break;
      case 2:
        /* Go to bottom */
        while(moveable){
            for(i=0;i<8;i+=2){
              if(myGame->gameBoard[myShape[i]][myShape[i+1]+1] || myShape[i+1]+1==G_BOARD_HEIGHT){ /* if the gameBoard is not empty below the blocks' part */
                moveable = 0;
                myBlock->blocked=1;
              }
            }
            if(moveable){
              myBlock->posY++;
              get_all_block_parts(myBlock, myShape);
            }
        }
        delete_block(myBlock, myGame, myShape);
        break;
      case 3:
        for(i=0;i<8;i+=2){
          if(myShape[i] == G_BOARD_WIDTH-1){
            moveable = 0;
          }
        }
        if(moveable){
          myBlock->posX++;
          get_all_block_parts(myBlock, myShape);
        }
        break;
        case 4:
        for(i=0;i<8;i+=2){
          if(myGame->gameBoard[myShape[i]][myShape[i+1]+1] || myShape[i+1]+1==G_BOARD_HEIGHT){ /* if the gameBoard is not empty below the blocks' part */
            moveable = 0;
            myBlock->blocked = 1;
            delete_block(myBlock, myGame, myShape);
          }
        }
        if(moveable){
          myBlock->posY++;
          get_all_block_parts(myBlock, myShape);
        }
        break;
        case 5:
        rotate_block(myBlock);
        break;
      default:
        break;
    }
  }
  else{
    ;
  }
  if(!myBlock->blocked){
    display_block(myGame,myBlock,myShape);
  }
  MLV_actualise_window();
  return;
}


void delete_block(block* myBlock, game* myGame, int* myShape ){
  /*
  Update Gboard with 1 where the block stands
  */
  int i;
  for(i=0;i<8;i+=2){
    myGame->gameBoard[myShape[i]][myShape[i+1]] = 1;
  }
  /*free(myBlock)*/;
  return;
}

#endif
