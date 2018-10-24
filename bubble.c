#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *array, int size)
{

	int trocou = 1;

	while (trocou == 1)
	{
		trocou = 0;

		for (int i = 0; i < (size - 1); i++)
		{
			if (array[i + 1] < array[i])
			{
				trocou = 1;
				int aux = array[i + 1];
				array[i + 1] = array[i];
				array[i] = aux;
			}
		}
	}
}