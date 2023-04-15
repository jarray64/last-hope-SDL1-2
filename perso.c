
#include "perso.h"


#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 25

void initialiser_perssonage (perssonage *p)
{
p->personnage=IMG_Load("graphic/hero/perso.png");
p->rect.x=0;
p->rect.y=0;
p->rect_relative.x=0;
p->rect_relative.y=0;
p->rect.w=100;
p->rect.h=100;
p->xvelocity=0;
p->yvelocity=0;


}

void afficher_perssonage (perssonage *p,SDL_Surface *screen)
{
	SDL_BlitSurface(p->personnage,NULL,screen,&p->rect);
}





void mouvementright (perssonage *p)
{
  //p->xvelocity+=0.005;
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=MAX_SPEED;
if (p->rect.x<1000 )
{

p->rect.x+=p->xvelocity;
p->rect_relative.x+=p->xvelocity;
}
}

void mouvementleft (perssonage *p)
{p->xvelocity=10;
if (p->xvelocity>=MAX_SPEED)
	p->xvelocity=10;
if (p->rect.x>150){
p->rect.x-=p->xvelocity;
p->rect_relative.x-=p->xvelocity;
}
}


void jump (perssonage *p)
{
if (p->xvelocity>=MAX_JUMP_SPEED)
	p->xvelocity=MAX_JUMP_SPEED;



}
