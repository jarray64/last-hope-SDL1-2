#ifndef FONCTION_H_INCLUDED
#define FONCTION_H_INCLUDED
/**
  *@file fonction.h
  */
#include <stdio.h>
 #include<stdlib.h>
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
  #include<math.h>
 /**  
* @struct ennemi 
* @brief struct for ennemi 
*/  

typedef struct ennemi{
/**!<surface*/ 
SDL_Surface *sprite;  
  /** !<entier de deplacement et de direction*/                      
int  direction;    
/**  !<rectangle  sur l'ecran  */                   
SDL_Rect posscreen;  
/**  !<rectangle parti de sprite   */                
SDL_Rect possprite;   
 /**  !<vitesse de deplacement        */                   
double vitesse;   
/**  !<entier,1=following ,2=attacking  ,initialement waiting */        
int etat_ennemi;                     
}ennemi;
/**  
* @struct perso  
* @brief struct for personnage  
*/  

typedef struct {
/**!<surface*/ 
SDL_Surface *img; 
/**  !<rectangle  sur l'ecran  */ 
SDL_Rect posscreen;
/**  !<rectangle parti de sprite   */ 
SDL_Rect posimg;
 /**  !<entier deplacement  */  
int  direction;
/** !< entier   d'annimation*/ 
int sens;           
}perso ;
typedef struct ennemi ennemi;
 

void initennemi1(ennemi *e1);
  void initennemii1(ennemi *e1);

void initennemi2(ennemi *e2);

void afficherennemi1(ennemi *e1,SDL_Surface *screen);

void libereres(ennemi *a);

void animerennemi1(ennemi *e1);

 void animerennemi2(ennemi *e2);
 
 void deplace2(ennemi *e2);
//***********************deplacement

 void deplacerx(ennemi *e1);
 
 void deplacery(ennemi *e1);
 
 void deplacerdrouj(ennemi *e1,int *test);
 
  
 void  deplacersinus(ennemi *e1,Uint32 dt);
 
 void deplacedt(ennemi *e1,Uint32 dt);
   
 int collisionBB(SDL_Rect perso,SDL_Rect ennemi);
//****************************************
 void initperso(perso *p);
 void afficherperso(perso *p,SDL_Surface *screen);
 void liberer2(perso *a);
  void deplacerpersox(perso *p);
  void animerperso(perso *p);
 //****************************************************************
 /********************partie IA************************************/
 
 void updateennemi(ennemi *e1,SDL_Rect p,float *distancex,Uint32 *dt);
 /**  
* @brief animer l'ennemi.avec petite mise a jour de l'ancien annimer  
* @param e1 the first ennemi  ,etat determiner la ligne de l'annimation correspondante 
* @return Nothing  type void
*/  
 void arduinoWriteData(int x);
 int arduinoReadData(int *x);
 void animerennemii(ennemi *e1,int etat);
#endif // MENU_H_INCLUDED
