CC = gcc
OPTIONS = -W -Wall -std=c89 -pedantic -O3
MLVG=`pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
MLVD=`pkg-config --libs-only-l MLV`


main :	main.c structure display
	$(CC) $(OPTIONS) $(MLVG) -g main.c *.o $(MLVD) -o tetris

structure :	structure.c structure.h
	$(CC) $(OPTIONS) -c structure.c

display : display.c display.h
	$(CC) $(OPTIONS) $(MLVG) -c display.c $(MLVD) 

clean :
	rm -f *.o *~ tetris
