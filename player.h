#ifndef player_H_INCLUDED
#define player_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
typedef struct
{
    int left, right,up,down;

} Input;
typedef struct
{
    SDL_Surface *sprite;
    SDL_Rect PersoPos;
    SDL_Rect rects[100];

    int frame;
    float xStep, yStep;

    int currentMode;
    Input i;
    

} Perso;

void setrectsmap(SDL_Rect *crop);
void init_Persomap(Perso *p);
void afficher_Persomap(Perso *p, SDL_Surface *screen);

void idleAnimationmap(Perso *p);
void runAnimationmap(Perso *p);
void leftAndRightPersoMvtmap(Perso *p);


#endif
