 /**
  *@file fonction.c
  
  */
#include <stdio.h>
 #include<stdlib.h>
 #include"fonction.h"
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
 #include<math.h>

  
/**  
* @brief To initialize ennemi.  
* @param e1 the first ennemi   
* @return Nothing  type void
*/ 
 void initennemi1(ennemi *e1){
 e1->sprite=IMG_Load("graphic/farh.png");
 if(e1->sprite==NULL){
 return ;
 }
 e1->possprite.x=0;
 e1->possprite.y=0;
 e1->possprite.w=747/9; // nbre de ligne 1280/10
 e1->possprite.h=280/4; //nbre de colonne  327/2
 e1->posscreen.x=1280;
 e1->posscreen.y=450;
 e1->direction=0;
 e1->vitesse=0.3;
 }
 /*void initennemii1(ennemi *e11){
 e11->sprite=IMG_Load("graphic/farh2.png");
 if(e11->sprite==NULL){
 return ;
 }
 e11->possprite.x=0;
 e11->possprite.y=0;
 e11->possprite.w=747/9; // nbre de ligne 1280/10
 e11->possprite.h=145/2; //nbre de colonne  327/2
 e11->posscreen.x=1400;
 e11->posscreen.y=410;
 e11->direction=0;
 e11->vitesse=0.3;
 }*/
 
 
 /**  
* @brief To afficher l'immage de l' ennemi.  
* @param e1 utiliser pour afficher les deux ennemis e1 et e2
*@param screen la place sur l'ecran ou il seront afficher    
* @return Nothing  type void
*/  
 void afficherennemi1(ennemi *e1,SDL_Surface *screen){
 SDL_BlitSurface(e1->sprite,&e1->possprite,screen,&e1->posscreen);
 }
 /**  
* @brief liberer le stockage pour eleminer tout risque de saturation de stockage.  
* @param a quelque soit l'ennemi a   
* @return Nothing  type void
*/  
void libereres(ennemi *a){
SDL_FreeSurface(a->sprite);

}
/**  
* @brief animer l'ennemi.  
* @param e1 the first ennemi   
* @return Nothing  type void
*/  
 void animerennemi1(ennemi *e1){
 
e1->possprite.y=e1->direction * e1->possprite.h;
 if(e1->possprite.x==747-747/9)//e->possprite.w- e->possprite.h    1280-128
 {
 e1->possprite.x=0;
 }
 else {
 SDL_Delay(28);
 e1->possprite.x=e1->possprite.x+e1->possprite.w;
 }
 
 
 }
 
 
 
 ///***********deplacement
 /**  
* @brief deplacement manuelle horizontal l'ennemi.  
* @param e1 the first ennemi   
* @return Nothing  type void
*/  
  void deplacerx(ennemi *e1){
 if(e1->posscreen.x>1500)
 e1->direction=1;
 if(e1->posscreen.x<900)
 e1->direction=0;
 if(e1->direction==0){
 SDL_Delay (50);
 e1->posscreen.x=e1->posscreen.x +5;
 }
 else{SDL_Delay (50);
  e1->posscreen.x=e1->posscreen.x-5;
 }
 
 }
 ////////////////////////////////////////////////////////////////
 /**  
* @brief deplacement automatique 
* @param e1 the first ennemi   
*@param dt variable utilise dans le calcule de vitesse  deplacement  
* @return Nothing  type void
*/  
 void deplacedt(ennemi *e1,Uint32 dt){
 if(e1->posscreen.x>1280)//800
 e1->direction=1;
 if(e1->posscreen.x<700)//100
 e1->direction=0;
 if(e1->direction==0){
 //SDL_Delay (50);
 e1->posscreen.x+=e1->vitesse*dt*0.2;
 }
 else{//SDL_Delay (50);
  e1->posscreen.x-=e1->vitesse*dt*0.2;
 }
 
 
 }
 ////////deplacement haut bas
 /**  
* @brief deplacement manuelle vertical l'ennemi.  
* @param e1 the first ennemi   
* @return Nothing  type void
*/  
 void deplacery(ennemi *e1){
 if(e1->posscreen.y>350)
 e1->direction=1;
 if(e1->posscreen.y<50)
 e1->direction=0;
 if(e1->direction==0){
 SDL_Delay (50);
e1->posscreen.y=e1->posscreen.y +5;}
 else{SDL_Delay (50);
  e1->posscreen.y=e1->posscreen.y-5;
 }
 
 
 }
 ////////////////////////////////////////////////
 
 //////////////////////////////////////////
 /**  
* @brief deplacement manuelle sinusoidal l'ennemi.  
* @param e1 the first ennemi   ,test pour reouré si il a atteingne les limites
* @return Nothing  type void
*/  
 void deplacerdrouj(ennemi *e1,int *test){
 if(e1->posscreen.y==350)          
 *test=1;                
 if(e1->posscreen.y==50)                        
 *test=0;   
  if(e1->posscreen.x>1280){
 e1->direction=1;
 
 }
 if(e1->posscreen.x<900){
 e1->direction=0;
 }
 if(e1->direction==0){
 //SDL_Delay (30);
 e1->posscreen.x=e1->posscreen.x +15;
 
 if(*test==0){
 //SDL_Delay (50);
 //e1->posscreen.y=350;
 e1->posscreen.y+=10;
 }
 else{//SDL_Delay (30);
  e1->posscreen.y=e1->posscreen.y-10;
 }
 }
 else{
 //SDL_Delay (50);
  e1->posscreen.x=e1->posscreen.x-15;
 if(*test==0){
 //SDL_Delay (30);
 e1->posscreen.y+=10;}
 else{//SDL_Delay (30);
  e1->posscreen.y=e1->posscreen.y-10;
 }
 }
 
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /**  
* @brief tafiha matekhdemch 
* @param e1 the first ennemi  et dt variable utilise dans le calcule de vitesse  deplacement  
* @return Nothing  type void
*/  
  
 void deplacersinus(ennemi *e1,Uint32 dt){
 
 if(e1->posscreen.x>1280)
 e1->direction=1;
 if(e1->posscreen.x<700)
 e1->direction=0;
 if(e1->direction==0){
 
 SDL_Delay (50);
 e1->posscreen.x=e1->posscreen.x +5;
 e1->posscreen.y=200*sin(200*dt*0.002+1.7);
 }
 else{SDL_Delay (50);
  e1->posscreen.x=e1->posscreen.x-5;
 }
 
 
 
 
 }
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void deplacer2(ennemi *e1,Uint32 dt){
 
 if(e1->posscreen.x>1280)
 e1->direction=1;
 if(e1->posscreen.x<700)
 e1->direction=0;
 if(e1->direction==0){
 if(e1->posscreen.y<500){
 e1->posscreen.x+=2;
 e1->posscreen.y+=7;
 
 }
 SDL_Delay (50);
 e1->posscreen.x=e1->posscreen.x +5;
 //e1->posscreen.x+=200*sin(200*dt*0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000002+1.7);
 SDL_Delay(50);
 e1->posscreen.y+=200*sin(200*dt*0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000002+1.7);
 SDL_Delay(50);
 }
 else{SDL_Delay (50);
  e1->posscreen.x=e1->posscreen.x-5;
 }
 
 
 
 
 }
 
 
 
 
 

///////////////////////////////////////////                                  *******************collision bolding box********************
/**  
* @brief  lors d'une collision de perso avec l'ennemi le perso recule 350pixels
* @param rectangle perso  
*@param rectangle ennemi 
* @return entier ki va determiner la condition dans le cas de collision 
*/

  int collisionBB(SDL_Rect perso,SDL_Rect ennemi)
{
int collision;
if(((perso.x+perso.w)<ennemi.x+50) || (perso.x+50>(ennemi.x+ennemi.w)) || ((perso.y+perso.h)<ennemi.y+9) || (perso.y+5>(ennemi.y+ennemi.h)))
	collision=1;
else
	collision=0;

return collision;
}
 
  
  
  
  
  
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /**  
* @brief To initialize ennemi.  
* @param e2 the second ennemi   
* @return Nothing  type void
*/ 
 void initennemi2(ennemi *e2){
 
 e2->sprite=IMG_Load("graphic/ess2.png");
 if(e2->sprite==NULL){
 return ;
 }
 e2->possprite.x=0;
 e2->possprite.y=0;
 e2->possprite.w=640/5; // nbre de ligne 
 e2->possprite.h=128/1; //nbre de colonne  
 e2->posscreen.x=0;
 e2->posscreen.y=100;
 e2->direction=0;
 
 }
 
 
 /**  
* @brief animer l'ennemi.  
* @param e2 the second ennemi   
* @return Nothing  type void
*/  
 
 void animerennemi2(ennemi *e2){
 
e2->possprite.y=e2->direction * e2->possprite.h;
 if(e2->possprite.x== 640-128)//e->possprite.w- e->possprite.h    1280-128
 {
 e2->possprite.x=0;
 }
 else {
 //SDL_Delay(28);
 e2->possprite.x=e2->possprite.x+e2->possprite.w;
 }
 
 
 }
 
  /**  
* @brief deplacer l'ennemi.jusqu'a sortir de l'ecran  
* @param e2 the second ennemi   
* @return Nothing  type void
*/ 
 void deplace2(ennemi *e2){
 
 e2->posscreen.x=e2->posscreen.x+10;
 
 
 }
 
 
 ////////////////////////////////////////////////////////////////////////
 void initperso(perso *p){
 p->img=IMG_Load("graphic/per.png");
 if(p->img==NULL){
 return ;
 }
 p->posimg.x=0;
 p->posimg.y=0;
 p->posimg.w=400/4; // nbre de ligne 
 p->posimg.h=400/4; //nbre de colonne  
 p->posscreen.x=200;
 p->posscreen.y=380;
  p->direction=0;
 }
 
 void afficherperso(perso *p,SDL_Surface *screen){
 SDL_BlitSurface(p->img,&p->posimg,screen,&p->posscreen);
 }
 
 void liberer2(perso *a){
SDL_FreeSurface(a->img);

}
 
 void deplacerpersox(perso *p){

 
 
 
 if(p->direction==0){
 p->posscreen.x=p->posscreen.x +27;}
 else if(p->direction==1)
 {
  p->posscreen.x=p->posscreen.x-27;
 }
 else if(p->direction==2)
 {
  p->posscreen.y=p->posscreen.y-27;
 }
 else if(p->direction==3)
 {
  p->posscreen.y=p->posscreen.y+27;
 }
  p->direction=-1;
 }
 
 void animerperso(perso *p){
 
p->posimg.y=(p->sens)*(p->posimg.h);
 if(p->posimg.x==400-100 )//e->possprite.w- e->possprite.h    1280-128
 {
 p->posimg.x=0;
 }
 else {
 //SDL_Delay(28);
 p->posimg.x=p->posimg.x+p->posimg.w;
 }
 
 
 }
 
 ///////////////////////////////////////////////////////////////////
  void animerennemii(ennemi *e1,int etat){
 
e1->possprite.y=etat * e1->possprite.h;
 if(e1->possprite.x== 747-747/9)//e->possprite.w- e->possprite.h    1280-128
 {
 e1->possprite.x=0;
 }
 else {
 SDL_Delay(28);
 e1->possprite.x=e1->possprite.x+e1->possprite.w;
 }
 
 
 }
 /********************partie IA************************************/
 /**  
* @brief faire tout waiting ,following and attacking  
* @param e1 the first  ennemi  
*@param p rectangle de perso
*@param  distancex la distance entre le personnage   
*@param  le perso 
*@param  dt 
* @return Nothing  type void
*/  
void updateennemi(ennemi *e1,SDL_Rect p,float *distancex,Uint32 *dt){
if((*distancex<-470)||(*distancex>470))
e1->etat_ennemi=0;


else if((*distancex>200 && *distancex<470)  ||(*distancex<-200 && *distancex>-470))
e1->etat_ennemi=1;

 else if((*distancex<200 ) &&(*distancex>-200))   
 e1->etat_ennemi=2;
  
 
 switch (e1->etat_ennemi){
 case 0:
 deplacedt(e1,*dt);
 break;
  case 1:   
                   ////////////following
                    if(*distancex>0) {         
  e1->direction=0;
  animerennemii(e1,0);}
  else {
  e1->direction=1;
  animerennemii(e1,1);}
   deplacedt(e1,*dt);
                   
   
  break;
   
   case 2:                    ///////////attacking
   if(*distancex>0)    {           
  e1->direction=0;
  animerennemii(e1,2);}
  else {
  e1->direction=1;
  animerennemii(e1,3);}
   deplacedt(e1,*dt);
    
   
  break;
  
  
  
 }
 
 
 }
 
 void arduinoWriteData(int x)
{
    char chemin[]="/dev/ttyS1";
    FILE*f;

    f=fopen(chemin,"w");
    /*if(f == NULL)
        return(-1);*/

    fprintf(f,"%d",x);
    fclose(f);

    //return(0);
}

int arduinoReadData(int *x)
{
    char chemin[]="/dev/ttyS1";
    FILE*f;
    char c;
    f=fopen(chemin,"r");

    if(f == NULL)
        return(-1);

    fscanf(f,"%d",x);

    fclose(f);

    return(0);
}
 
 
 
 
 
 
 
 
 
 
 
 
