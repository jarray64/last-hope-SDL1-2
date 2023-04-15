#include "fonction.h"
#include "perso.h"
int alissa(int q){
Mix_Music *music;
Mix_Chunk *sound[8],*sound1[10],*sound2,*sound3;
    int done = 1,i,j=1,k,b=0,l=0, run = 0,run1=0,n=-1,n1=-1,vm=50,vsfx=100,po=2;
    char filename[20],filename1[20];
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
int nb=0,v=0,s=0,s1=500,test=-1;
float distancex,distancey;
    SDL_Surface *screen, *bg,*boat;
ennemi e1,e2,e3,e4,e5,e6;
initennemi1(&e1);
initennemi2(&e2);
initennemi1(&e4);
initennemi1(&e5);
initennemi1(&e6);
initennemi1(&e3);
e1.posscreen.x=900;
e4.posscreen.x=900;
e3.posscreen.x=900;
e5.posscreen.x=900;
e6.posscreen.x=900;
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024);//initialiser le song
//declaration+changement de la musique
music= Mix_LoadMUS("music/theme.mp3");
Mix_VolumeMusic(vm);
//Mix_PlayMusic(music,-1);
for(i=0;i<8;i++){
        sprintf(filename,"music/%d.wav",i);
sound[i]= Mix_LoadWAV(filename);}
for(k=0;k<10;k++){
        sprintf(filename1,"music/l%d.wav",k);
sound1[k]= Mix_LoadWAV(filename1);
}
sound2= Mix_LoadWAV("music/dash.wav");
sound3= Mix_LoadWAV("music/j1.wav");
    bg = IMG_Load("alissa1.png");
    SDL_Rect bgPos,map1pos,boatpos;
    map1pos.x = 0;
    map1pos.y = 0;
    map1pos.w=1280;
    map1pos.h=720;
       boatpos.x=0;
    boatpos.y=0;
    Perso p;
            Perso p1;
    init_Perso(&p);
    if(q==2){

    init_Perso(&p1);
    }
    Uint32 dt, t_prev;

    SDL_Flip(screen);
    SDL_Event event;
            p.hb[0] = IMG_Load("graphic/health/2.png");
            p.hb[1] = IMG_Load("graphic/health/3.png");
        p.hb[2] = IMG_Load("graphic/health/4.png");
    SDL_EnableKeyRepeat(1, 0);
    while (done)
    {
    s1--;
    if (map1pos.x==1800)
    boatpos.x+=5;
    if(map1pos.x<1800){
        map1pos.x+=5;
        // p.PersoPos.x-=5;
        }

            t_prev = SDL_GetTicks();
         SDL_BlitSurface(bg, &map1pos, screen, NULL);
                                   SDL_BlitSurface(p.hb[po], NULL, screen, NULL);
         afficherennemi1(&e2,screen);
          deplacerdrouj(&e2,&test);
          animerennemi2(&e2);
          if (s!= 0)

        sprintf(filename,"boat/1%d.png",s);
        boat = IMG_Load(filename);
        SDL_BlitSurface(boat,NULL,screen,&boatpos); 
    s++;
        if (s > 5)
        {
            s = 0;
        }
         if (s1<=400){
afficherennemi1(&e3,screen);
 deplacedt(&e3,dt);
 animerennemi1(&e3);
 updateennemi(&e3,p.PersoPos,&distancex,&dt);    
}
if (s1<=300){
afficherennemi1(&e4,screen);
 deplacedt(&e4,dt);
 animerennemi1(&e4);
 updateennemi(&e4,p.PersoPos,&distancex,&dt);    
}
if (s1<=200){
afficherennemi1(&e5,screen);
 deplacedt(&e5,dt);
 animerennemi1(&e5);
 updateennemi(&e5,p.PersoPos,&distancex,&dt);    
}
if (s1<=100){
afficherennemi1(&e6,screen);
 deplacedt(&e6,dt);
 animerennemi1(&e6);
 updateennemi(&e6,p.PersoPos,&distancex,&dt);    
}
               //   SDL_BlitSurface(p.hb, NULL, screen, &bgPos);
                 if (q==2){                 leftAndRightPersoDash(&p1);

        leftAndRightPersoMvtR(&p1, dt);
        DashAnimation(&p1,screen,bg,bgPos);
        jumpAnimation(&p1, screen, bg, bgPos, run1);
        attackAnimation(&p1, screen, bg, bgPos);
        afficher_Perso(&p1, screen);
        SDL_Flip(screen);
        if (p1.currentMode == 0 || p1.currentMode == 2 || p1.currentMode == 6 || p1.currentMode == 9)//yejri ymchi yothrob ynagez el fayda 3l imin
        /* 0: idle imin
        1:idle isar
        2:yjri imin
        3:yjri isar
        4:nothing
        5:nothing
        6: yotherb imin
        7: yothreb isr
        8:nothing
        9:dash imin
        10 : dash isar
        */
        {
           p1.direction=0;
        }
        else//yejri ymchi yothrob ynagez el fayda 3l isar
        {
            p1.direction=1;
        }

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_z:
                    p1.i.jump = 1;
                                                               Mix_PlayChannel(1,sound3,0);
                    break;
                     case SDLK_e:
                    p1.i.attack = 1;
                    if (p1.direction== 0)
                    {
                        p1.currentMode = 6;
                    }
                    else
                    {
                        p1.currentMode = 7;
                    }
                                           Mix_PlayChannel(1,sound[j],0);
                                            j++;
                    break;
                    case SDLK_r:
                     if (p1.acceleration!=0){
                    if (p1.direction== 0)
                    {
                     p1.i.dashright = 1;
                        p1.currentMode = 9;  
                                             
                    }
                    else
                    {
                     p1.i.dashleft = 1;
                        p1.currentMode = 10;                       
                    }
                    Mix_PlayChannel(1,sound2,0);}
                    
                    break;

                case SDLK_d:
                    p1.i.right = 1;
                    p1.currentMode = 2;
                    n1=0;


                    break;

                case SDLK_q:
                   p1.i.left = 1;
                    p1.currentMode = 3;
                    n1=1;
             break;
                }
                break;
            case SDL_KEYUP://m3ach tclicki 3l boutton howa hnee 93d YRAj3 fi position initial
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    p1.i.jump = 0;
                    if (p1.i.right == 1)
                    {
                        p1.currentMode = 2;
                    }
                    else if (p.i.left == 1)
                    {
                        p1.currentMode = 3;
                    }
                    else
                    {
     if (p1.direction== 0)
                        {
                            p1.currentMode = 0;
                        }
                        else
                        {
                            p1.currentMode = 1;
                        }
                    }

                    break;
                     
                     

                case SDLK_z:
                    p1.i.right = 0;
                    p1.currentMode = 0;
                    run1 = 0;
                    n1=2;
                    nb=2;
                                        b++;

                    break;

                case SDLK_LEFT:
                    p1.i.left = 0;
                    p1.currentMode = 1;
                    run1 = 0;
                    n1=3;
                    nb=2;
                                        b++;

                    break;
                    case SDLK_e:
                     if (n1 == 0 || n1 == 1){
                    p1.i.attack = 0;
     if (p1.direction== 0)
                    {
                        p1.currentMode = 2;
                        p1.acceleration=0;
                    }
                    else
                    {
                        p1.currentMode = 3;
                        p1.acceleration=0;
                    }
                    }
                     if (n1 == 2 || n1 == 3 ||n1 == -1 ){
                    p1.i.attack = 0;
     if (p1.direction== 0)
                    {
                        p1.currentMode = 0;
                        p1.acceleration=0;
                    }
                    else
                    {
                        p1.currentMode = 1;
                        p1.acceleration=0;
                    }}

                    break;
                    case SDLK_r:
                      if (n1 == 0 || n1 == 1){
                    if (p1.acceleration!=0){
                    if (p1.direction== 0)
                    {
                    p1.i.dashright = 0;
                    p1.i.dashleft = 0;
                        p1.currentMode = 2;
                         p1.acceleration=p.acceleration/2;
                    }
                    else
                    {
                    p1.i.dashleft = 0;
                    p1.i.dashright = 0;
                        p1.currentMode = 3;
                         p1.acceleration=p.acceleration/2;

                    }}}
                     if (n1 == 2 || n1 == 3 ||n1 == -1 ){
                    if (p1.acceleration!=0){
                    if (p1.direction== 0)
                    {
                    p1.i.dashright = 0;
                    p1.i.dashleft = 0;
                        p1.currentMode = 0;
                         p1.acceleration=p.acceleration/2;
                    }
                    else
                    {
                    p1.i.dashleft = 0;
                    p1.i.dashright = 0;
                        p1.currentMode = 1;
                         p1.acceleration=p.acceleration/2;
                    }}
                    }
                    break;
               
                }
                break;
            }   
        }
 
  jumpPersoMvt(&p1, &run1);
        idleAnimation(&p1);
        runAnimation(&p1);
        leftAndRightHeroMvt(&p1);
       } 
       
                 leftAndRightPersoDash(&p);

        leftAndRightPersoMvtR(&p, dt);
        DashAnimation(&p,screen,bg,bgPos);
        jumpAnimation(&p, screen, bg, bgPos, run);
        attackAnimation(&p, screen, bg, bgPos);
        afficher_Perso(&p, screen);
        SDL_Flip(screen);
        SDL_Delay(60);
        if (p.currentMode == 0 || p.currentMode == 2 || p.currentMode == 6 || p.currentMode == 9)//yejri ymchi yothrob ynagez el fayda 3l imin
        /* 0: idle imin
        1:idle isar
        2:yjri imin
        3:yjri isar
        4:nothing
        5:nothing
        6: yotherb imin
        7: yothreb isr
        8:nothing
        9:dash imin
        10 : dash isar
        */
        {
           p.direction=0;
        }
        else//yejri ymchi yothrob ynagez el fayda 3l isar
        {
            p.direction=1;
        }

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
                case SDLK_SPACE:
                    p.i.jump = 1;
                                                               Mix_PlayChannel(1,sound3,0);
                    break;
                     case SDLK_x:
                    p.i.attack = 1;
                    if (p.direction== 0)
                    {
                        p.currentMode = 6;
                    }
                    else
                    {
                        p.currentMode = 7;
                    }
                                           Mix_PlayChannel(1,sound[j],0);
                                            j++;
                    break;
                    case SDLK_c:
                     if (p.acceleration!=0){
                    if (p.direction== 0)
                    {
                     p.i.dashright = 1;
                        p.currentMode = 9;  
                                             
                    }
                    else
                    {
                     p.i.dashleft = 1;
                        p.currentMode = 10;                       
                    }
                    Mix_PlayChannel(1,sound2,0);}
                    
                    break;

                case SDLK_RIGHT:
                    p.i.right = 1;
                    p.currentMode = 2;
                    n=0;


                    break;

                case SDLK_LEFT:
                   p.i.left = 1;
                    p.currentMode = 3;
                    n=1;
             break;
                }
                break;
            case SDL_KEYUP://m3ach tclicki 3l boutton howa hnee 93d YRAj3 fi position initial
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    p.i.jump = 0;
                    if (p.i.right == 1)
                    {
                        p.currentMode = 2;
                    }
                    else if (p.i.left == 1)
                    {
                        p.currentMode = 3;
                    }
                    else
                    {
     if (p.direction== 0)
                        {
                            p.currentMode = 0;
                        }
                        else
                        {
                            p.currentMode = 1;
                        }
                    }

                    break;
                     
                     

                case SDLK_RIGHT:
                    p.i.right = 0;
                    p.currentMode = 0;
                    run = 0;
                    n=2;
                    nb=2;
                                        b++;

                    break;

                case SDLK_LEFT:
                    p.i.left = 0;
                    p.currentMode = 1;
                    run = 0;
                    n=3;
                    nb=2;
                                        b++;

                    break;
                    case SDLK_x:
                     if (n == 0 || n == 1){
                    p.i.attack = 0;
     if (p.direction== 0)
                    {
                        p.currentMode = 2;
                        p.acceleration=0;
                    }
                    else
                    {
                        p.currentMode = 3;
                        p.acceleration=0;
                    }
                    }
                     if (n == 2 || n == 3 ||n == -1 ){
                    p.i.attack = 0;
     if (p.direction== 0)
                    {
                        p.currentMode = 0;
                        p.acceleration=0;
                    }
                    else
                    {
                        p.currentMode = 1;
                        p.acceleration=0;
                    }}

                    break;
                    case SDLK_c:
                      if (n == 0 || n == 1){
                    if (p.acceleration!=0){
                    if (p.direction== 0)
                    {
                    p.i.dashright = 0;
                    p.i.dashleft = 0;
                        p.currentMode = 2;
                         p.acceleration=p.acceleration/2;
                    }
                    else
                    {
                    p.i.dashleft = 0;
                    p.i.dashright = 0;
                        p.currentMode = 3;
                         p.acceleration=p.acceleration/2;

                    }}}
                     if (n == 2 || n == 3 ||n == -1 ){
                    if (p.acceleration!=0){
                    if (p.direction== 0)
                    {
                    p.i.dashright = 0;
                    p.i.dashleft = 0;
                        p.currentMode = 0;
                         p.acceleration=p.acceleration/2;
                    }
                    else
                    {
                    p.i.dashleft = 0;
                    p.i.dashright = 0;
                        p.currentMode = 1;
                         p.acceleration=p.acceleration/2;
                    }}
                    }
                    break;
               
                }
                break;
            }   
        }
        
