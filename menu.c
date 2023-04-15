#include "menu.h"
void initBackground(SDL_Surface *Backg,char name[]) {
 Backg= IMG_Load(name); 
 if (Backg == NULL) {
  printf("Unable to load bttmap: %s\n", SDL_GetError());
  
   return; 
} 
}

void initBouttom(SDL_Surface *newgame[],SDL_Surface *loadgame[],SDL_Surface *option[],SDL_Surface *exit[]){
newgame[0]=IMG_Load("graphic/menu/ngns.png");
    loadgame[0]=IMG_Load("graphic/menu/opns.png");
    loadgame[2]=IMG_Load("graphic/menu/opc.png");
    loadgame[1]=IMG_Load("graphic/menu/ops.png");
    option[0]=IMG_Load("graphic/menu/crns.png");
    exit[0]=IMG_Load("graphic/menu/qns.png");
    newgame[1]=IMG_Load("graphic/menu/ngs.png");
    newgame[2]=IMG_Load("graphic/menu/ngc.png");
    option[1]=IMG_Load("graphic/menu/cs.png");
    option[2]=IMG_Load("graphic/menu/cc.png");
    exit[1]=IMG_Load("graphic/menu/qs.png");
    exit[2]=IMG_Load("graphic/menu/qc.png");  
    }
void affichage(SDL_Surface *img,SDL_Surface *screen,SDL_Rect background_pos){
	    SDL_BlitSurface(img,NULL,screen,&background_pos);
		}

void liberer(SDL_Surface *img){
SDL_FreeSurface(img);}

void initText(Text *A) { 
A->position.x=70;     // initialisaation du postion de texte
 A->position.y=50; 
 // couleur jaune 
 A->textColor.r=255; 
 A->textColor.g=255; 
 A->textColor.b=0; 

A->font = TTF_OpenFont( "graphic/menu/style.otf", 100 ); }
void freeText(Text A) { 
SDL_FreeSurface(A.surfaceTexte); 
} 
void displayText(Text t,SDL_Surface *screen) {
 t.surfaceTexte = TTF_RenderText_Solid(t.font, "Last Hope", t.textColor ); 
 SDL_BlitSurface(t.surfaceTexte, NULL, screen,&t.position); 
} 
