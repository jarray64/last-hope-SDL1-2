#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "map.h"
#include "alissa.h"
#include "hached.h"
#include "benali.h"
#include "game.h"
#include "enigme.h"
#include "pingpong.h"

//void sauvgarde(int position_perso ,int position_background,int position_enemy,int score,int vie,char *nom_fich);
//void chargement(int *position_perso ,int *position_background,int *position_enemy,int *score,int *vie,char *nom_fich);

/*int main()
{
    sauvgarde(0,2,3,4,5,"save.txt");

    int position_perso,position_background,position_enemy,score,vie ;

    chargement(&position_perso,&position_background,&position_enemy,&score,&vie,"save.txt");
    printf("%d %d %d %d %d \n",position_perso,position_background,position_enemy,score,vie);
    return 0;
}
*/
void savegame(int  complited,char nom_fich[])
 {
   FILE *f ;
   f=fopen(nom_fich,"w");
if (f!=NULL)
{
  fprintf(f,"%d \n",complited);
  fclose(f);
}
else
    printf ("error \n");
 }



int chargement(char nom_fich[])
 {int c=0;
   FILE *f ;
   f=fopen(nom_fich,"r");
if (f!=NULL)
{
 while( fscanf(f,"%d" ,&c)!=EOF)

  fclose(f);
}

else
    printf ("error \n");
    return c;
 }
