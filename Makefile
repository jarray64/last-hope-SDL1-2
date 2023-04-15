game:main.o game.o minimap.o  pingpong.o
	gcc *.o -o game -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g ;./game
main.o:main.c
	gcc -c main.c -g
game.o:game.c
	gcc -c game.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g

pingpong.o:pingpong.c
	gcc -c pingpong.c -g
