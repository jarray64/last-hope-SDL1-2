
#include "background.h"



void initialiser_backround (background *b)
{
b->icon=NULL;
b->bg=NULL;
b->map=NULL;
b->pos.x=0;
b->pos.y=0;
b->xy.x=20;
b->xy.y=0;

b->posposbonhomme.x=0;
b->posposbonhomme.y=0;
b->icon=IMG_Load("icone.png");

b->bg=IMG_Load("graphic/stages/background.png");
b->map=IMG_Load("MAP.png");
}
void MAJMinimap(perssonage *p,background *b, int redimensionnement)
{b->posposbonhomme.x=p->rect.x*redimensionnement/50;
 b->posposbonhomme.y=p->rect.y*redimensionnement/100;
}
void afficher_background (SDL_Surface *screen,background *b)
{
  SDL_BlitSurface(b->bg,NULL,screen,&b->pos);
  SDL_BlitSurface(b->map,NULL,screen,&b->xy); 
  SDL_BlitSurface(b->icon,NULL,screen,&b->posposbonhomme); 
}