if (p.frame>81 ||p.frame>91||p.frame>41||p.frame>51){
p.acceleration=0;
}
if( ((collisionBB(e1.posscreen,p.PersoPos)==0)&&e1.sprite!=NULL)||((collisionBB(e2.posscreen,p.PersoPos)==0)&&e2.sprite!=NULL)||((collisionBB(e3.posscreen,p.PersoPos)==0)&&e3.sprite!=NULL)||((collisionBB(e4.posscreen,p.PersoPos)==0)&&e4.sprite!=NULL)||((collisionBB(e5.posscreen,p.PersoPos)==0)&&e5.sprite!=NULL)||((collisionBB(e6.posscreen,p.PersoPos)==0)&&e6.sprite!=NULL)){
 //done=1;
 SDL_Delay(100);
 p.PersoPos.x-=50;
 po--;
 //arduinoWriteData(1);
 }
 
 
 if (((p.PersoPos.x+p.PersoPos.w<e6.posscreen.x+60)&&p.i.attack==1&&e5.sprite==NULL) ||((e6.posscreen.x+e6.posscreen.w<p.PersoPos.x+60)&&p.i.attack==1&&e5.sprite==NULL) ||((p.PersoPos.y+p.PersoPos.h<e6.posscreen.y+19)&&p.i.attack==1&&e5.sprite==NULL)||((e6.posscreen.y+e6.posscreen.h<p.PersoPos.y+15)&&p.i.attack==1&&e5.sprite==NULL))
