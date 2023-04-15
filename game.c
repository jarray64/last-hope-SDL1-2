
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include"pingpong.h"

#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 25
void initialiser_input (Input *I)
{
I->left=0;
I->right=0;

I->jump=0;
}
/*-------------------------------------------*/





void initialiser_time (stat *s)
{
  s->bg=IMG_Load("graphic/stages/bbg1t.png");
SDL_Color color={255,255,255};
s->font_stage=TTF_OpenFont("fonts/font_nom.ttf",40);
TTF_SetFontStyle(s->font_stage,TTF_STYLE_BOLD);
s->stage=TTF_RenderText_Solid(s->font_stage,"MINIMAP ",color);
s->font_time=TTF_OpenFont("fonts/font_score.ttf",40);
TTF_SetFontStyle(s->font_time,TTF_STYLE_NORMAL);


s->pos.x=0;
s->pos.y=0;

s->stage_pos.x=30;
s->stage_pos.y=20;
s->timegame_pos.x=720;
s->timegame_pos.y=23;
s->time_pos.x=350;
s->time_pos.y=23;

s->time_enigme=3000;
s->time_game=0;
 

}




void afficher_time (stat *s,SDL_Surface *fenetre)
{
  SDL_BlitSurface(s->bg,NULL,fenetre,&s->pos);
SDL_BlitSurface(s->stage,NULL,fenetre,&s->stage_pos);


SDL_Color color={255,255,255};


char time[15];
sprintf(time,"time : %03d",s->time_game);
s->timesrf=TTF_RenderText_Solid(s->font_time,time,color);
SDL_BlitSurface(s->timesrf,NULL,fenetre,&s->timegame_pos);




}

void afficher_timeenigme (stat *s,SDL_Surface *fenetre)
{
	SDL_Color color={255,255,255};

 char time[25];
sprintf(time,"time remaining: %03d",s->time_enigme);
s->time1=TTF_RenderText_Solid(s->font_time,time,color);
SDL_BlitSurface(s->time1,NULL,fenetre,&s->time_pos);}


void caclultimegame(int *time)
{
	*time=SDL_GetTicks()/1000  ;
}

void caclultimeenigme(int *time)
{
	 int elapsed_time = SDL_GetTicks() / 1000;
    int time_remaining = *time - elapsed_time;

	*time=time_remaining;
     
	
	}


/*------------------------------------------*/


/*--------------------------------------------------*/


int ground=450;



void stage_1(SDL_Surface *screen)
{
TTF_Init();
	int redimensionnement=20;
perssonage p;
background b;
image enigme[35],img;
	bool running=true;
	SDL_Event event,event1;
Input I;
img.img=IMG_Load("graphic/stages/enigme.png");
img.pos.x=0;
img.pos.y=0;
	initialiser_minimap (&b,&p);
        initialiser_input (&I);
		init_animation(enigme);
int done=0;
int act=1;
stat st;
initialiser_time (&st);
int e=0;
int i=0;
int j=0;
SDL_EnableKeyRepeat(200,0);
while(running)
{
Minimap(&p,&b,redimensionnement);
afficher_time (&st,screen);

afficher_minimap (screen,&b,&p);

animation(enigme,j,screen);
j++;
SDL_Flip(screen);
SDL_Delay(16);
	
while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
		
			running=false;
		break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				case SDLK_ESCAPE:

			
			running=false;
				break;
        
			case SDLK_RIGHT:
				I.right=1;


			break;
			case SDLK_LEFT :
				I.left=1;

      		break;
			case SDLK_UP :
				if (act==1)
				{
				I.jump=1;
			
                act=0;
				
			p.yvelocity = -55;
				p.xvelocity=MAX_JUMP_SPEED;
				}
			break;
			case SDLK_e:
				e=1;
				done=1;

						break;

			
			}
		break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_RIGHT:
				I.right=0;
			break;
			case SDLK_LEFT :
				I.left=0;
      		break;
			case SDLK_UP :
				I.jump=0;
act=1;
p.yvelocity = -55;
				p.xvelocity=MAX_JUMP_SPEED;

			break;
			
				
			
			
			}
		break;
		}
	}



 if (I.right==1 && (collision_player_map_droite(&b , &p)!=2 ))
{

       p.xvelocity+=1;
	if (I.jump==0) mouvementright (&p);
	
}else if (I.left==1 && (collision_player_map_gauche(&b , &p)!=2 ) )
{
	p.xvelocity+=1;
	 
	if (I.jump==0) mouvementleft (&p);
	

}


 

	 if (collision_player_map_bas(&b , &p)==2 && act==1 )
	{
	
	p.yvelocity=0;
	p.rect.y += p.yvelocity;
	p.rect_relative.y += p.yvelocity;
 }
 else
 {
  p.yvelocity+=GRAVITY;
  p.rect.y += p.yvelocity;
  p.rect_relative.y += p.yvelocity;
}



 if(p.rect.y >= ground)
 	 {
 		 p.rect.y= ground;
		 p.rect_relative.y= ground;
 		 p.yvelocity = 0;
}
SDL_Rect relcoord_perssonage={p.rect.x+b.x_relative,p.rect.y,p.rect.w,p.rect.h};
update_points_de_collision(&p);



caclultimegame(&st.time_game );
 
   



if (p.rect_relative.x>=1000) // end map = 3000
{
	AI(); //tache blache jouer conter le pc
	
 
  running=false;
}

if((p.rect_relative.x>=850 &&p.rect_relative.x<=950) && e==1)
{
	
	
	
		
	while(done){
	while(SDL_PollEvent(&event1))
	{
		switch(event1.type)
		{
		case SDL_KEYDOWN:
		   case SDLK_ESCAPE:
		   done=0;
		break;
		break;}}

	 SDL_BlitSurface(img.img, NULL, screen,&img.pos);
	afficher_timeenigme (&st,screen);
	 SDL_Flip(screen);
	 SDL_Delay(80);
	 
	
	 		caclultimeenigme(&st.time_enigme);

	 if (st.time_enigme<=0 || done==0){
	 done=0;
	 e=0;
	 st.time_enigme=3000;
	 }
		
		
	 }}
	  
	
else
e=0;
done=0;


if (j==34) j=0;
}
TTF_Quit();


}




