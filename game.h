#ifndef stage1_H_INCLUDED
#define stage1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "minimap.h"



/*-----------------------------------*/
typedef struct  stat
{
  SDL_Surface *bg;
  SDL_Rect pos;
SDL_Surface *stage;
TTF_Font *font_stage;
SDL_Rect stage_pos;

SDL_Surface *timesrf;
SDL_Surface *time1;
TTF_Font *font_time;
SDL_Rect timegame_pos;
SDL_Rect time_pos;
int time_game;
int time_enigme;

}stat;




void initialiser_time (stat *s);
void afficher_time (stat *s,SDL_Surface *fenetre);
void stage_1(SDL_Surface *screen );
void afficher_timeenigme (stat *s,SDL_Surface *fenetre);
void caclultimegame(int *time);
/*---------------------------*/
typedef struct Input
{
 int left,right,jump;

} Input;

void initialiser_input (Input *I);
/*---------------------------*/



  #endif // DS_H_INCLUDED
