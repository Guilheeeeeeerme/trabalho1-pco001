#include <stdio.h>
#include <stdlib.h>

void heapSort(int *array, int size)
{
	int i = size / 2, pai, filho, t;

	while (1)
	{
		if (i > 0)
		{
			i--;
			t = array[i];
		}
		else
		{
			size--;
			if (size == 0)
				return;
			t = array[size];
			array[size] = array[0];
		}
		pai = i;
		filho = i * 2 + 1;
		while (filho < size)
		{
			if ((filho + 1 < size) && (array[filho + 1] > array[filho]))
				filho++;
			if (array[filho] > t)
			{
				array[pai] = array[filho];
				pai = filho;
				filho = pai * 2 + 1;
			}
			else
			{
				break;
			}
		}
		array[pai] = t;
	}
}