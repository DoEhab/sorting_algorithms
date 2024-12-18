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
	size_t gap = 1;
	size_t i, j;
	int temp;

	if (array == NULL)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
