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
	FILE *fp = fopen(fileName, "r");
	int size = 0;
	int num;

	while (fscanf(fp, "%d", &num) != EOF)
	{
		size++;
	}

	fclose(fp);

	return size;
}

int main(int argc, char **argv)
{
	FILE *fp;
	int num;
	int size = 0;
	int *array;

	if (argc >= 3)
	{

		size = sizeOf(argv[1]);
		fp = fopen(argv[1], "r");

		if (fp == NULL)
		{
			printf("usage %s <filename> [bubble | heap | insertion | quick | selection | shell]", argv[0]);
			exit(0);
		}
	}
	else
	{

		// fp = fopen("input.in", "r");

		// if (fp == NULL)
		// {
		printf("usage %s <filename> [bubble | heap | insertion | quick | selection | shell]", argv[0]);
		exit(0);
		// }
	}

	printf("\nMethod: %s\n", argv[2]);
	printf("Dataset: %s\n", argv[1]);
	printf("Dataset Size: %d\n", size);

	// printf("%s, %d\n", argv[2], strcmp(argv[2], "shell"));
	// printf("%s, %d\n", argv[2], strcmp(argv[2], "heap"));
	// printf("%s, %d\n", argv[2], strcmp(argv[2], "insertion"));
	// printf("%s, %d\n", argv[2], strcmp(argv[2], "quick"));
	// printf("%s, %d\n", argv[2], strcmp(argv[2], "selection"));
	// printf("%s, %d\n", argv[2], strcmp(argv[2], "bubble"));

	array = (int *)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		fscanf(fp, "%d", &num);
		array[i] = num;
	}

	fclose(fp);

	// Calculate the time taken by fun()
	clock_t t;
	t = clock();

	if (strcmp(argv[2], "shell") == 0)
		shellSort(array, size);
	else if (strcmp(argv[2], "heap") == 0)
		heapSort(array, size);
	else if (strcmp(argv[2], "insertion") == 0)
		insertionSort(array, size);
	else if (strcmp(argv[2], "quick") == 0)
		quickSort(array, 0, size - 1);
	else if (strcmp(argv[2], "selection") == 0)
		selectionSort(array, size);
	else
		bubbleSort(array, size);

	t = clock() - t;
	double total_t = ((double)t) / CLOCKS_PER_SEC; // in seconds

	printf("Total time taken by CPU: %f\n", total_t);
	// printf("Output: \n[");

	int isOrdered = 1;

	for (int i = 0; i < (size - 1); i++)
	{
		// printf("%d, ", array[i]);

		if (array[i] > array[i + 1])
		{
			isOrdered = 0;
		}
	}

	// printf("%d]\n", array[size - 1]);

	if (isOrdered == 1)
	{
		printf("status: OK\n");
	}
	else
	{
		printf("status: NOT OK\n");
	}

	return 0;
}