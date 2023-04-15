#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <math.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>


typedef struct
{
	
	double speed; 
	double velocityX,velocityY; 
	SDL_Rect ball_position; 
	SDL_Surface *ball; 

}balls;

typedef struct
{
  SDL_Surface *img; 
  SDL_Rect position; 

}surf;

typedef struct 
{
	SDL_Surface *text; 
	TTF_Font *police; 
	SDL_Rect positionscore; 
	int score; 
        char score_ch[10]; 



}score_pingpong;

int main_pingpong(int argc, char *argv[]);
void setrects_pingpong(SDL_Rect* clip);
int Bounding_Box_pingpong(SDL_Rect ball,SDL_Rect obstacl );
void initialiser(balls *B,surf *player,surf *compt,score_pingpong *scoreplayer,score_pingpong *scorecom,surf *net  );
void update_game(balls *B,score_pingpong *scoreplayer,score_pingpong *scorecom);
void Afficher_Game(SDL_Surface *screen, surf *net ,balls *B,score_pingpong *scoreplayer,score_pingpong *scorecom,surf*player,surf *compt,SDL_Rect objects[]);
void AI();

