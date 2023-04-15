
#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#include "minimap.h"



typedef struct perssonage
{
SDL_Surface *personnage;
SDL_Rect rect,rect_relative;
float xvelocity,yvelocity;
float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12 , x13 , x14 , x15 , x16 ;  //points de verification de collision parfaite
float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12 , y13 , y14 , y15 , y16 ;  // points de verification de collision parfaite

}perssonage;





void mouvementright (perssonage *p);
void mouvementleft (perssonage *p);


typedef struct  background
{
  SDL_Surface *bg;
	    SDL_Surface *icon;
      SDL_Surface *mask;
      SDL_Surface *map;
	  
	    int x_relative;
	    int y_relative;
      SDL_Rect pos,xy;
      SDL_Rect posposbonhomme;
}background;

struct image
{

SDL_Surface * img ; 
SDL_Rect pos; 
};

typedef struct image image ;


void initialiser_minimap (background *b, perssonage *p);
void afficher_minimap (SDL_Surface *screen,background *b,perssonage *p);
void Minimap(perssonage *p,background *b, int redimensionnement);
void init_animation (image load[]);
void afficher_img(image p,SDL_Surface *ecran);
void animation(image enigme[],int i,SDL_Surface *ecran);



SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y);
void update_points_de_collision(perssonage* hero);
int collision_player_map_droite(background* acteurs , perssonage* hero);
int collision_player_map_gauche(background* acteurs , perssonage* hero);
int collision_player_map_top(background* acteurs , perssonage* hero);
int collision_player_map_bas(background* acteurs , perssonage* hero);




  #endif // DS_H_INCLUDED
