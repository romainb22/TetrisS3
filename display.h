#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "structure.h"

void start_display();

int menu();

void display_game(game * myGame);

void display_block(block * myBlock, int * myShape);

void display_next_block(block * myNextBlock);

int menu_saves(game * myGame);

#endif