e6.sprite=NULL;
if (((p.PersoPos.x+p.PersoPos.w<e5.posscreen.x+60)&&p.i.attack==1&&e4.sprite==NULL) ||((e5.posscreen.x+e5.posscreen.w<p.PersoPos.x+60)&&p.i.attack==1&&e4.sprite==NULL) ||((p.PersoPos.y+p.PersoPos.h<e5.posscreen.y+19)&&p.i.attack==1&&e4.sprite==NULL)||((e5.posscreen.y+e5.posscreen.h<p.PersoPos.y+15)&&p.i.attack==1&&e4.sprite==NULL))
e5.sprite=NULL;
 if (((p.PersoPos.x+p.PersoPos.w<e4.posscreen.x+60)&&p.i.attack==1&&e3.sprite==NULL) ||((e4.posscreen.x+e4.posscreen.w<p.PersoPos.x+60)&&p.i.attack==1&&e3.sprite==NULL) ||((p.PersoPos.y+p.PersoPos.h<e4.posscreen.y+19)&&p.i.attack==1&&e3.sprite==NULL)||((e4.posscreen.y+e4.posscreen.h<p.PersoPos.y+15)&&p.i.attack==1&&e3.sprite==NULL))
e4.sprite=NULL;
 if (((p.PersoPos.x+p.PersoPos.w<e3.posscreen.x+60)&&p.i.attack==1&&e2.sprite==NULL) ||((e3.posscreen.x+e3.posscreen.w<p.PersoPos.x+60)&&p.i.attack==1&&e2.sprite==NULL) ||((p.PersoPos.y+p.PersoPos.h<e3.posscreen.y+19)&&p.i.attack==1&&e2.sprite==NULL)||((e3.posscreen.y+e3.posscreen.h<p.PersoPos.y+15)&&p.i.attack==1&&e2.sprite==NULL))
