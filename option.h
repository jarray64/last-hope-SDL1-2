#ifndef OPTION_H_INCLUDED
#define OPTION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>




void options(SDL_Surface *screen,int *action);
void play(SDL_Surface *screen,int *action);
int windo(SDL_Surface *ecran);
int fullscreen(SDL_Surface *ecran);
void libere(SDL_Surface *img);
#endif // OPTION_H_INCLUDED
