#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_audio.h>
#include "option.h"
 struct Image{ 
 SDL_Rect pos1; 
 SDL_Rect pos2; 
 SDL_Surface *img; 
}; 
typedef struct Image Image;
typedef struct { 
SDL_Rect position; 
TTF_Font *font; 
SDL_Surface * surfaceTexte; 
SDL_Color textColor; 
char texte [20]; 
} Text;
void initBackground(SDL_Surface *Backg,char name[]);
void initBouttom(SDL_Surface *newgame[],SDL_Surface *loadgame[],SDL_Surface *option[],SDL_Surface *exit[]);
void affichage(SDL_Surface *img,SDL_Surface *screen,SDL_Rect background_pos);
void liberer(SDL_Surface *img);
void initText(Text *A); 
void freeText(Text A); 
void displayText(Text t,SDL_Surface *screen) ;
void menu (SDL_Surface *screen, int *continuer);
void initBackground(SDL_Surface *Backg,char name[]);

#endif // MENU_H_INCLUDED
