all:
	gcc -c bubble.c
	gcc -c heap.c
	gcc -c insertion.c
	gcc -c quick.c
	gcc -c selection.c
	gcc -c shell.c
	gcc -c main.c
	gcc main.o bubble.o heap.o insertion.o quick.o selection.o shell.o -o main
test: all
	cls
	main input\input.50m.in insertion 
	main input\input.50m.in selection 
	main input\input.50m.in bubble 
	main input\input.50m.in shell 
	main input\input.50m.in heap 
	main input\input.50m.in quick 

	main input\input.100m.in insertion 
	main input\input.100m.in selection 
	main input\input.100m.in bubble 
	main input\input.100m.in shell 
	main input\input.100m.in heap 
	main input\input.100m.in quick 

	main input\input.200m.in insertion 
	main input\input.200m.in selection 
	main input\input.200m.in bubble 
	main input\input.200m.in shell 
	main input\input.200m.in heap 
	main input\input.200m.in quick 