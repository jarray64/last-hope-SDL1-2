
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "game.h"
#include "string.h"

int main()
{ 
  

SDL_Init(SDL_INIT_VIDEO);


SDL_Surface *screen;
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("MINIMAP",NULL);//titre de la fenetre
perssonage p;
background b;



stage_1(screen );


SDL_Quit();
return 0 ;
}
