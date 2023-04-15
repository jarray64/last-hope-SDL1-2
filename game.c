
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define GRAVITY 10
#define SPEED 5
#define MAX_SPEED 10
#define MAX_JUMP_SPEED 25
void initialiser_input (Input *I)
{
I->left=0;
I->right=0;
I->down=0;
I->jump=0;
}
/*-------------------------------------------*/





void initialiser_stats (stat *s)
{
  s->bg=IMG_Load("graphic/stages/bbg1t.png");
SDL_Color color={255,255,255};
s->font_stage=TTF_OpenFont("fonts/font_stage.ttf",40);
TTF_SetFontStyle(s->font_stage,TTF_STYLE_BOLD);
s->stage=TTF_RenderText_Solid(s->font_stage,"TACHE 4 ",color);
s->font_score=TTF_OpenFont("fonts/font_score.ttf",40);
TTF_SetFontStyle(s->font_score,TTF_STYLE_NORMAL);


s->pos.x=0;
s->pos.y=0;

s->stage_pos.x=30;
s->stage_pos.y=20;
s->score_pos.x=720;
s->score_pos.y=23;
s->time_pos.x=350;
s->time_pos.y=23;

s->time=1000;
s->val_score=60;
}




void afficher_stats (stat *s,SDL_Surface *fenetre)
{
  SDL_BlitSurface(s->bg,NULL,fenetre,&s->pos);
SDL_BlitSurface(s->stage,NULL,fenetre,&s->stage_pos);


SDL_Color color={255,255,255};


char score[15];
sprintf(score,"time : %03d",s->val_score);
s->score=TTF_RenderText_Solid(s->font_score,score,color);
SDL_BlitSurface(s->score,NULL,fenetre,&s->score_pos);

char time[15];
sprintf(time,"score: %03d",s->time);
s->time1=TTF_RenderText_Solid(s->font_score,time,color);
SDL_BlitSurface(s->time1,NULL,fenetre,&s->time_pos);


}




/*------------------------------------------*/


/*--------------------------------------------------*/


int ground=480;



void stage_1(SDL_Surface *screen,bool *success,int *score )
{
TTF_Init();
	int redimensionnement=20;
perssonage p;
background b;
char *nom[10];
	bool running=true;
	SDL_Event event;
Input I;
	initialiser_backround (&b);
	initialiser_perssonage (&p);
        initialiser_input (&I);

int act=1;
stat st;
initialiser_stats (&st);

int next;
int nb=0;
int i=0;
SDL_EnableKeyRepeat(200,0);
while(running)
{
MAJMinimap(&p,&b,redimensionnement);
afficher_stats (&st,screen);

afficher_background (screen,&b);
afficher_perssonage (&p,screen);
SDL_Flip(screen);
SDL_Delay(16);
	next=-1;
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

			break;
			
			}
		break;
		}
	}



if (I.right==1  )
{

       p.xvelocity+=1;
	if (I.jump==0) mouvementright (&p);
	else if (I.jump==1) {jump (&p);}
}else if (I.left==1)
{
	p.xvelocity+=1;
	 
	if (I.jump==0) mouvementleft (&p);
	else if (I.jump==1) {jump (&p);}

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


nb++;
if (nb==22){
st.val_score=st.val_score-1;
nb=0;
}
i++;
if (i==10){
st.time --;
i=0;}
if (p.rect_relative.x>=1000) // end map = 3000
{
  (*success)=true;//win game
  running=0;
}



if (st.val_score <=0){
	
(*success)=false;//lose game
running=false;

}
if (next==0) running=0;
}
TTF_Quit();

*score= st.time;
}




