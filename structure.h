#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_
#define G_BOARD_WIDTH 9
#define G_BOARD_HEIGHT 20
#include <MLV/MLV_all.h>
#include <unistd.h>

typedef enum{
	left,
	bottom,
	right
}move;

typedef enum{
  ZShape,
   /*
          XX
           XX
  */
  SShape,
  /*
         XX
        XX
  */
  LineShape,
  /*
        XXXX
  */
  TShape,
  /*
        XXX
         X
  */
  SquareShape,
  /*
        XX
        XX
  */
  LShape,
  /*
      XX
       X
       X
  */
  MirroredLShape,
  /*
      XX
      X
      X
  */
  lastShape /* In order to make %lastShape in functions */
}shape;

typedef enum{
  zero,
  ninety,
  hundredEighty,
  twoHundredSeventy,
	lastRotation /* In order to make %lastRotation in functions */
}rotation;

typedef struct{
  shape blockShape;
  rotation blockRotation;
  int posX;
  int posY;
  int blocked;
}block;

typedef struct{
  int gameBoard[G_BOARD_WIDTH][G_BOARD_HEIGHT];
  int score;
}game;

block * create_new_block();

game * create_new_game();

void get_all_block_parts(block * myBlock, int * myShape);

void rotate_block(block * myBlock);

void move_block(game * myGame, block * myBlock, int * myShape, int movement, MLV_Sound * oof);

void delete_lines(game* myGame);

void delete_block(block* myBLock, game* myGame, int* myShape);

#endif
