#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *array, int size)
{

	int i, j, min, aux;
	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (array[i] != array[min])
		{
			aux = array[i];
			array[i] = array[min];
			array[min] = aux;
		}
	}
}