#include "perso.h"



int frameNb = 10;





void setrects(SDL_Rect *crop)//y3bi fi tableau
{
    int i;

    //idle right
    crop[0].x = 0;
    crop[0].y = 4;

    crop[0].w = 46;
    crop[0].h = 62;

    for (i = 1; i < frameNb; i++)
    {
        crop[i].w = 46;
        crop[i].h = 62;

        crop[i].x = crop[i].w + crop[i - 1].x;// position fi spritsheet
        crop[i].y = 4;//ligne
    }

    //idle left
    crop[10].x = 0;
    crop[10].y = 66;//repere mel star thani taw

    crop[10].w = 46;
    crop[10].h = 62;

    for (i = 11; i < 2 * frameNb; i++)// bach ymabdlch variable
    {
        crop[i].w = 46;
        crop[i].h = 66;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 66;
    }

    //run right
    crop[20].x = 0;
    crop[20].y = 136;

    crop[20].w = 27;
    crop[20].h = 70;

    for (i = 21; i < 3 * frameNb; i++)
    {
        crop[i].w = 27;
        crop[i].h = 70;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 136;
    }

    //run left
    crop[30].x = 0;
    crop[30].y = 206;

    crop[30].w = 27;
    crop[30].h = 70;

    for (i = 31; i < 4 * frameNb; i++)
    {
        crop[i].w = 27;
        crop[i].h = 70;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 206;
    }

    //jump right
    crop[40].x = 0;
    crop[40].y = 276;

    crop[40].w = 43;
    crop[40].h = 74;

    for (i = 41; i < 5 * frameNb; i++)
    {
        crop[i].w = 43;
        crop[i].h = 74;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 276;
    }

    //jump left
    crop[50].x = 0;
    crop[50].y = 350;

    crop[50].w = 43;
    crop[50].h = 74;

    for (i = 51; i < 6 * frameNb; i++)
    {
        crop[i].w = 43;
        crop[i].h = 74;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 350;
    }

    //attack right
    crop[60].x = 0;
    crop[60].y = 424;

    crop[60].w = 65;
    crop[60].h = 63;

    for (i = 61; i < 7 * frameNb; i++)
    {
        crop[i].w = 65;
        crop[i].h = 63;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 424;
    }

    //attack left
    crop[70].x = 0;
    crop[70].y = 487;

    crop[70].w = 65;
    crop[70].h = 63;

    for (i = 71; i < 8 * frameNb; i++)
    {
        crop[i].w = 65;
        crop[i].h = 63;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 487;
    }
    crop[80].x = 0;
    crop[80].y = 550;

    crop[80].w = 27;
    crop[80].h = 70;

    for (i = 81; i < 9 * frameNb; i++)
    {
        crop[i].w = 27;
        crop[i].h = 70;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 550;
    }
     crop[90].x = 0;
    crop[90].y = 620;

    crop[90].w = 27;
    crop[90].h = 70;

    for (i = 91; i < 10 * frameNb; i++)
    {
        crop[i].w = 27;
        crop[i].h = 70;

        crop[i].x = crop[i].w + crop[i - 1].x;
        crop[i].y = 620;
    }
}

void init_Perso(Perso *p)
{

    p->sprite = IMG_Load("sprites/tageya.png");

    p->frame = 0;
    p->currentMode = 0;
p->Ground=450;
    p->PersoPos.x = 335;
    p->PersoPos.y = p->Ground;

    p->acceleration = 0;
    p->vitesse = 0,3;

    p->xStep = 0,0001;
    p->yStep = 3;
    p->i.left = 0;
    p->i.right = 0;
    p->i.dashleft = 0;
    p->i.dashright = 0;
    p->i.down = 0;
    p->i.jump = 0;
    p->i.attack = 0;

    setrects(p->rects);
}
void init_Perso2(Perso *p)
{

    p->sprite = IMG_Load("sprites/tageya2.png");

    p->frame = 0;
    p->currentMode = 0;
p->Ground=450;
    p->PersoPos.x = 700;
    p->PersoPos.y = p->Ground;

    p->acceleration = 0;
    p->vitesse = 0,3;

    p->xStep = 0,0001;
    p->yStep = 3;
    p->i.left = 0;
    p->i.right = 0;
    p->i.dashleft = 0;
    p->i.dashright = 0;
    p->i.down = 0;
    p->i.jump = 0;
    p->i.attack = 0;

    setrects(p->rects);
}

void afficher_Perso(Perso *p, SDL_Surface *screen)
{
    SDL_BlitSurface(p->sprite, &p->rects[p->frame], screen, &p->PersoPos);
               // SDL_Delay(30);
}

void idleAnimation(Perso *p)//initialisation ll 0
{
    if (p->currentMode == 0)
    {
        if (p->frame < 0 || p->frame > 9)
        {
            p->frame = 0;
        }
        p->frame++;

       if (p->frame > frameNb - 1)
        {
            p->frame = 0;
        }
    }
    else if (p->currentMode == 1)
    {

        if (p->frame < 10 || p->frame > 19)
        {
            p->frame = 10;
        }
        p->frame++;

        if (p->frame > 19)
        {
            p->frame = 10;
        }
    }
}

