#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	i = 0;
	while (i < size)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j + 1] < array[j])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		i = i + 1;
	}
}
