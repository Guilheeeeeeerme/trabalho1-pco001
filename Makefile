all: 
	gcc -c bubble.c -o obj/bubble.o
	gcc -c heap.c -o obj/heap.o
	gcc -c insertion.c -o obj/insertion.o
	gcc -c quick.c -o obj/quick.o
	gcc -c selection.c -o obj/selection.o
	gcc -c shell.c -o obj/shell.o
	gcc -c sorter.c -o obj/sorter.o
	gcc obj/sorter.o obj/bubble.o obj/heap.o obj/insertion.o obj/quick.o obj/selection.o obj/shell.o -o sorter
	gcc -c main.c -o obj/main.o
	gcc obj/main.o -o main
