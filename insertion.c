#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *array, int size)
{

	for (int i = 1; i < size; i++)
	{
		int escolhido = array[i];
		int j = i - 1;

		while ((j >= 0) && (array[j] > escolhido))
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = escolhido;
	}

}