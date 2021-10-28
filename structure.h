#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_
#define G_BOARD_WIDTH 9
#define G_BOARD_HEIGHT 30

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
  last
}shape;

typedef enum{
  zero,
  ninety,
  hundredEighty,
  twoHundredSeventy
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

void delete_block(block* myBLock, game* myGame);

#endif
