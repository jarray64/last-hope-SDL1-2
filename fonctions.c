/**  
* @file fonctions.c  
*/  

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "enigme.h"

/**  
* @file fonctions.c  
* @brief fonction file to call fonction  
* @author intule Team  
* @version 00.41 
* @date Apr 25, 2022  
*  
* main program  *  
*/


/**  
* @brief  initialiser animation time  
* @param load de type image  
* @return Nothing  
*/  

void init_animation_time(image load[])
{
char file[20];
int i;
for (i=1 ;i<=113; i++)
{

 sprintf(file,"clock/%d.png",i);
load[i].img = IMG_Load(file);
load[i].pos.x=0;
load[i].pos.y=-250;
	 			
}
}
/**  
* @brief init image victoire   
* @param load pointeur de type image 
* @return Nothing  
*/  

void init_image_victoire(image *load)
{
load->img = IMG_Load("background/win.png");
load->pos.x=0;
load->pos.y=0;
}
/**  
* @brief inisialisation background  
* @param load pointeur de type image 
* @return Nothing  
*/  

void init_back(image *load)
{
load->img = IMG_Load("background/back.png");
load->pos.x=0;
load->pos.y=30;
}
/**  
* @brief init image defeat  
* @param load pointeur de type image 
* @return Nothing  
*/  
void init_image_defeat(image *load)
{
load->img = IMG_Load("background/lose.png");
load->pos.x=0;
load->pos.y=0;
}

/**  
* @brief affichage image   
* @param p de type image 
*@param ecran SDL WINDOW
* @return Nothing  
*/  
void afficher_img(image p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.img, NULL, ecran,&p.pos);

}
/**  
* @brief affichage text   
* @param p de type text
*@param ecran SDL WINDOW
* @return Nothing  
*/  
void afficher(TEXT p,SDL_Surface *ecran)
{
SDL_BlitSurface(p.t, NULL, ecran,&p.pos);

}
/**  
* @brief initialisation des questions   
* @param txt de type text 
*@param ch chaine de caractere
* @return Nothing  
*/  
void init_question(TEXT *txt,char ch[])
{
	txt->pos.x=35;
	txt->pos.y=45;
	TTF_Init();
	
	
	SDL_Color couleur={255,255,255};
	 
	txt->p=TTF_OpenFont("text/game.ttf",30);
	
	txt->t=TTF_RenderText_Blended(txt->p,ch,couleur);
	
	 TTF_CloseFont (txt->p);
	 TTF_Quit();
}

/**  
* @brief initialisation des reponses
* @param txt pointeur de type text 
*@param ch chaine de caractere
*@param x entier 
*@param num_reponse entier 
* @return Nothing  
*/  
void init_reponse(TEXT *txt,char ch[],int x,int num_reponse)
{
       if(num_reponse==1)
        {
	txt->pos.x=35;
	txt->pos.y=200;
        }
       if(num_reponse==2)
        {
	txt->pos.x=35;
	txt->pos.y=300;
        }
       if(num_reponse==3)
        {
	txt->pos.x=35;
	txt->pos.y=400;
        }
	TTF_Init();
	
	
	SDL_Color couleur;
	if(x==1)
         {
        couleur.r=255 ;
        couleur.g=255 ;
        couleur.b=255;
          }
        else if(x==2)
          {
        couleur.r=255 ;
        couleur.g=255 ;
        couleur.b=100;
          }
	
	
	txt->p=TTF_OpenFont("text/game.ttf",30);
	
	txt->t=TTF_RenderText_Blended(txt->p,ch,couleur);
	 TTF_CloseFont (txt->p);
	 TTF_Quit();
}

/**  
* @brief initialisation  de enigme
* @return enigme  
*/  
enigme_txt init_enigme()
  { srand(time(NULL));
   int l=1+rand() %5 ;
   enigme_txt e;
    int i1=0;
    char ch1[30],c1,quest[50];
    sprintf(ch1,"question/%d/question.txt",l);
    FILE* question=fopen(ch1,"r+");
      while((c1=fgetc(question))!=EOF)
        {
         quest[i1]=c1 ;
          if(quest[i1]==':')
          {
             i1++;
             quest[i1]='\0';
          } 
             i1++;
        }
       init_question(&e.question,quest);
  
    int i2=0 ;
    char ch2[30],c2,rep1[10];
    sprintf(ch2,"question/%d/reponse1.txt",l);
    FILE* reponse1=fopen(ch2,"r+");
      while((c2=fgetc(reponse1))!=EOF)
        {
         rep1[i2]=c2 ;
          if(rep1[i2]==';')
             rep1[i2]='\0';
           i2++;
        }
       init_reponse(&e.reponse1,rep1,1,1);
       init_reponse(&e.reponse1o,rep1,2,1);
    //
    ////initialisation reponse 2
     int i3=0 ;
    char ch3[30],c3,rep2[10];
    sprintf(ch3,"question/%d/reponse2.txt",l);
    FILE* reponse2=fopen(ch3,"r+");
     while((c3=fgetc(reponse2))!=EOF)
        {
         rep2[i3]=c3 ;
         if(rep2[i3]==';')
             rep2[i3]='\0';
           i3++;
        }
  
     init_reponse(&e.reponse2,rep2,1,2);
       init_reponse(&e.reponse2o,rep2,2,2);

   int i4=0 ;
    char ch4[30],c4,rep3[10];
    sprintf(ch4,"question/%d/reponse3.txt",l);
    FILE* reponse3=fopen(ch4,"r+");
    while((c4=fgetc(reponse3))!=EOF)
        {
         rep3[i4]=c4 ;
        if(rep3[i4]==';')
             rep3[i4]='\0';

           i4++;
        }
      init_reponse(&e.reponse3,rep3,1,3);
       init_reponse(&e.reponse3o,rep3,2,3);

   int i5=0 ;
    char ch5[30],c5;
    sprintf(ch5,"question/%d/resultat.txt",l);
    FILE* result=fopen(ch5,"r+");
    while((c5=fgetc(result))!=EOF)
    {   if(i5==0){
         switch(c5)
       {
       case '1':
        e.resultat=1 ;
        break;
       case '2':
        e.resultat=2 ;
        break;
       case '3':
        e.resultat=3 ;
        break;
        }}
     i5++;
    }

    

  return e;
  }
/**  
* @brief afficher enigme
* @param e de type enigme texte
*@param ecran de type SDL WINDOW 
* @return Nothing  
*/  
void afficher_enigme(enigme_txt e,SDL_Surface *ecran)
{
afficher(e.question,ecran);
afficher(e.reponse1,ecran);
afficher(e.reponse2,ecran);
afficher(e.reponse3,ecran);
}


/**  
* @brief animation de temps
* @param clock de type image 
*@param i de type entier
*@param ecran de type SDL WINDOW 
* @return Nothing  
*/  
void animation_time(image clock[],int i,SDL_Surface *ecran)
{
 afficher_img(clock[i],ecran);
 

} 









