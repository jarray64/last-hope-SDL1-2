p:main.o game.o perso.o background.o 
	gcc main.o game.o perso.o background.o  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer  -o p -g 
main.o:main.c
	gcc -c main.c -g
game.o:game.c
	gcc -c game.c -g
background.o:background.c
	gcc -c background.c -g
perso.o:perso.c
	gcc -c perso.c -g
