#ifndef _DISPLAY_C_
#define _DISPLAY_C_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "structure.h"
#include "display.h"
#define WINDOW_LENGHT 1280
#define WINDOW_HEIGHT 720
#define MENU_BUTTON_LENGHT 400
#define MENU_BUTTON_HEIGHT 100


void start_display(){
  MLV_create_window("Tetris","Tetris Game", WINDOW_LENGHT, WINDOW_HEIGHT);
  return;
}

int menu(){
  int i=0, x,y;
  MLV_Image *start, *load, *save, *score;
  MLV_clear_window(MLV_COLOR_BLACK);

  printf("Yo\n");
  start = MLV_load_image("Sprites/button.png");
  printf("Yo\n");
  load = MLV_load_image("Sprites/button.png");
  printf("Yo\n");
  save = MLV_load_image("Sprites/button.png");
  printf("Yo\n");
  score = MLV_load_image("Sprites/button.png");

  MLV_resize_image_with_proportions( start, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);
  MLV_resize_image_with_proportions( load, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);
  MLV_resize_image_with_proportions( save, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);
  MLV_resize_image_with_proportions( score, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);

  MLV_draw_image(start, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 60);
  MLV_draw_image(load, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 190);
  MLV_draw_image(save, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 320);
  MLV_draw_image(score, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 450);

  MLV_actualise_window();
  MLV_wait_mouse(&x,&y);
  if(y>60 && y<160){
    i = 1;
  }
  else if(y>190 && y<290){
    i = 2;
  }
  else if(y>320 && y<420){
    i = 3;
  }
  else if(y>450 && y<550){
    i =4;
  }
  else{
    i=0;
  }
  return i;
}

void display_game(game* myGame){
  int i,j;
  int * myShape;
  MLV_clear_window(MLV_COLOR_BLACK);
  /*MLV_draw_filled_rectangle((100+((WINDOW_LENGHT-200)/config->t->n)*i),
    (100+((WINDOW_HEIGHT-200)/config->t->m)*j),
    (WINDOW_LENGHT-200)/config->t->n,
    ((WINDOW_HEIGHT-200)/config->t->m),maCouleur);*/ /* ici, on calcule la taille d'un carré en fonction
    de la taille de la fenêtre et du nombre de carrés choisi en appelant le programme */
  for(i=0;i<G_BOARD_WIDTH;i++){
    for(j=0;j<G_BOARD_HEIGHT;j++){
      if(myGame->gameBoard[i][j]){
        MLV_draw_filled_rectangle(20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*i,
          20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*j,
          (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,
          (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,MLV_COLOR_DARK_SLATE_GRAY);
      }
      MLV_draw_rectangle(20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*i,
        20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*j,
        (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,
        (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,MLV_COLOR_MIDNIGHTBLUE );
    }
  }
  MLV_draw_rectangle(20, 20, G_BOARD_WIDTH*((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT),WINDOW_HEIGHT-40,MLV_COLOR_MIDNIGHTBLUE );

  MLV_actualise_window();
  return;
}

void display_block(game * myGame, block * myBlock, int * myShape){
  int i,j,k;
  MLV_Color myColor;
  switch(myBlock->blockShape){
    case ZShape:
      myColor = MLV_COLOR_ORANGE;
      break;
    case SShape:
      myColor = MLV_COLOR_PALE_TURQUOISE;
      break;
    case LineShape:
      myColor = MLV_COLOR_RED;
      break;
    case TShape:
      myColor = MLV_COLOR_GREEN;
      break;
    case SquareShape:
      myColor = MLV_COLOR_BLUE;
      break;
    case LShape:
      myColor = MLV_COLOR_PURPLE;
      break;
    case MirroredLShape:
      myColor = MLV_COLOR_YELLOW;
      break;
    default:
      break;
  }
  for(k=0;k<8;k+=2){
    for(i=0;i<G_BOARD_WIDTH;i++){
      for(j=0;j<G_BOARD_HEIGHT;j++){
        if(i==myShape[k] && j==myShape[k+1]){
          MLV_draw_filled_rectangle(20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*i,
            20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*j,
            (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,
            (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,myColor);
          MLV_draw_rectangle(20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*i,
            20+((WINDOW_HEIGHT-40)/G_BOARD_HEIGHT)*j,
            (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,
            (WINDOW_HEIGHT-40)/G_BOARD_HEIGHT,MLV_COLOR_MIDNIGHTBLUE );
        }
      }
    }
  }
  return;
}

#endif
