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
    int left, right, jump, attack, down,dashleft,dashright;

} Input;
typedef struct
{
    SDL_Surface *sprite,*hb[3];
    SDL_Surface *personnage_fall;
    SDL_Surface *personnage_attack_r;
    SDL_Rect PersoPos;
    SDL_Rect rect,rect_relative;
    SDL_Rect rects[100];
    SDL_Rect fall[15];
    SDL_Rect attack_r[15];

    int frame;
    float xvelocity,yvelocity;
    int direction,Ground;
    float x1 , x2 , x3 , x4 , x5 , x6 , x7 , x8 , x9 , x10 , x11 , x12 , x13 , x14 , x15 , x16 ;  //points de verification de collision parfaite
    float y1 , y2 , y3 , y4 , y5 , y6 , y7 , y8 , y9 , y10 , y11 , y12 , y13 , y14 , y15 , y16 ;  // points de verification de collision parfaite
    float xStep, yStep;

    float acceleration, vitesse;
    int currentMode;
    Input i;
 

} Perso;

void setrects(SDL_Rect *crop);
void setrects_attack_r(SDL_Rect* clip);
void init_Perso(Perso *p);
void init_Perso2(Perso *p);
void afficher_Perso(Perso *p, SDL_Surface *screen);
void leftAndRightPersoDash(Perso *p);
void idleAnimation(Perso *p);
void runAnimation(Perso *p);
void DashAnimation(Perso *p, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos);
void jumpAnimation(Perso *p, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, int run);
void attackAnimation(Perso *p, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos);
void leftAndRightHeroMvt(Perso *p);
void leftAndRightPersoMvtR(Perso *p, Uint32 dt);
void jumpPersoMvt(Perso *p, int *run);

#endif