void runAnimation(Perso *p)
{
    if (p->currentMode == 2)
    {
        if (p->frame < 20 || p->frame > 29)
        {
            p->frame = 20;
        }
        p->frame++;
        if (p->frame > 29)
        {
            p->frame = 20;
        }
    }
    else if (p->currentMode == 3)
    {
        if (p->frame < 30 || p->frame > 39)
        {
            p->frame = 30;
        }
        p->frame++;
        if (p->frame > 39)
        {
            p->frame = 30;
        }
    }
}
void DashAnimation(Perso *p, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos)
{
    int i;


    if (p->currentMode == 9)
    {
  
       if (p->frame < 80 || p->frame > 89)
        {
            p->frame = 80;
        }
        p->frame++;
        if (p->frame > 89)
        {
            p->frame = 80;
        }
    }
    else if (p->currentMode == 10)
    {
   
        if (p->frame < 90 || p->frame > 99)
        {
            p->frame = 90;
        }
        p->frame++;
        if (p->frame > 99)
        {
            p->frame = 90;
        }
    }

}
void leftAndRightPersoDash(Perso *p)//movement
{
    if (p->currentMode == 9 || p->currentMode == 10)
    {
        if (p->i.dashright == 1)
        {
            p->PersoPos.x =p->PersoPos.x+ p->acceleration*100000;
        }

        if (p->i.dashleft == 1)
        {
            p->PersoPos.x =p->PersoPos.x- p->acceleration*100000;
        }
    }
}

void jumpAnimation(Perso *p, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos, int run)
{
    int i;
    if (p->currentMode == 4)
    {
        for (i = 40; i < 50; i++)
        {
            p->frame = i;

            if (i > 44)
            { if (p->acceleration==0)
            p->PersoPos.y += 10;
            else
                p->PersoPos.y += 10000*p->acceleration;//hero pos ybadelha maw ynagz
            }
            else
            {
            if (p->acceleration==0)
           p->PersoPos.y -= 10;
            else
                p->PersoPos.y -= 10000*p->acceleration;
            }
            if (run == 1)
            {
                p->PersoPos.x += 10000*p->acceleration;
            }
           SDL_BlitSurface(bg, NULL, screen, &bgPos);
                             //SDL_BlitSurface(p->hb, NULL, screen, &bgPos);
            SDL_BlitSurface(p->sprite, &p->rects[p->frame], screen, &p->PersoPos);
            SDL_Flip(screen);
            SDL_Delay(60);
        }
    }
    else if (p->currentMode == 5)
    {
        for (i = 50; i < 60; i++)
        {
            p->frame = i;

            if (i > 54)
            {
            if (p->acceleration==0)
            p->PersoPos.y += 10;
            else
                p->PersoPos.y += 10000*p->acceleration;
            }
            else
            {
            if (p->acceleration==0)
            p->PersoPos.y -= 10;
            else
                p->PersoPos.y -= 10000*p->acceleration;
            }

            if (run == 1)
            {
                p->PersoPos.x -= 10000*p->acceleration;
            }
            SDL_BlitSurface(bg, NULL, screen, &bgPos);
                             // SDL_BlitSurface(p->hb, NULL, screen, &bgPos);
            SDL_BlitSurface(p->sprite, &p->rects[p->frame], screen, &p->PersoPos);
            SDL_Flip(screen);
            SDL_Delay(60);
        }
    }
}

void attackAnimation(Perso *p, SDL_Surface *screen, SDL_Surface *bg, SDL_Rect bgPos)
{
    int i;
SDL_Rect attack;

    if (p->currentMode == 6)
    {
// double boucle pour un evenement
        if (p->frame < 60 || p->frame > 69)
        {
            p->frame = 60;
        }
        p->frame++;
        if (p->frame > 69)
        {
            p->frame = 60;
        }

        
    }
    else if (p->currentMode == 7)
    {

        if (p->frame < 70 || p->frame > 79)
        {
            p->frame = 70;
        }
        p->frame++;
        if (p->frame > 79)
        {
            p->frame = 70;
        }
      
    }

}



void jumpPersoMvt(Perso *p, int *run)
{
    if (p->i.jump == 1)
    {
        if (p->i.right == 1)
        {
            p->currentMode = 4;
            *run = 1;
        }
        else if (p->i.left == 1)
        {
            p->currentMode = 5;
            *run = 1;
        }
        else
        {
if (p->currentMode == 0)
            {
                p->currentMode = 4;
                *run = 0;
            }
            else if (p->currentMode == 1)
            {
                p->currentMode = 5;
                *run = 0;
            }
        }
    }
}
void leftAndRightHeroMvt(Perso *p)//movement
{
    if (p->currentMode == 2 || p->currentMode == 3)
    {
        if (p->i.right == 1)
        {
            p->PersoPos.x += p->xStep;
        }

        if (p->i.left == 1)
        {
            p->PersoPos.x -= p->xStep;
        }
    }
}
void leftAndRightPersoMvtR(Perso *p, Uint32 dt)
{
   
    
        if (p->i.right == 1)
        {
            p->xStep = 0.5 * p->acceleration * dt * dt + p->vitesse * dt;
            p->PersoPos.x += p->xStep;
            if (p->acceleration <0,0003)
            {
                p->acceleration += 0.0001;
            }
        }

        if (p->i.left == 1)
        {
            p->xStep = 0.5 * p->acceleration* dt * dt + p->vitesse * dt;
            p->PersoPos.x -= p->xStep;
            if (p->acceleration < 0,0003)
            {
                p->acceleration += 0.0001;
            }
        }//
    
    if (p->i.right == 0 && p->i.left == 0)
    {
        p->acceleration = 0;
    }
}
