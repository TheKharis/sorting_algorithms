#include "sort.h"

/**
 *  quick_sort - sorts an array in ascending order using the quick sort
 *		 algorithm
 *
 * @array: array of integers to sort
 * @size: number of elements in the array.
 *
 * Description: This implementation uses the Lomuto partition scheme
 *		The pivot is always the last element of the partition being
 *		sorted. The array is printed after each swap.
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_helper(array, 0, size - 1, size);
}

/**
 * quicksort_helper - recursive helper function for quick_sort
 * @array: array of integers to sort
 * @low: index of first element of the partition being sorted
 * @high: index of the last element of the partition being sorted
 * @size: number of elements in the array
 *
 * Return: void
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quicksort_helper(array, low, pi - 1, size);
		quicksort_helper(array, pi + 1, high, size);
	}
}

/**
 * partition - partitions the array around a pivot
 * @array: array of integers to sort
 * @low: index of the first element of the partition being sorted
 * @high: index of last element of the partition being sorted
 * @size: number of elements in the array
 *
 * Return: final index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap2(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap2(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap2 - swaps two integers in an array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap2(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
