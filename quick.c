#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int *array, int low, int high)
{
	int pivot = array[high]; // pivot
	int i = (low - 1);		 // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (array[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}
}