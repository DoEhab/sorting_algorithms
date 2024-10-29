#include "sort.h"

size_t arr_size;
int partition(int *arr, int low, int high)
{
	int tmp, j;
	int pivot = arr[high];
	int i  = low - 1;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			print_array(arr, arr_size);
		}
	}
	tmp = arr[high];
	arr[high] = arr[i + 1];
	arr[i + 1] = tmp;
	print_array(arr, arr_size);
	return (i + 1);
}

void quick_sort_recursion(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);
		quick_sort_recursion(arr, low, pivot - 1);
		quick_sort_recursion(arr, pivot + 1, high);
	}
}
void quick_sort(int *array, size_t size)
{
	arr_size = size;
	quick_sort_recursion(array, 0, size - 1);
}
