#include "colli.h"
#include "perso.h"
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

/*-------------------------------------------*/





void initialiser_stats (stat *s)
{
  s->bg=IMG_Load("graphic/stages/bbg1t.png");
SDL_Color color={255,255,255};
s->font_stage=TTF_OpenFont("fonts/font_stage.ttf",40);
TTF_SetFontStyle(s->font_stage,TTF_STYLE_BOLD);
s->stage=TTF_RenderText_Solid(s->font_stage,"level benali ",color);
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

s->time=10000;
s->val_score=700;
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


void MAJMinimap(Perso *p,background *b, int redimensionnement)
{b->posposbonhomme.x=p->PersoPos.x*redimensionnement/50;
 b->posposbonhomme.y=p->PersoPos.y*redimensionnement/100;
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
SDL_Color color={255,220,100};
police=TTF_OpenFont("fonts/font_nom.ttf",40);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
pos.x=100;
pos.y=200;
char chaine[50]=" \0";
sprintf(chaine,"best score : %s  %d",h.name,h.score);
TTF_SetFontStyle(police,TTF_STYLE_BOLD);
texte=TTF_RenderText_Solid(police,chaine,color);
SDL_BlitSurface(texte, NULL,screen, &pos);
SDL_Flip(screen);
SDL_Delay(3000);

}


