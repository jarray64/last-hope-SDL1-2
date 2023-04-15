#ifndef background_H_INCLUDED
#define background_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "perso.h"

typedef struct  background
{
  SDL_Surface *bg;
	    SDL_Surface *icon;
      SDL_Surface *mask;
      SDL_Surface *map;
	    SDL_Rect camera;
	    int x_relative;
	    int y_relative;
      SDL_Rect pos,xy;
      SDL_Rect posposbonhomme;
}background;

void initialiser_backround (background *b);
void afficher_background (SDL_Surface *screen,background *b);
void MAJMinimap(perssonage *p,background *b, int redimensionnement);



  #endif // DS_H_INCLUDED
