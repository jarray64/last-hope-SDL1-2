#include "player.h"





void setrectsmap(SDL_Rect *crop)//y3bi fi tableau
{
   

    //idle right
    crop[0].x = 0;
    crop[0].y = 135;

    crop[0].w = 18;
    crop[0].h = 44;

   
        crop[1].w = 18;
        crop[1].h = 45;

        crop[1].x = crop[1].w + crop[0].x;// position fi spritsheet
        crop[1].y = 135;//ligne
    

    //idle left
    crop[2].x = 0;
    crop[2].y = 90;//repere mel star thani taw

    crop[2].w = 18;
    crop[2].h = 45;

   
        crop[3].w = 18;
        crop[3].h = 45;

        crop[3].x = crop[3].w + crop[2].x;
        crop[3].y = 90;
    

    //idle up
    crop[4].x = 0;
    crop[4].y = 45;

    crop[4].w = 18;
    crop[4].h = 45;

    
        crop[5].w = 18;
        crop[5].h = 45;

        crop[5].x = crop[5].w + crop[4].x;
        crop[5].y = 45;
    

    //idle down
    crop[6].x = 0;
    crop[6].y = 0;

    crop[6].w = 18;
    crop[6].h = 45;

    
        crop[7].w = 18;
        crop[7].h = 45;

        crop[7].x = crop[7].w + crop[6].x;
        crop[7].y = 0;
    
    //move right
    crop[8].x = 0;
    crop[8].y = 315;

    crop[8].w = 18;
    crop[8].h = 45;

    
        crop[9].w = 18;
        crop[9].h = 45;

        crop[9].x = crop[9].w + crop[8].x;// position fi spritsheet
        crop[9].y = 315;//ligne
    

    //move left
    crop[10].x = 0;
    crop[10].y = 270;//repere mel star thani taw

    crop[10].w = 18;
    crop[10].h = 45;

    
        crop[11].w = 18;
        crop[11].h = 45;

        crop[11].x = crop[11].w + crop[10].x;
        crop[11].y = 270;
    

    //move up
    crop[12].x = 0;
    crop[12].y = 225;

    crop[12].w = 18;
    crop[12].h = 45;

    
        crop[13].w = 18;
        crop[13].h = 45;

        crop[13].x = crop[13].w + crop[12].x;
        crop[13].y = 225;
    

    //move down
    crop[14].x = 0;
    crop[14].y = 180;

    crop[14].w = 18;
    crop[14].h = 45;

    
        crop[15].w = 18;
        crop[15].h = 45;

        crop[15].x = crop[15].w + crop[14].x;
        crop[15].y = 180;
    }

void init_Persomap(Perso *p)
{

    p->sprite = IMG_Load("sprites/fighterfinally.png");

    p->frame = 0;
    p->currentMode = 0;

    p->PersoPos.x = 301;
    p->PersoPos.y = 445;

 


    p->xStep = 10;
    p->yStep = 10;
    p->i.left = 0;
    p->i.right = 0;
    
    p->i.down = 0;
   
    p->i.up = 0;

    setrectsmap(p->rects);
}

void afficher_Persomap(Perso *p, SDL_Surface *screen)
{
    SDL_BlitSurface(p->sprite, &p->rects[p->frame], screen, &p->PersoPos);
               // SDL_Delay(30);
}

void idleAnimationmap(Perso *p)//initialisation ll 0
{
    if (p->currentMode == 0)
    {
        if (p->frame < 4 || p->frame > 5)
        {
            p->frame = 4;
        }
        p->frame++;

        if (p->frame > 5)
        {
            p->frame = 4;
        }
    }
    else if (p->currentMode == 1)
    {

        if (p->frame < 6 || p->frame > 7)
        {
            p->frame = 6;
        }
        p->frame++;

        if (p->frame > 7)
        {
            p->frame = 6;
        }
    }
    else if (p->currentMode == 2)
    {

        if (p->frame < 0 || p->frame > 1)
        {
            p->frame = 0;
        }
        p->frame++;

        if (p->frame > 1)
        {
            p->frame = 0;
        }
    }
    else if (p->currentMode == 3)
    {

        if (p->frame < 2 || p->frame > 3)
        {
            p->frame = 2;
        }
        p->frame++;

        if (p->frame > 3)
        {
            p->frame = 2;
        }
    }
}







void runAnimationmap(Perso *p)
{
    if (p->currentMode == 4)
    {
        if (p->frame < 12 || p->frame > 13)
        {
            p->frame = 12;
        }
        p->frame++;
        if (p->frame > 13)
        {
            p->frame = 12;
        }
    }
    else if (p->currentMode == 5)
    {
        if (p->frame < 14 || p->frame > 15)
        {
            p->frame = 14;
        }
        p->frame++;
        if (p->frame > 15)
        {
            p->frame = 14;
        }
    }
   else if (p->currentMode == 6)
    {
        if (p->frame < 8 || p->frame > 9)
        {
            p->frame = 8;
        }
        p->frame++;
        if (p->frame > 9)
        {
            p->frame = 8;
        }
    }
    else if (p->currentMode == 7)
    {
        if (p->frame < 10 || p->frame > 11)
        {
            p->frame = 10;
        }
        p->frame++;
        if (p->frame > 11)
        {
            p->frame = 10;
        }
    }
}
void leftAndRightPersoMvtmap(Perso *p)
{
   
    
        if (p->i.right == 1)
        {
            p->xStep = 10;
            p->PersoPos.x += p->xStep;
           
        }

        if (p->i.left == 1)
        {
            p->xStep = 10;
            p->PersoPos.x -= p->xStep;
            
        }
        if (p->i.up == 1)
        {
            p->yStep = 10;
            p->PersoPos.y -= p->yStep;
           
        }

        if (p->i.down == 1)
        {
            p->yStep = 10;
            p->PersoPos.y += p->yStep;
            
        }
    
    
}
