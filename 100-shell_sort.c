#include "sort.h"

/**
  * shell_sort - Entry point
  *
  * @array: unsorted array
  * @size: size of array to be sorted
  * Return: void
  */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}