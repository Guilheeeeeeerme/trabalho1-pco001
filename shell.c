#include <stdio.h>
#include <stdlib.h>

void shellSort(int *array, int size)
{
	int i, j, value;
	int gap = 1;
	while (gap < size)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 1)
	{
		gap /= 3;
		for (i = gap; i < size; i++)
		{
			value = array[i];
			j = i;
			while (j >= gap && value < array[j - gap])
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = value;
		}
	}
}