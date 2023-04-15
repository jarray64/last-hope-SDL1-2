
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "colli.h"
#include "player.h"
#include "game.h"
void afficher_background(SDL_Surface *screen, background *b)
{

   SDL_BlitSurface(b->mask, &b->camera, screen, NULL); 
   SDL_BlitSurface(b->background, &b->camera, screen, NULL);
   SDL_BlitSurface(b->map,NULL,screen,&b->xy); 
  SDL_BlitSurface(b->icon,NULL,screen,&b->posposbonhomme); 
}
SDL_Color GetPixel (SDL_Surface *pSurface , int x , int y)
{

SDL_Color color ;
Uint32 col=0;
char* pPosition = (char*) pSurface->pixels ;
pPosition += (pSurface->pitch * y);
pPosition += (pSurface->format->BytesPerPixel * x);

memcpy(&col , pPosition , pSurface->format->BytesPerPixel);
SDL_GetRGB(col ,pSurface->format , &color.r , &color.g ,&color.b );


return (color) ;
}

void update_points_de_collision(Perso* p)
{

  //points a droite de l'hero

	p->x1=p->PersoPos.x + p->rects[p->frame].w ;
	p->y1=p->PersoPos.y  ;

	p->x2=  p->PersoPos.x + p->rects[p->frame].w;
	p->y2= p->PersoPos.y + p->rects[p->frame].h/2 ;


	p->x3=p->PersoPos.x + p->rects[p->frame].w ;
	p->y3= p->PersoPos.y + p->rects[p->frame].h  ;

	//points a gauche de l'hero

	p->x6=  p->PersoPos.x ;
	p->y6=  p->PersoPos.y  ;

	p->x7=  p->rect_relative.x ;
	p->y7=  p->rect_relative.y + p->rects[p->frame].h/2   ;

	p->x8= p->rect_relative.x  ;
	p->y8=  p->rect_relative.y + p->rects[p->frame].h ;


	//points au milieu de l'hero
//up
	p->x11=  p->PersoPos.x+ p->rects[p->frame].w/2;
	p->y11=  p->PersoPos.y;
//down
	p->x12=  p->PersoPos.x+ p->rects[p->frame].w/2;
	p->y12=  p->PersoPos.y + p->rects[p->frame].h;



}

// retourne la couleur voir liste dans les variables globales

//pour le moment collision avec blanc

int collision_player_map_droite(background* acteurs , Perso* hero)
{

SDL_Color color1 , color2 , color3  ;

int coll =-1;
color1=GetPixel (acteurs->mask , hero->x1 , hero->y1) ;
color2=GetPixel (acteurs->mask , hero->x2 , hero->y2) ;
color3=GetPixel (acteurs->mask , hero->x3 , hero->y3) ;




if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255))
|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255)) )
{
	coll = 2;
}



return coll;
}

int collision_player_map_gauche(background* acteurs , Perso * hero)
{

SDL_Color color6 , color7 , color8  ;

int coll = -1;

color6=GetPixel (acteurs->mask , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->mask , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->mask , hero->x8 , hero->y8) ;



if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) )
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) )|| ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) ) )
{
	coll = 2;
}


return coll;
}

int collision_player_map_top(background* acteurs , Perso* hero)
{

SDL_Color  color11  ;

int coll = -1;

color11=GetPixel (acteurs->mask , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) )){
	coll = 2;
}


return coll;
}

int collision_player_map_bas(background* acteurs , Perso* hero)
{

SDL_Color  color12 ;

int coll = -1;


color12=GetPixel (acteurs->mask , hero->x12 , hero->y12) ;

if(((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
	coll = 2;
}



return coll;
}
void bg_int (background *b)
{
b->x_relative=0;
b->y_relative=0;
b->pos.x=0;
b->pos.y=0;
b->camera.x=0;
b->camera.y=0;
b->camera.w=1280;
b->camera.h=720;
b->posposbonhomme.x=0;
b->posposbonhomme.y=0;
b->icon=IMG_Load("icone.png");
b->background=IMG_Load("benali.png");
b->mask=IMG_Load("benali.png");
b->map=IMG_Load("MAP.png");
}
void scrolling_right(background *b, float velocity, SDL_Surface *screen, Input I)
{
	 if (I.right == 1 )
    {
        if (b->camera.x < 4873 - 1280)
        {
            b->camera.x += velocity;
        }
    }
}

void scrolling_left(background *b, float velocity, SDL_Surface *screen, Input I)
{
	 if (I.left == 1)
    {
        if (b->camera.x > 0)
        {
            b->camera.x -= velocity;
        }
    }
}
