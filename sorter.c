#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bubble.h"
#include "heap.h"
#include "insertion.h"
#include "quick.h"
#include "selection.h"
#include "shell.h"

int sizeOf(char *fileName)
{
	FILE *input_file = fopen(fileName, "r");
	int size = 0;
	int num;

	while (fscanf(input_file, "%d", &num) != EOF)
	{
		size++;
	}

	fclose(input_file);

	return size;
}

int main(int argc, char **argv)
{
	FILE *input_file;
	FILE *output_file;
	int num;
	int size = 0;
	int *array;

	if (argc >= 4)
	{

		size = sizeOf(argv[1]);
		input_file = fopen(argv[1], "r");
		output_file = fopen(argv[2], "w");

		if (input_file == NULL || output_file == NULL)
		{
			printf("usage %s <input filename> <output filename> [bubble | heap | insertion | quick | selection | shell]", argv[0]);
			exit(0);
		}
	}
	else
	{
		printf("usage %s <input filename> <output filename> [bubble | heap | insertion | quick | selection | shell]", argv[0]);
		exit(0);
	}

	array = (int *)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		fscanf(input_file, "%d", &num);
		array[i] = num;
	}

	fclose(input_file);

	// Calculate the time taken by fun()
	clock_t t;
	t = clock();

	if (strcmp(argv[3], "shell") == 0)
		shellSort(array, size);
	else if (strcmp(argv[3], "heap") == 0)
		heapSort(array, size);
	else if (strcmp(argv[3], "insertion") == 0)
		insertionSort(array, size);
	else if (strcmp(argv[3], "quick") == 0)
		quickSort(array, 0, size - 1);
	else if (strcmp(argv[3], "selection") == 0)
		selectionSort(array, size);
	else
		bubbleSort(array, size);

	t = clock() - t;
	double total_t = ((double)t) / CLOCKS_PER_SEC; // in seconds

	printf("%f", total_t);

	for (int i = 0; i < size; i++)
	{
		fprintf(output_file, "%d\n", array[i]);
	}

	fclose(output_file);

	return 0;
}