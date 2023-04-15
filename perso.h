
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




//int blanc=1,noir=0,rouge=2,vert=3,bleu=4;

typedef struct perssonage
{
SDL_Surface *personnage;
SDL_Rect rect,rect_relative;
float xvelocity,yvelocity;

}perssonage;


void initialiser_perssonage (perssonage *p);
void afficher_perssonage (perssonage *p,SDL_Surface *screen);
void afficher_attack (perssonage p,SDL_Surface *screen);

void mouvementright (perssonage *p);
void mouvementleft (perssonage *p);
void jump (perssonage *p);


  #endif // DS_H_INCLUDED
