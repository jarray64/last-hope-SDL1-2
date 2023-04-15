#ifndef colli_H_INCLUDED
#define colli_H_INCLUDED

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
  SDL_Surface *background;
  SDL_Surface *icon;
      SDL_Surface *mask;
      SDL_Surface *map;
	    SDL_Rect camera;
	    int x_relative;
	    int y_relative;
      SDL_Rect pos,xy;
      SDL_Rect posposbonhomme;
}background;

SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y);

void afficher_background(SDL_Surface *screen, background *b);
void update_points_de_collision(Perso* hero);
int collision_player_map_droite(background* acteurs , Perso* p);
int collision_player_map_gauche(background* acteurs , Perso* p);
int collision_player_map_top(background* acteurs , Perso* p);
int collision_player_map_bas(background* acteurs , Perso* p);
void scrolling_right (background *b,float volacity,SDL_Surface *screen,Input i);
void scrolling_left (background *b,float volacity,SDL_Surface *screen,Input i);
void bg_int (background *b);


  #endif // DS_H_INCLUDED
