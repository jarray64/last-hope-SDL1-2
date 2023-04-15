
#include "minimap.h"

#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 10


void initialiser_minimap (background *b, perssonage *p)
{

b->icon=NULL;
b->bg=NULL;
b->map=NULL;
b->pos.x=0;
b->pos.y=0;
b->xy.x=50;
b->xy.y=0;

b->posposbonhomme.x=0;
b->posposbonhomme.y=0;
b->icon=IMG_Load("graphic/hero/icon.png");
b->mask=IMG_Load("graphic/stages/1as.png");
b->bg=IMG_Load("graphic/stages/background.png");
b->map=IMG_Load("graphic/stages/MAP.png");


p->personnage=IMG_Load("graphic/hero/perso.png");

p->rect.x=0;
p->rect.y=300;
p->rect_relative.x=0;
p->rect_relative.y=300;
p->rect.w=10;
p->rect.h=10;
p->xvelocity=0;
p->yvelocity=0;









}


void afficher_minimap (SDL_Surface *screen,background *b,perssonage *p)
{


SDL_BlitSurface(b->bg,NULL,screen,&b->pos);
  SDL_BlitSurface(b->map,NULL,screen,&b->xy); 
  SDL_BlitSurface(b->icon,NULL,screen,&b->posposbonhomme); 
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
if (p->rect.x>0){
p->rect.x-=p->xvelocity;
p->rect_relative.x-=p->xvelocity;
}
}


void Minimap(perssonage *p,background *b, int redimensionnement)
{b->posposbonhomme.x=p->rect.x*redimensionnement/100;
 b->posposbonhomme.y=p->rect.y*redimensionnement/100;
}



void init_animation (image load[])
{
char file[20];
int i;
for (i=0 ;i<=34; i++)
{

 sprintf(file,"animation/%d.resized.png",i);
load[i].img = IMG_Load(file);
load[i].pos.x=850;
load[i].pos.y=480;

	 			
}

}
void afficher_img(image p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);

}
void animation(image enigme[],int j,SDL_Surface *ecran)
{
 afficher_img(enigme[j],ecran);
 

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

void update_points_de_collision(perssonage* hero)
{

  //points a droite de l'hero

	hero->x1=hero->rect_relative.x + hero->rect.w-30 ;
	hero->y1=hero->rect_relative.y  ;

	hero->x2=  hero->rect_relative.x + hero->rect.w-30;
	hero->y2= hero->rect_relative.y + hero->rect.h/2 ;


	hero->x3=hero->rect_relative.x + hero->rect.w-30 ;
	hero->y3= hero->rect_relative.y + hero->rect.h  ;

	//points a gauche de l'hero

	hero->x6=  hero->rect_relative.x ;
	hero->y6=  hero->rect_relative.y  ;

	hero->x7=  hero->rect_relative.x ;
	hero->y7=  hero->rect_relative.y + hero->rect.h/2   ;

	hero->x8= hero->rect_relative.x  ;
	hero->y8=  hero->rect_relative.y + hero->rect.h ;


	//points au milieu de l'hero
//up
	hero->x11=  hero->rect_relative.x+ hero->rect.w/2;
	hero->y11=  hero->rect_relative.y;
//down
	hero->x12=  hero->rect_relative.x+ hero->rect.w/2;
	hero->y12=  hero->rect_relative.y + hero->rect.h;



}

// retourne la couleur voir liste dans les variables globales

//pour le moment collision avec blanc

int collision_player_map_droite(background* acteurs , perssonage* hero)
{

SDL_Color color1 , color2 , color3  ;

int coll =-1;
color1=GetPixel (acteurs->mask , hero->x1 , hero->y1) ;
color2=GetPixel (acteurs->mask , hero->x2 , hero->y2) ;
color3=GetPixel (acteurs->mask , hero->x3 , hero->y3) ;




if(((color1.r==255)  &&  (color1.g==255)  &&  (color1.b==255)) || ((color2.r==255)  &&  (color2.g==255)  &&  (color2.b==255))
|| ((color3.r==255)  &&  (color3.g==255)  &&  (color3.b==255)) )
{
	coll = 0;
}


else if(((color1.r==0)  &&  (color1.g==0)  &&  (color1.b==0)) || ((color2.r==0)  &&  (color2.g==0)  &&  (color2.b==0))
)
{
	coll = 1;
}
if(((color1.r<=255 && color1.r>=200)   &&   (color1.g<=50 && color1.g==0)  &&  (color1.b<=50 && color1.b>=0)) || ((color2.r<=255 && color2.r>=200)   &&   (color2.g<=50 && color2.g==0)   &&  (color2.b<=50 && color2.b>=0)) )
{
	coll = 2;
}

return coll;
}

int collision_player_map_gauche(background* acteurs , perssonage* hero)
{

SDL_Color color6 , color7 , color8  ;

int coll = -1;

color6=GetPixel (acteurs->mask , hero->x6 , hero->y6) ;
color7=GetPixel (acteurs->mask , hero->x7 , hero->y7) ;
color8=GetPixel (acteurs->mask , hero->x8 , hero->y8) ;



if(((color6.r==255)  &&  (color6.g==255)  &&  (color6.b==255) )
	|| ((color7.r==255)  &&  (color7.g==255)  &&  (color7.b==255) )|| ((color8.r==255)  &&  (color8.g==255)  &&  (color8.b==255) ) )
{
	coll = 0;
}

else if(((color6.r==0)  &&  (color6.g==0)  &&  (color6.b==0) )
	|| ((color7.r==0)  &&  (color7.g==0)  &&  (color7.b==0) ))
{
	coll = 1;
}
if(((color6.r<=255 && color6.r>=200)   &&   (color6.g<=50 && color6.g==0)  &&  (color6.b<=50 && color6.b>=0)) || ((color7.r<=255 && color7.r>=200)   &&   (color7.g<=50 && color7.g==0)   &&  (color7.b<=50 && color7.b>=0)) )
{
	coll = 2;
}
return coll;
}

int collision_player_map_top(background* acteurs , perssonage* hero)
{

SDL_Color  color11  ;

int coll = -1;

color11=GetPixel (acteurs->mask , hero->x11 , hero->y11) ;

if(((color11.r==255)  &&  (color11.g==255)  &&  (color11.b==255) ))
{
	coll = 0;
}

else if(((color11.r==0)  &&  (color11.g==0)  &&  (color11.b==0) ))
{
	coll = 1;
}

return coll;
}

int collision_player_map_bas(background* acteurs , perssonage* hero)
{

SDL_Color  color12 ;

int coll = -1;


color12=GetPixel (acteurs->mask , hero->x12 , hero->y12) ;

if(((color12.r==255)  &&  (color12.g==255)  &&  (color12.b==255)))
{
	coll = 0;
}

if(((color12.r==0)  &&  (color12.g==0)  &&  (color12.b==0)))
{
	coll = 1;
}

if(((color12.r<=255 && color12.r>=200)  &&  (color12.g<=50 && color12.g==0)  &&  (color12.b<=50 && color12.b>=0)))
{
	coll = 2;
}

return coll;
}
