#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "pingpong.h"
void setrects_pingpong(SDL_Rect* clip)
{

        clip[0].x = 0;
        clip[0].y = 200;
        clip[0].w = 30;
        clip[0].h = 240;

        clip[1].x = 321;
        clip[1].y = 330;
        clip[1].w = 62;
        clip[1].h = 100;

        clip[2].x = 480;
        clip[2].y = 0;
        clip[2].w = 120;
        clip[2].h = 780;

        clip[3].x = 970;
        clip[3].y = 200;
        clip[3].w = 30;
        clip[3].h = 240;


 }

int Bounding_Box_pingpong(SDL_Rect ball,SDL_Rect obstacl )
{
    if((ball).y >= (obstacl).y + (obstacl).h)
     return 0 ;
    if((ball).x >= (obstacl).x + (obstacl).w )
     return 0 ;
    if((ball).y  + (ball).h  <= (obstacl).y)
     return 0 ;
    if((ball).x  + (ball).w   <= (obstacl).x)
     return 0 ;
   
    return 1 ;
}



void initialiser(balls *B,surf *player,surf *compt,score_pingpong *scoreplayer,score_pingpong *scorecom,surf *net  )
{

       net->img=IMG_Load("ping pong_1000_800.png"); //net separation
       net->position.x=465;
       net->position.y=0;

       B->speed=1; //ball
       B->velocityX=2; //nbre de pixel par pas 
       B->velocityY=2;
       B->ball_position.x=432;
       B->ball_position.y=365;
       B->ball=IMG_Load("ping pong 1.png");

       player->position.x=0; //player dans le main
       player->position.y=250;
       player->img=IMG_Load("ping pong_1000_800.png");

       compt->position.x=950; //pc 
       compt->position.y=250;
       compt->img=IMG_Load("ping pong_1000_800.png");

     	 scoreplayer->positionscore.x=350;
	 scoreplayer->positionscore.y=10;
         scoreplayer->score=0;
         sprintf(scoreplayer->score_ch, " %d", scoreplayer->score);
         scoreplayer->police = TTF_OpenFont("yass.ttf",80) ;

    	 scorecom->positionscore.x=500;
	 scorecom->positionscore.y=10;
         scorecom->score=0;
         sprintf(scorecom->score_ch, " %d", scorecom->score);
         scorecom->police = TTF_OpenFont("yass.ttf",80) ;


       

}

void update_game(balls *B,score_pingpong *scoreplayer,score_pingpong *scorecom)
{
     if((B->ball_position.x<=0)||(B->ball_position.x>=950))
	{
		if(B->ball_position.x>=950)
                {
               scoreplayer->score++;
               sprintf(scoreplayer->score_ch, " %d", scoreplayer->score);
              // scoreplayer->text = TTF_RenderText_Blended(scoreplayer->police,scoreplayer->score_ch, couleur);
		}
		if(B->ball_position.x<=0)
                {
                 scorecom->score++;
                sprintf(scorecom->score_ch, " %d", scorecom->score);
              // scorecom->text = TTF_RenderText_Blended(scorecom->police,scorecom->score_ch, couleur);
		}

               B->ball_position.x=432;
               B->ball_position.y=365;
               B->speed=1;
               B->velocityX=2;
               B->velocityY=2;

       
	}


}


void Afficher_Game(SDL_Surface *screen, surf *net ,balls *B,score_pingpong *scoreplayer,score_pingpong *scorecom,surf*player,surf *compt,SDL_Rect objects[])
{ //object==clip


         SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 35, 222, 255));

          SDL_BlitSurface(net->img,&objects[2] ,screen,&net->position);

          SDL_BlitSurface(scoreplayer->text, NULL, screen, &scoreplayer->positionscore); 
          SDL_BlitSurface(scorecom->text, NULL, screen, &scorecom->positionscore); 

          SDL_BlitSurface(B->ball,&objects[1] ,screen,&B->ball_position);  

          SDL_BlitSurface(player->img,&objects[0] ,screen,&player->position);      
          SDL_BlitSurface(compt->img,&objects[3] ,screen,&compt->position);   
          SDL_Flip(screen);     



}
/*----------------------------------------------------------------------------------------------------------*/

void AI() //int argc, char **argv[]
{
    SDL_Surface *screen = NULL;
    SDL_Event event;
    SDL_Rect objects[4];
    setrects_pingpong(objects);
    int continuer = 1;
    int screen_w=1000,screen_h=740;
    int direction;
    double speedcomp=0.1;
    double mouse_y;

    printf("***************");
    balls B;
    surf player,compt,net; //separation
    score_pingpong scoreplayer,scorecom ;
    SDL_Color couleur = {255, 255, 255};


    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    initialiser(&B,&player,&compt,&scoreplayer,&scorecom,&net );
    scoreplayer.text = TTF_RenderText_Blended(scoreplayer.police,scoreplayer.score_ch, couleur);
    scorecom.text = TTF_RenderText_Blended(scorecom.police,scorecom.score_ch, couleur);


    screen = SDL_SetVideoMode(screen_w,screen_h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("PING PONG", NULL);






    while(continuer==1)
    {
        if((scoreplayer.score>=3)||(scorecom.score>=3))
        {
            continuer=0;
        }

        SDL_PollEvent(&event);
        switch(event.type)
        {
        case SDL_QUIT:
            continuer = 0 ;
            break;

        case SDL_KEYDOWN :
            switch (event.key.keysym.sym)
            {
            case  SDLK_ESCAPE:
                continuer=0;
                break;

            } //fin switch clavier
            break;

        case SDL_MOUSEMOTION :

            mouse_y=event.motion.y;
            player.position.y=mouse_y-120;

            break;




        }


        if((B.ball_position.y<=0)||(B.ball_position.y>=680))
        {

            B.velocityY=-B.velocityY; //inverser le sens up/down

        }

        if( (Bounding_Box_pingpong( B.ball_position,player.position  )==1)||(Bounding_Box_pingpong(B.ball_position, compt.position )==1))
        {

            // everytime ball hit panel speeed ++*/
            B.velocityX=-B.velocityX;
            B.speed+=0.2;

        }


        update_game(&B,&scoreplayer,&scorecom);
        scoreplayer.text = TTF_RenderText_Blended(scoreplayer.police,scoreplayer.score_ch, couleur);
        scorecom.text = TTF_RenderText_Blended(scorecom.police,scorecom.score_ch, couleur);

        B.ball_position.x+=B.velocityX*B.speed; //mouvement
        B.ball_position.y+=B.velocityY*B.speed;
        compt.position.y += ( B.ball_position.y - ( compt.position.y + objects[3].h/2 ) ) * speedcomp   ; //mvt de la barre du pc

        if((scoreplayer.score>=3)||(scorecom.score>=3))
        {
            continuer=0;
        }


        Afficher_Game(screen,  &net, &B, &scoreplayer, &scorecom, &player, &compt, objects);



    }//fin while

/*
    if(scoreplayer.score==3)
    {
        return 1 ;
    }

    if(scorecom.score>=3)
    {
        return 0;
    }*/
    //lberaton :::::


    TTF_CloseFont(scoreplayer.police); /* Doit être avant TTF_Quit() */
    TTF_Quit();
    SDL_Quit();
	
}

