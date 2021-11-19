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

  start = MLV_load_image("Sprites/start.png");
  load = MLV_load_image("Sprites/load.png");
  save = MLV_load_image("Sprites/Button.png");
  score = MLV_load_image("Sprites/Button.png");

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

void display_block(block * myBlock, int * myShape){
  int i,j,k/*,r,g,b,a=255*/;
  MLV_Color myColor=MLV_COLOR_BLACK;
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
  }/*
  r = rand()%256;
  g = rand()%256;
  b = rand()%256;
  myColor=MLV_rgba(r,g,b,a);*/
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

void display_next_block(block * myNextBlock){
  MLV_Image *MyShape;
  switch(myNextBlock->blockShape){
    case 0:
      MyShape = MLV_load_image("Sprites/Z1.png");
      break;
    case 1:
      MyShape = MLV_load_image("Sprites/S1.png");
      break;
    case 2:
      MyShape = MLV_load_image("Sprites/l1.png");
      break;
    case 3:
      MyShape = MLV_load_image("Sprites/T1.png");
      break;
    case 4:
      MyShape = MLV_load_image("Sprites/O.png");
      break;
    case 5:
      MyShape = MLV_load_image("Sprites/L1.png");
      break;
    case 6:
      MyShape = MLV_load_image("Sprites/J1.png");
      break;
    default:
      MyShape = NULL;
      break;
  }
  if(MyShape != NULL){
    MLV_resize_image_with_proportions(MyShape, 100, 100);
    MLV_draw_image(MyShape, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 60);
    MLV_actualise_window();
  }
  return;
}

int menu_saves(game * myGame){
  int i=0, x,y;
  MLV_Image *slot1, *slot2, *slot3, *goBack;
  FILE * myFile;
  MLV_clear_window(MLV_COLOR_BLACK);

  slot2 = MLV_load_image("Sprites/Button.png");
  slot1 = MLV_load_image("Sprites/Button.png");
  slot3 = MLV_load_image("Sprites/Button.png");
  goBack = MLV_load_image("Sprites/Leave.png");

  MLV_resize_image_with_proportions( slot1, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);
  MLV_resize_image_with_proportions( slot2, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);
  MLV_resize_image_with_proportions( slot3, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);
  MLV_resize_image_with_proportions( goBack, MENU_BUTTON_LENGHT, MENU_BUTTON_HEIGHT);

  MLV_draw_image(slot1, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 60);
  MLV_draw_image(slot2, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 190);
  MLV_draw_image(slot3, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 320);
  MLV_draw_image(goBack, WINDOW_LENGHT/2-MENU_BUTTON_LENGHT/2, 450);

  MLV_actualise_window();
  MLV_wait_mouse(&x,&y);
  if(y>60 && y<160){
    i = -1;
    myFile = fopen("Saves/Slot1.txt", "w");
  }
  else if(y>190 && y<290){
    i = -2;
    myFile = fopen("Saves/Slot2.txt", "w");
  }
  else if(y>320 && y<420){
    i = -3;
    myFile = fopen("Saves/Slot3.txt", "w");
  }
  else if(y>450 && y<550){
    i = 0;
  }
  if(myFile==NULL){
    return -50; /* err code */
  }
  fprintf(myFile, "%d\n", myGame->score);
  for(y=0;y<G_BOARD_HEIGHT;y++){
    for(x=0;x<G_BOARD_WIDTH;x++){
      fprintf(myFile, "%d ", myGame->gameBoard[x][y]);
    }
    fprintf(myFile, "\n");
  }
  fprintf(myFile, "\n");
  fclose(myFile);
  return i;
}

#endif
