#include "option.h"
void initsure(SDL_Surface *sure[]){
	sure[4]=IMG_Load("graphic/options/no selected.png");
    sure[0]=IMG_Load("graphic/options/yes s.png");
	sure[1]=IMG_Load("graphic/options/no s.png");
	sure[2]=IMG_Load("graphic/options/yes c.png");
	sure[3]=IMG_Load("graphic/options/no c.png"); 
    }
   void init(SDL_Surface *back[],SDL_Surface *full_screen[],SDL_Surface *keys[],SDL_Surface *music[],SDL_Surface *sfx[],SDL_Surface *boutton_sfx[],SDL_Surface *boutton_music[]){
back[0]=IMG_Load("graphic/options/backns.png");
	back[1]=IMG_Load("graphic/options/backs.png");
	full_screen[0]=IMG_Load("graphic/options/fsns.png");
	full_screen[1]=IMG_Load("graphic/options/fss.png");
	full_screen[2]=IMG_Load("graphic/options/fsc.png");
	keys[0]=IMG_Load("graphic/options/wmns.png");
	keys[1]=IMG_Load("graphic/options/wms.png");
        keys[2]=IMG_Load("graphic/options/wmc.png");
	
	music[0]=IMG_Load("graphic/options/vns.png");
    music[1]=IMG_Load("graphic/options/vs.png");
	sfx[1]=IMG_Load("graphic/options/sfxs.png");
	sfx[0]=IMG_Load("graphic/options/sfxns.png");

	boutton_sfx[0]=IMG_Load("graphic/options/sfx0.png");
	boutton_sfx[1]=IMG_Load("graphic/options/sfx20.png");
	boutton_sfx[2]=IMG_Load("graphic/options/sfx40.png");
	boutton_sfx[3]=IMG_Load("graphic/options/sfx60.png");
	boutton_sfx[4]=IMG_Load("graphic/options/sfx80.png");
	boutton_sfx[5]=IMG_Load("graphic/options/sfx100.png");
	//appel main

	boutton_music[0]=IMG_Load("graphic/options/v0.png");
	boutton_music[1]=IMG_Load("graphic/options/v20.png");
	boutton_music[2]=IMG_Load("graphic/options/v40.png");
	boutton_music[3]=IMG_Load("graphic/options/v60.png");
	boutton_music[4]=IMG_Load("graphic/options/v80.png");
	boutton_music[5]=IMG_Load("graphic/options/v100.png");
 
    }
void affichagesure(SDL_Surface *img,SDL_Surface *screen,SDL_Rect background_pos){
	    SDL_BlitSurface(img,NULL,screen,&background_pos);
		}
		void libere(SDL_Surface *img){
SDL_FreeSurface(img);}
int windo(SDL_Surface *ecran)
{
	SDL_Surface *sure[5];
	int n=0;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
initsure(sure);


    while(1)
    {
    affichagesure(sure[n],ecran,pos);
    	SDL_Flip(ecran);
    	if(SDL_PollEvent(&event)){
    
    	switch(event.type)
    	{

			//avec clavier
    		case SDL_KEYDOWN:

    			switch(event.key.keysym.sym)
    			{
    				case SDLK_UP:
    				if (n==4) n=0;
						if (n==0)
						{
							n++;
							
						}
						else if (n==1)
						{
							n--;
							
						}
					break;

					case SDLK_DOWN:
					if (n==4) n=0;
						if (n==0)
						{
							n++;
						
						}
						else if (n==1)
						{
							n--;
							
						}
					break;

					case SDLK_RETURN:
						if (n==0)//yes
						{n=2;
    				
  							ecran=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE |SDL_DOUBLEBUF );
    				return 0;
						}
						else if (n==1)//no
						{n=2;
							n=0; 
							return 0;
						}
					break;
						    			}
    		break;
			// avec souris
    		case SDL_MOUSEMOTION:
			n=4;
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=0;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=2;
    											ecran=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE |SDL_DOUBLEBUF );
				return 0;}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					n=2;
    				 n=0;
					return 0;
				}
			break;
    	}
    }}
}

int fullscreen(SDL_Surface *ecran)
{
	SDL_Surface *sure[5];
	int n=0;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;

	initsure(sure);


    while(1)
    {
    affichagesure(sure[n],ecran,pos);
    	SDL_Flip(ecran);
    	SDL_WaitEvent(&event);
    	
    	switch(event.type)
    	{

			//avec clavier
    		case SDL_KEYDOWN:

    			switch(event.key.keysym.sym)
    			{
    				case SDLK_UP:
    				if (n==4) n=0;
						if (n==0)
						{
							n++;
							
						}
						else if (n==1)
						{
							n--;
							
						}
					break;

					case SDLK_DOWN:
					if (n==4) n=0;
						if (n==0)
						{
							n++;
						
						}
						else if (n==1)
						{
							n--;
							
						}
					break;

					case SDLK_RETURN:
						if (n==0)//yes
						{n=2;
    												ecran=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
    				return 0;
						}
						else if (n==1)//no
						{n=3;
							n=0;
							return 0;
						}
					break;
						    			}
    		break;

// avec souris
    		case SDL_MOUSEMOTION:
			n=4;
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=0;
				}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392)
				{
					n=1;
				}
			break;

			case SDL_MOUSEBUTTONDOWN:
				if (event.motion.x>317 && event.motion.y>312 && event.motion.x<488 && event.motion.y<392)
				{
					n=2;
    					ecran=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE |SDL_DOUBLEBUF |SDL_FULLSCREEN);
				return 0;}
				else if (event.motion.x>521 && event.motion.y>312 && event.motion.x<699 && event.motion.y<392 )
				{
					n=3;
    			n=0;
					return 0;
				}
			break;
    	}
    }
}

