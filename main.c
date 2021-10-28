#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include <unistd.h>
#include <time.h>
#include "structure.h"

int main(){
  block testBlock;
  game testGame;
  srand(time(NULL));
  testBlock = create_new_block();
  testGame = create_new_game();
  exit(EXIT_SUCCESS);
}
