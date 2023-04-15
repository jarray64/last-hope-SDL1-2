#ifndef game_H_INCLUDED
#define game_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


typedef struct  stat
{
  SDL_Surface *bg;
  SDL_Rect pos;
SDL_Surface *stage;
TTF_Font *font_stage;
SDL_Rect stage_pos;
SDL_Surface *icon;
SDL_Rect icon_pos;
SDL_Surface *time1;
SDL_Surface *score;
TTF_Font *font_score;
SDL_Rect score_pos;
SDL_Rect time_pos;
int val_score;
int time;

}stat;

typedef struct 
{
  char name[30];
  int score;
}high;

high meilleur (char nomfichier[30],int score,char nomjoueur[30]);
void affichehigh(SDL_Surface *screen,high h);
void initialiser_stats (stat *s);
void afficher_stats (stat *s,SDL_Surface *fenetre);
void sauvgarder (int score,char nomjoueur[],char nomfichier[]);
void playername(SDL_Surface *screen , char chaine[50]);
void MAJMinimap(Perso *p,background *b, int redimensionnement);
void savegame(int  complited,char nom_fich[]);
int chargement(char nom_fich[]);
#endif