void options(SDL_Surface *screen,int *action)
{

SDL_Surface *background,*boutton_sfx[6],*boutton_music[6],*full_screen[3],*keys[3],*music[2],*sfx[2],*back[2];
	int m=1,s=0,ks=0,fs=0,n=1,q=1,p_sfx,volume_sfx=100,p_music,volume_music=100,mp=0,bk=0;
	p_sfx=volume_sfx/20;
	p_music=volume_music/20;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	Mix_Chunk *sfx_sound;
	Mix_Music *music_sound;
	
	background=IMG_Load("graphic/options/nothing.png");
	init(back,full_screen,keys,music,sfx,boutton_sfx,boutton_music);
	sfx_sound= Mix_LoadWAV("graphic/option/gh.wav");
music_sound= Mix_LoadMUS("graphic/option/option.mp3");
Mix_VolumeMusic(volume_music);
Mix_PlayMusic(music_sound,-1);

	while(event.key.keysym.sym!=SDLK_ESCAPE &&q!=0){ //while
	//affichage des images
	affichagesure(background,screen,pos);
	affichagesure(full_screen[fs],screen,pos);
	affichagesure(sfx[s],screen,pos);
	affichagesure(music[m],screen,pos);
	affichagesure(back[bk],screen,pos);
	affichagesure(keys[ks],screen,pos);
	affichagesure(boutton_sfx[p_sfx],screen,pos);
	affichagesure(boutton_music[p_music],screen,pos);
        SDL_Flip(screen); //test
        if (fs==2) {
        fs=0;
        fullscreen(screen);}
if (ks==2) {
        ks=0;
        windo(screen);}
    
    	if (SDL_PollEvent(&event)){
    	switch(event.type)
{
case SDL_QUIT:
(*action)=0;
	q=0;
break;
    		//avec clavier
    		case SDL_KEYDOWN:
    			switch(event.key.keysym.sym)
    			{

    				case SDLK_UP:

						if (m==0 && s==0 && fs==0 && ks==0) //variable
    				{s=1;
    				}
    					if (m==1){

    						ks=1;
    						m=0;
    				fs=0;
    						s=0;
    						
    						n=3;
    					}
    					else if(s==1){
									
                                m=1;
                                s=0;
                                ks=0;
                                fs=0;
                                
                n=1;
										      	}
    					else if (ks==1){
    						s=0;
    						ks=0;
    					fs=1;
    						m=0;
    						
    		n=2;
    					}
                        else if (fs==1)
                        {
                            s=1;
                            fs=0;
                            m=0;
                            ks=0;
                            
            n=2;
}
else if(n==3)	{
						if (ks==0)
						{
						if (fs==0){
						ks++;}
						else{
							fs--;
							ks++;}
							
						}
						else if (ks==1)
						{
							fs++;
							ks--;
							
						}
						}
    				break;

    				case SDLK_DOWN:

    				if (m==0 && s==0 && ks==0 && fs==0)
    				{ks=1;}
    					if (m==1){

                                m=0;
                                s=1;
                                ks=0;
                                fs=0;
                           n=2;
    					}
    					else if(s==1){
							

    						m=0;
    						s=0;
    						ks=0;
    						fs=1;
    						
    						n=3;
							}
    					else if (ks==1){
    						ks=0;
    						fs=0;
    						m=1;
    						s=0;
    						
    						 n=1;

							}
                        else if (fs==1)
                        {
                            ks=1;
                            s=0;
                            m=0;
                            fs=0;
                           
                             n=1;

									      }
									  else    if(n==3)	{
						if (ks==0 )
						{
							if (fs==0){
						ks++;}
						else{
							fs--;
							ks++;}
							
						}
						else if (ks==1)
						{
							fs++;
							ks--;
							
						}
						}
    				break;
    				case SDLK_LEFT:
						if (n==1){
						if (volume_music>0)
						{
							p_music--;
							volume_music-=20;
						Mix_VolumeMusic(volume_music);
						}}
						else if (n==2){
						if (volume_sfx>0)
						{
							p_sfx--;
							volume_sfx-=20;
							mp=1;
						Mix_VolumeChunk(sfx_sound,volume_sfx);
				Mix_PlayChannel(-1,sfx_sound, 0); // appel
						}}
    			/*else	if(n==3)	{
						if (ks==0)
						{
						if (fs==0){
						ks++;}
						else{
							fs--;
							ks++;}
							
						}
						else if (ks==1)
						{
							fs++;
							ks--;
							
						}
						}*/
					break;

					case SDLK_RIGHT:
					if (n==1){
					if (volume_music<100)
					{
						p_music++;
						volume_music+=20;
					Mix_VolumeMusic(volume_music);
					}}
				else	if (n==2){
					if (volume_sfx<100)
					{
						p_sfx++;
						volume_sfx+=20;
						mp=1;
						Mix_VolumeChunk(sfx_sound,volume_sfx);
				Mix_PlayChannel(-1,sfx_sound, 0);//appel
					}}
					/*else if(n==3)	{
						if (ks==0 )
						{
							if (fs==0){
						ks++;}
						else{
							fs--;
							ks++;}
							
						}
						else if (ks==1)
						{
							fs++;
							ks--;
							
						}
						}*/
					break;

    				case SDLK_RETURN:

    					if (ks==1)
    					{
    						ks=2;

    			
    					}
                        else if (fs==1)
                        {
                          fs=2;

                          
                        }
    				break;
    			}
    		break;

//avec souris
   		case SDL_MOUSEMOTION:
//
    				m=0;
    				s=0;
    				fs=0;
    				ks=0;
    			if (event.motion.x>18 && event.motion.y>131 && event.motion.x<434 && event.motion.y<161)
    			{
    			m=1;

    			}

    			else if (event.motion.x>18 && event.motion.y>161 && event.motion.x<434 && event.motion.y<191)
    			{

    				s=1;

    			}
    			else if (event.motion.x>307 && event.motion.y>408 && event.motion.x<387 && event.motion.y<438 )
    			{
    				ks=1;

    			}
    			else if (event.motion.x>307 && event.motion.y>399 && event.motion.x<387 && event.motion.y<429 )
    			{
    				fs=1;

    			}
				else if (event.motion.x>10 && event.motion.y>17 && event.motion.x<45 && event.motion.y<54 )
    			{
    				bk=1;

    			}

    		break;

    		case SDL_MOUSEBUTTONDOWN:
    			if (event.button.button==SDL_BUTTON_LEFT)
    			{
    			if (event.motion.x>251 && event.motion.y>132 && event.motion.x<274 && event.motion.y<160)
						{
							if (volume_music>0)
							{
								p_music--;
								volume_music-=20;
							Mix_VolumeMusic(volume_music);

							}
    				//modife music ---
    				}

						else if (event.motion.x>408 && event.motion.y>132 && event.motion.x<431 && event.motion.y<160 )
							{
								if (volume_music<100)
								{
									p_music++;
									volume_music+=20;
									Mix_VolumeMusic(volume_music);

								}
				//modife music +++
						}
					else	if (event.motion.x>251 && event.motion.y>162 && event.motion.x<254 && event.motion.y<190)
							{
								if (volume_sfx>0)
								{mp=1;
									p_sfx--;
									volume_sfx-=20;
									Mix_VolumeChunk(sfx_sound,volume_sfx);
							Mix_PlayChannel(-1,sfx_sound, 0);
								}
				//modife sfx ---
							}
    				else if (event.motion.x>408 && event.motion.y>162 && event.motion.x<431 && event.motion.y<190 )
							{
								if (volume_sfx<100)
								{mp=1;
									p_sfx++;
									volume_sfx+=20;
									Mix_VolumeChunk(sfx_sound,volume_sfx);
							Mix_PlayChannel(-1,sfx_sound, 0);
								}
    				//modife sfx+++
    				}
    				else if (ks==1)
    				{
    				ks=2;
    
    				}
    				else if (fs==1)
    				{
    			fs=2;
    					
    				}
    				else if (bk=1 )
    			{
    				q= 0;

    			}
    			}
    		break;


    	}

    	}
 }



libere(background);
libere(full_screen[0]);
libere(full_screen[1]);
libere(full_screen[2]);
libere(keys[0]);
libere(keys[1]);
libere(keys[2]);
libere(music[1]);
libere(music[0]);
libere(sfx[1]);
libere(sfx[0]);
 
}

 void play(SDL_Surface *screen,int *action)
{

SDL_Surface *background;
	
	int q;
	SDL_Rect pos;
	SDL_Event event;
	pos.x=0;
	pos.y=0;
	
	background=IMG_Load("graphic/option/backg1.png");
	




	do{
	//affichage des images
	SDL_BlitSurface(background,NULL,screen,&pos);
       
        SDL_Flip(screen);

    	
    	if (SDL_WaitEvent(&event)){
    	switch(event.type)
{
case SDL_QUIT:
	q=0;
break;
    		
    		



 }}}while(event.key.keysym.sym!=SDLK_ESCAPE &&q!=0);



 	SDL_FreeSurface(background);
    	
 }