e3.sprite=NULL;
      if (((p.PersoPos.x+p.PersoPos.w<e2.posscreen.x+60)&&p.i.attack==1&&e1.sprite==NULL) ||((e2.posscreen.x+e2.posscreen.w<p.PersoPos.x+60)&&p.i.attack==1&&e1.sprite==NULL) ||((p.PersoPos.y+p.PersoPos.h<e2.posscreen.y+19)&&p.i.attack==1&&e1.sprite==NULL)||((e2.posscreen.y+e2.posscreen.h<p.PersoPos.y+15)&&p.i.attack==1&&e1.sprite==NULL))
e2.sprite=NULL;
 if (((p.PersoPos.x+p.PersoPos.w<e1.posscreen.x+60)&&p.i.attack==1) ||((e1.posscreen.x+e1.posscreen.w<p.PersoPos.x+60)&&p.i.attack==1) ||((p.PersoPos.y+p.PersoPos.h<e1.posscreen.y+19)&&p.i.attack==1)||((e1.posscreen.y+e1.posscreen.h<p.PersoPos.y+15)&&p.i.attack==1)){
e1.sprite=NULL;
     }
        jumpPersoMvt(&p, &run);
        idleAnimation(&p);
        runAnimation(&p);
        leftAndRightHeroMvt(&p);
if (p.PersoPos.x>585&&p.PersoPos.x<760)
p.Ground=540;
else 
p.Ground=0;

if (map1pos.x>500){
 if (p.PersoPos.x>595&& p.PersoPos.x<910)
 p.PersoPos.y=450;
 else
 p.PersoPos.y=1200;}
 if (p.PersoPos.y==1200){
 po--;
  p.PersoPos.y=450;
   p.PersoPos.x=700;
}
 else if(boatpos.x>1280){
 printf("you win");
return 1; 
}
if (po==-1){
 printf("you lose");
return 0; 
}

distancex=p.PersoPos.x-e1.posscreen.x;
if(j>7){
    j=1;}
    if(b>3){
                    Mix_PlayChannel(1,sound1[l],0);
                                            l++;
                                            
    b=0;}
    if(l>9){
    l=1;}
    v++;
       dt = SDL_GetTicks() - t_prev;
    }
    libereres(&e1); 
        libereres(&e4); 
            libereres(&e3); 
                libereres(&e5); 
                    libereres(&e6); 
    SDL_FreeSurface(screen);
    SDL_FreeSurface(bg);
    SDL_FreeSurface(p.sprite);}
