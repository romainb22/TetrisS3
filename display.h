#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "structure.h"

void start_display();

int menu();

void display_game(game * myGame);

void display_block(game * myGame, block * myBlock, int * myShape);

#endif
