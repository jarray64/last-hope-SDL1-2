
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
{ high highsc;
  bool success1=false;

SDL_Init(SDL_INIT_VIDEO);


SDL_Surface *screen;
screen=SDL_SetVideoMode (1000,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("last hope",NULL);//titre de la fenetre
perssonage p;
background b;
char chaine[50]="\0";
playername(screen ,chaine);
printf("%s\n",chaine);
int score;
char file[15]="score.txt";
stage_1(screen,&success1,&score );
sauvgarder (score,chaine,file);
highsc=meilleur (file,score,chaine);
printf("%s",highsc.name);
printf("%d",highsc.score);
affichehigh(screen,highsc);
/*=======================================*
SDL_Surface *texte;
  SDL_Rect pos;
  TTF_Font *police;
SDL_Color color={255,255,255};
police=TTF_OpenFont("fonts/font_nom.ttf",40);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
pos.x=100;
pos.y=200;
char cc[30]="\0";
sprintf(cc,"high score : %s %03d",highsc.name,highsc.score);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
texte=TTF_RenderText_Solid(police,cc,color);
SDL_BlitSurface(texte, NULL,screen, &pos);
SDL_Flip(screen);
SDL_Delay(500);


/*===================================================*/
if (success1==true) printf("success\n");
else printf("fail\n");
SDL_Quit();
return 0 ;
}
