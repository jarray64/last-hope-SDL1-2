#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <time.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
/**  
* @struct image  
* @brief struct for image 
*/  

struct image
{
SDL_Rect pos; /*!< Rectangle*/  
SDL_Surface * img ; /*!< surface*/  
};

typedef struct image image ;
/**  
* @struct TEXT 
* @brief struct for text  
*/  

struct TEXT
{
SDL_Rect pos;/*!< Rectangle*/  
SDL_Surface *t ;/*!< surface*/  
TTF_Font *p; /*!< font de text*/  
};
typedef struct TEXT TEXT ;
/**  
* @struct enigme_txt
* @brief struct for enigme 
*/  

struct enigme_txt
{
TEXT question,reponse1,reponse1o,reponse2,reponse2o,reponse3,reponse3o;/*!< text*/  
int resultat ;/*!< entier*/  
};
typedef struct enigme_txt enigme_txt;

void initeverything();
 void init_background(image *load);
void init_image_victoire(image *load);
void init_image_defeat(image *load);
void init_back(image *load);
void init_animation_time(image load[]);
void init_question(TEXT *txt,char ch[]);

void init_reponse(TEXT *txt,char ch[],int x,int num_reponse);

enigme_txt init_enigme();  

void afficher_img(image p,SDL_Surface *ecran);
void afficher(TEXT p,SDL_Surface *ecran);
void afficher_enigme(enigme_txt e,SDL_Surface *ecran);
void animation_time(image clock[],int i,SDL_Surface *ecran);
int enigmee(SDL_Surface *ecran) ;



