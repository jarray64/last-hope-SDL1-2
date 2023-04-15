#include "player.h"
#include "map.h"
#include "alissa.h"
#include "hached.h"
#include "benali.h"
#include "game.h"
#include "enigme.h"
#include "pingpong.h"
void map()
{
    int done = 1,m1=-1,m2=-1,m3=-1,q=-1,i=1;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Surface *screen, *bg,*pc,*background;

    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    int score=0;

    SDL_Rect bgPos;
    bgPos.x = 0;
    bgPos.y = 0;

char filename[30];
    Perso p;
    init_Persomap(&p);
int n=-1;
  char filesave[50]="enigmesave.txt";

    char file[15]="score.txt";
high highsc;
  
    bg = IMG_Load("ezgif-frame-002.png");


pc = IMG_Load("choose player.png");
    SDL_Event event,evento;

             while(q==-1){
               SDL_BlitSurface(pc, NULL, screen, NULL);
             SDL_Flip(screen);
     if (SDL_PollEvent(&event)){
    	switch(event.type)
{

    		//avec clavier
    		case SDL_KEYDOWN://click clavier
    			switch(event.key.keysym.sym){

    				case SDLK_e:
    				q=1;
    				break;
    				case SDLK_f:
    				q=2;

    				break;}}break;}}



    SDL_EnableKeyRepeat(1, 0);
    while (done)
    {
         SDL_BlitSurface(bg, NULL, screen, &bgPos);



       

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done = 0;
                    break;

               
                     case SDLK_UP:
                    p.i.up = 1;
                    p.currentMode = 4;
                  n=0;
                
                    break;
                    case SDLK_DOWN:
                    p.i.down = 1;
                    p.currentMode = 5;
n=1;
                    break;
                    

                case SDLK_RIGHT:
                    p.i.right = 1;
                    p.currentMode = 6;
                 n=2;
                    break;

                case SDLK_LEFT:
                   p.i.left = 1;
                    p.currentMode = 7;
                                    n=3;
                    break;

               
                }
                break;

            case SDL_KEYUP://m3ach tclicki 3l boutton howa hnee 93d YRAj3 fi position initial
                switch (event.key.keysym.sym)
                {
                

                case SDLK_RIGHT:
                
                   
                    p.i.right = 0;
                    p.currentMode = 2;
                    

                                    
                    break;

                case SDLK_LEFT:
                    p.i.left = 0;
                    p.currentMode = 3;
                                    //n=5;
                    break;
                    
                    case SDLK_UP:
                     
                    p.i.up = 0;
                    p.currentMode = 0; 
                                                        // n=6;
                    break;
                    case SDLK_DOWN:
                    p.i.down = 0;
                    p.currentMode = 1;  
                                                     //   n=7;               
                    break; 
                    
               
                }
                break;
            }
          // n=-1; 
        }

        //run left and right
 leftAndRightPersoMvtmap(&p);

char chaine[50]="\0";
        SDL_BlitSurface(bg, NULL, screen, &bgPos);
        idleAnimationmap(&p);
        runAnimationmap(&p);
if (p.PersoPos.x<526 && p.PersoPos.x>493 && p.PersoPos.y<271 && p.PersoPos.y>247){
while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_e:if (m2!=1){
                                i=21;
                while(i<=25){

                sprintf(filename,"speach/%d.png",i);
                background = IMG_Load(filename);
        SDL_BlitSurface(background,NULL,screen,NULL);
            SDL_Flip(screen);
                SDL_Delay(4000);
        i++;
        }
        
m2=hached(q);
AI();
if(m2==1){
                sprintf(filename,"speach/26.png");
                 background = IMG_Load(filename);
        SDL_BlitSurface(background,NULL,screen,NULL);
            SDL_Flip(screen);}

                    break;}}}}}
if (p.PersoPos.x<808 && p.PersoPos.x>748 && p.PersoPos.y<634 && p.PersoPos.y>580){
while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_e:if (m1!=1){
                i=11;
                  while(i<=15){

                sprintf(filename,"speach/%d.png",i);
                background = IMG_Load(filename);
        SDL_BlitSurface(background,NULL,screen,NULL);
            SDL_Flip(screen);
                SDL_Delay(4000);
        i++;
        }
m1=alissa(q);
printf("%d",m1);
if(m1==1){
                sprintf(filename,"speach/26.png");
                 background = IMG_Load(filename);
        SDL_BlitSurface(background,NULL,screen,NULL);
            SDL_Flip(screen);}
                    break;}}}}}
if (p.PersoPos.x<943 && p.PersoPos.x>886 && p.PersoPos.y<76 && p.PersoPos.y>40){
while (SDL_PollEvent(&event))
        {int resultat;
            switch (event.type)
            {
            case SDL_QUIT:

                done = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_e:
               // m3=chargement(filesave);
                if (m3!=1){
                                i=1;
                while(i<=9){

                sprintf(filename,"speach/%d.png",i);
                background = IMG_Load(filename);
        SDL_BlitSurface(background,NULL,screen,NULL);
            SDL_Flip(screen);
                SDL_Delay(1000);
        i++;
        }

printf("%hn\n",&p.PersoPos.x);
printf("%hn\n",&p.PersoPos.y);
playername(screen ,chaine);
m3=benali(&score,q);
sauvgarder (score,chaine,file);
highsc=meilleur (file,score,chaine);
affichehigh(screen,highsc);
resultat=enigmee(screen) ;
//savegame(m3,filesave);
printf("RESULTAT= %d \n ",resultat);
                    break;}}}}}
        afficher_Persomap(&p, screen);

        SDL_Flip(screen);
        SDL_Delay(60);
        
    }

    SDL_FreeSurface(screen);
    SDL_Quit();

}
