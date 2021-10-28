CC = gcc
OPTIONS = -W -Wall -std=c89 -pedantic -O3
MLVG=`pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
MLVD=`pkg-config --libs-only-l MLV`


main :	main.c structure
	$(CC) $(CFLAGS) $(MLVG) -g main.c *.o $(MLVD) -o tetris

structure :	structure.c structure.h
	$(CC) $(OPTIONS) -c structure.c

clean :
	rm -f *.o *~ tetris
