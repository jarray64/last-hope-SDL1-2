/**  
* @file enigme.c  
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
* @file enigme.c  
* @brief enigme file  
* @author intule Team  
* @version 0.14 
* @date Apr 25, 2022  

*/

/**  
* @brief enigme fonction pricipale
*@param ecran de type SDL WINDOW 
* @return 1 ou 0
*/  
int enigmee(SDL_Surface *ecran)
{SDL_Event event ;
image winn,losee,back,clock[130];
enigme_txt e;
int done=1,curseur=0,cursor=0,win=0,lose=0,victory,defeat,i=1,nbr=1,j=1;
init_animation_time(clock);
 init_back(&back);
init_image_victoire(&winn);
init_image_defeat(&losee);
e=init_enigme();


while(done)
	{	          
                

              

                afficher_enigme(e,ecran);
                if(nbr!=3)
                 {
                 animation_time(clock,i,ecran);
                 i++;
                 SDL_Delay(100);
                 }

                afficher_enigme(e,ecran);

              if (win==1)
                {
                 afficher_img(winn,ecran);
                
                   switch(e.resultat)
            	{	
            		case 1:
            		afficher(e.reponse1o,ecran);
            		break;
            		case 2:
            		 afficher(e.reponse2o,ecran);
            		break;
            		case 3:
            		afficher(e.reponse3o,ecran);
            		break;
                }
                 
                     victory=1;
                }
   
              if(lose==1)
                {
                 afficher_img(losee,ecran);
                   switch(e.resultat)
            	{	
            		case 1:
            		afficher(e.reponse1o,ecran);
            		break;
            		case 2:
            		 afficher(e.reponse2o,ecran);
            		break;
            		case 3:
            		afficher(e.reponse3o,ecran);
            		break;
                   
            	}
                 
                   defeat=1;
                }    
                    switch(cursor)
            	{	
            		case 1:
            		afficher(e.reponse1o,ecran);
            		break;
            		case 2:
            		 afficher(e.reponse2o,ecran);
            		break;
            		case 3:
            		afficher(e.reponse3o,ecran);
            		break;
            	}
	
		while (SDL_PollEvent(&event)){
		switch(event.type)
		{
		case SDL_QUIT:
			done=0;
			break;

	  case SDL_KEYDOWN:
	      switch(event.key.keysym.sym)
			{ 
	         case SDLK_ESCAPE:
		done=0;
		break;
                       }
	case SDL_MOUSEMOTION :
	     if((event.motion.x>20 )&&(event.motion.x<180)&&(event.motion.y>200)&&(event.motion.y<264))
            	{
                       curseur=1;         
                       cursor=1;
                } 

              else if((event.motion.x>20 )&&(event.motion.x<180)&&(event.motion.y>300)&&(event.motion.y<364))
              {
            		curseur=2;         
                       cursor=2;
              }
              else if((event.motion.x>20 )&&(event.motion.x<180)&&(event.motion.y>400)&&(event.motion.y<464))
              {
                       curseur=3;         
                       cursor=3;
              }        
    
              else{       
                 cursor=0;
                 curseur=0;
                  }
        break;                       
                       
       case SDL_MOUSEBUTTONUP:
        
            if(event.button.button==SDL_BUTTON_LEFT)
            	      { 
            	
            	if(curseur==e.resultat)
                    {
	            win=1;
                    }   
                else if (curseur!=e.resultat)
                { 
                lose=1;
            	}
			
		  }
	         

                 
                }}
                if(i==130)
                  {
                   i=1;
                   nbr++;                 
                  }     
                  afficher_img(back,ecran);
                  
                 if(victory==1)
                 {
                    SDL_Delay(3000);
                     done=0;
                 }
                 if(defeat==1)
                 {
                    SDL_Delay(3000);
                     done=0;
                 }
                
		SDL_Flip(ecran);	
	}
	
if (victory==1)
return 1;
if (defeat==1)
return 0;





}

