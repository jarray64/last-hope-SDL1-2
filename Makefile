p:main.o menu.o option.o map.o player.o alissa.o perso.o hached.o benali.o colli.o fonction.o
	gcc main.o menu.o option.o map.o player.o alissa.o perso.o hached.o benali.o colli.o fonction.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -lm
main.o:main.c
	gcc -c main.c -g
menu.o:menu.c 
	gcc -c menu.c -g
option.o:option.c 
	gcc -c option.c -g
player.o:player.c 
	gcc -c player.c -g
perso.o:perso.c 
	gcc -c perso.c -g
colli.o:colli.c 
	gcc -c colli.c -g
map.o:map.c 
	gcc -c map.c -g
alissa.o:alissa.c 
	gcc -c alissa.c -g
hached.o:hached.c 
	gcc -c hached.c -g
benali.o:benali.c 
	gcc -c benali.c -g
fonction.o:fonction.c 
	gcc -c fonction.c -g
