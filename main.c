#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "menu.h"
#include "option.h"
#include "map.h"

int main()
{
 Text t;
int continuer=-1,a=-1;
SDL_Surface *screen=NULL;
int vm=100, vsfx=100;
SDL_Surface *background=NULL;
SDL_Rect background_pos,position;
background_pos.x=0;
background_pos.y=0;
int c=-1;
Mix_Music *music;
Mix_Chunk *sound;
SDL_Surface *newgame[3],*loadgame[3],*option[3],*exit[3];
SDL_Rect pos;
pos.x=0;
pos.y=0;
SDL_Event event;
int ng=0,op=0,ex=0,lg=0,save;
int done=1;
int i=1;
char filename[64];
//init
 TTF_Init(); 
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode (1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Last Hope\t!",NULL); 
initBackground(background,"graphic/menu/ezgif-frame-002.png");
initText(&t);
initBouttom(newgame,loadgame,option,exit);
//introduction musique
//********frequence**format*************echantillon de morceau,
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);//initialiser le song
//declaration+changement de la musique
music= Mix_LoadMUS("graphic/menu/Elevator Music - Gaming Background Music (HD).mp3");
Mix_VolumeMusic(vm);
Mix_PlayMusic(music,-1);
sound= Mix_LoadWAV("graphic/option/gh.wav");
if (sound==NULL)
{ 
  printf("xxxxxx:%s",Mix_GetError());
}
Mix_VolumeChunk(sound,vsfx);//  fix volume********morceau+volume**********
while(continuer!=0){

    while (done)
    {
    if (i != 0)
        //SDL_FreeSurface(background);
        sprintf(filename,"animation/%d.png",i);
        SDL_BlitSurface(background,NULL,screen,&pos); 
        background = IMG_Load(filename);
   // affichage(background,screen,background_pos);
    affichage(loadgame[lg],screen,pos);
    affichage(option[op],screen,pos);
    affichage(newgame[ng],screen,pos);
    affichage(exit[ex],screen,pos);
    displayText(t, screen);
    //background =IMG_Load("graphic/menu/ezgif-frame-002.png");
    i++;
        if (i > 178)
        {
            i = 0;
        }
       
    SDL_Flip(screen);
    if(ng==2){
        			SDL_Delay (500);
    (continuer)=1;
                             c=0;
                             ng=0;
                             }
                             if(lg==2){
                                 			SDL_Delay (500);
    (continuer)=3;
                             c=0;
                             lg=0;}
                             if(ex==2){
                                 			SDL_Delay (500);
    (continuer)=0;
                             c=0;
                             ex=0;}
                              if(op==2){
                                  			SDL_Delay (500);
    (continuer)=2;
                             c=0;
                             op=0;}
                         
    

 
    	if (SDL_PollEvent(&event)){
    	switch(event.type)
{
case SDL_QUIT :
(continuer)=0;// bckg --->vers backg
c=0;//tkharajna me loop
break;

    		//avec clavier
    		case SDL_KEYDOWN://click clavier
    			switch(event.key.keysym.sym){

    				case SDLK_UP:// flesh fou9ani
    				if (ng==0 && op==0 && ex==0 && lg==0)
    				{lg=1;
					Mix_PlayChannel(1,sound,0);//sound
				 
					}
    					if (ng==1 ){
    						ex=1;
    						ng=0;
    						op=0;
                        Mix_PlayChannel(1,sound,0);
    					}
    					else if(op==1 ){
    						if (lg==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;
                                ex=0;
                                Mix_PlayChannel(1,sound,0);
                            }
                            else{
                                ng=1;
                                op=0; Mix_PlayChannel(1,sound,0);
                                ex=0;
                            }
    					}
    					else if (ex==1 ){
    						op=1;
    						ex=0;Mix_PlayChannel(1,sound,0);
    						ng=0;
    						
    					}
                        else if (lg==1 )
                        {
                            ng=1;
                            lg=0;
                            op=0; Mix_PlayChannel(1,sound,0);
                            ex=0;
                        }
    				break;

    				case SDLK_DOWN:
    				if (ng==0 && op==0 && ex==0 && lg==0)
    				{ex=1;
    				Mix_PlayChannel(1,sound,0);//sound
					
					}
    					if (ng==1){
    						if (lg==0)
                            {
                                ng=0;
                                lg=1;
                                op=0;Mix_PlayChannel(1,sound,0);
                                ex=0;
                            }
                            else{
                                ng=0;
                                op=1;
                                ex=0;Mix_PlayChannel(1,sound,0);
                            }
    					}
    					else if(op==1 ){
    						ng=0;
    						op=0;Mix_PlayChannel(1,sound,0);
    						ex=1;
    					}
    					else if (ex==1 ){
    						op=0;
    						ex=0;
    						ng=1;Mix_PlayChannel(1,sound,0);
    					}
                        else if (lg==1 )
                        {
                            ng=0;
                            lg=0;
                            op=1; Mix_PlayChannel(1,sound,0);
                            ex=0;
                        }
    				break;
    				case SDLK_p:(continuer)=1;c=0;break;
    				case SDLK_q:(continuer)=0;c=0;break;
    				case SDLK_o:(continuer)=2;c=0;break;

    				case SDLK_RETURN:
    					if (ng==1)
    					{ng=2;
    			
    					}
    					else if (op==1)
    					{op=2;
	c=0;
    					}
							else if (ex==1)
	    				{
	    			ex=2;
						
							
	    				}
                        else if (lg==1)
                        { 
                          lg=2;
                      
                             }
    				break;
    			}
    		break;

//avec souris
    		case SDL_MOUSEMOTION:

    				ex=0;
    				ng=0;
    				op=0;
    				lg=0;
    			if (event.motion.x>104 && event.motion.y>252 && event.motion.x<367 && event.motion.y<301 )
    			{
    			    ng=1; Mix_PlayChannel(1,sound,0);

    			}

    			else if (event.motion.x>104 && event.motion.y>412 && event.motion.x<367 && event.motion.y<461 )
    			{
    				op=1;
					Mix_PlayChannel(1,sound,0);

    			}
    			else if (event.motion.x>104 && event.motion.y>332 && event.motion.x<367 && event.motion.y<381 )
    			{
    				lg=1; Mix_PlayChannel(1,sound,0);

    			}
    			else if (event.motion.x>104 && event.motion.y>492 && event.motion.x<367 && event.motion.y<541 )
    			{
    				ex=1; Mix_PlayChannel(1,sound,0);
    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    				if (ng==1)
    				{
    				
    					ng=2;

    				}
    				else if (op==1)
    				{
    			
    		op=2;
    		
    				}
    				else if (lg==1)
    				{
    
    				lg=2;

    				}
    				else if (ex==1)
    				{
    			ex=2;
    			
    				}
    			}
    		break;


    	}

    	}
if (c==0) break;

 }
   	
    	
		
		

switch(continuer)
{case 1 :map();
continuer=-1;break;
case 3 :options(screen,&a) ;
continuer=-1;

break;
case 2 :
continuer=-1;
break;}
}
// free
liberer(background);
    	liberer(newgame[2]);
    	liberer(option[2]);
    	liberer(exit[2]);
    	liberer(newgame[0]);
    	liberer(newgame[1]);
    	liberer(option[0]);
    	liberer(option[1]);
    	liberer(loadgame[0]);
    	liberer(exit[0]);
    	liberer(exit[1]);
    	//TTF_CloseFont(policeTitre);
        Mix_FreeMusic(music);
SDL_Quit();

return 0 ;}