void playername(SDL_Surface *screen , char chaine[50])
{
	TTF_Init();
SDL_Event event;
int i=0;
SDL_EnableKeyRepeat(200,0);
SDL_Rect pos;
SDL_Surface *texte;
SDL_Surface *c;
c=IMG_Load("graphic/stages/name.png");

TTF_Font *police;
SDL_Color color={255,255,255};
police=TTF_OpenFont("fonts/font_nom.ttf",40);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
pos.x=100;
pos.y=200;
while(i < 20) { 
 SDL_BlitSurface(c,NULL,screen,NULL);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
texte=TTF_RenderText_Solid(police,chaine,color);
SDL_BlitSurface(texte, NULL, screen, &pos);
SDL_Flip(screen);

  SDL_WaitEvent(&event);
  switch (event.type){
case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{  case SDLK_a:
                    strcat(chaine,"a");
                    break;
                    case SDLK_q:
                    strcat(chaine,"q");
                    break;
                    case SDLK_w:
                    strcat(chaine,"w");
                    break;
                    case SDLK_e:
                    strcat(chaine,"e");
                    break;
                    case SDLK_r:
                    strcat(chaine,"r");
                    break;
                    case SDLK_t:
                    strcat(chaine,"t");
                    break;
                    case SDLK_y:
                    strcat(chaine,"y");
                    break;
                    case SDLK_u:
                    strcat(chaine,"u");
                    break;
                    case SDLK_i:
                    strcat(chaine,"i");
                    break;
                    case SDLK_o:
                    strcat(chaine,"o");
                    break;
                    case SDLK_p:
                    strcat(chaine,"p");
                    break;
                    case SDLK_s:
                    strcat(chaine,"s");
                    break;
                    case SDLK_d:
                    strcat(chaine,"d");
                    break;
                    case SDLK_f:
                    strcat(chaine,"f");
                    break;
                    case SDLK_g:
                    strcat(chaine,"g");
                    break;
                    case SDLK_h:
                    strcat(chaine,"h");
                    break;
                    case SDLK_j:
                    strcat(chaine,"j");
                    break;
                    case SDLK_k:
                    strcat(chaine,"k");
                    break;
                    case SDLK_l:
                    strcat(chaine,"l");
                    break;
                    case SDLK_z:
                    strcat(chaine,"z");
                    break;
                    case SDLK_x:
                    strcat(chaine,"x");
                    break;
                    case SDLK_c:
                    strcat(chaine,"c");
                    break;
                    case SDLK_v:
                    strcat(chaine,"v");
                    break;
                    case SDLK_b:
                    strcat(chaine,"b");
                    break;
                    case SDLK_n:
                    strcat(chaine,"n");
                    break;
                    case SDLK_m:
                    strcat(chaine,"m");
                    break;
                    case SDLK_SPACE:
                    strcat(chaine," ");
                    break;
              case SDLK_RETURN:
                    i=22;
                    break;
                     case SDLK_ESCAPE:
                    SDL_Quit();
                    break;
                     
}


case SDL_KEYUP:
switch (event.key.keysym.sym)
			{  case SDLK_ESCAPE:
                    strcat(chaine,"\0");
                    break;
                 case SDLK_a:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_q:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_w:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_e:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_r:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_t:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_y:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_u:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_i:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_o:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_p:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_s:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_d:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_f:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_g:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_h:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_j:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_k:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_l:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_z:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_x:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_c:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_v:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_b:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_n:
                    strcat(chaine,"\0");
                    break;
                    case SDLK_m:
                    strcat(chaine,"\0");
                    break;
              }
  




}
}
}


void sauvgarder (int score,char nomjoueur[],char nomfichier[])
{
    FILE *fichier = NULL;
    
    fichier = fopen(nomfichier, "a+");
    fprintf(fichier, "%s %d\n", nomjoueur, score);
    fclose(fichier);
}

 high meilleur (char nomfichier[30],int score,char nomjoueur[30])
{ int i=0,j;
high h, t[30];
int max=i;
  FILE *fichier=NULL;
  fichier=fopen(nomfichier,"r");
  {
    if(fichier){
      while(fscanf(fichier,"%s %d\n",h.name,&h.score)!=EOF){
        strcpy(t[i].name,h.name);
        t[i].score=h.score;
        i++;
      }
      for(j=1;j<i;j++){
   if(t[j].score> t[max].score){
     max=j;
   }
    }
    return t[max];
 } 
 else {
   strcpy(h.name,nomjoueur);
   h.score=score;
 
 
 return h;
 }
 

  }fclose(fichier);
 
}

void affichehigh(SDL_Surface *screen,high h)
{TTF_Init();

  SDL_Surface *texte;
  SDL_Rect pos;
  TTF_Font *police;
SDL_Color color={255,0,0};
police=TTF_OpenFont("fonts/font_nom.ttf",40);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
pos.x=100;
pos.y=200;
char chaine[50]=" \0";
sprintf(chaine,"best score : %s    %d",h.name,h.score);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
texte=TTF_RenderText_Solid(police,chaine,color);
SDL_BlitSurface(texte, NULL,screen, &pos);
SDL_Flip(screen);
SDL_Delay(1000);

}