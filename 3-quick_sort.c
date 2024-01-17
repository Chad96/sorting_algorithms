#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order using Quick sort
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
* quick_sort_recursive - Recursive helper function for Quick sort
* @array: Array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick sort
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Size of the array
* Return: Partition index
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}
