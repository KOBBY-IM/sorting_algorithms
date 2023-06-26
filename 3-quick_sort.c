#include "sort.h"

void swap_ints(int *a, int *b);
int partition(int *array, size_t size, int start, int end);
void quickSort(int *array, size_t size, int start, int end);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Order a subset of an array of integers according to
 *          the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */

int partition(int *array, size_t size, int start, int end)
{
	int *pivot, above, below;

	pivot = array + end;
	for (above = below = start; below < end; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * quickSort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void quickSort(int *array, size_t size, int start, int end)
{
	int part;

	if (start - end > 0)
	{
		part = partition(array, size, start, end);
		quickSort(array, size, start, part - 1);
		quickSort(array, size, part + 1, end);
	}
}

/**
 * quick_sort - Quick sorts an array
 * @array: An array of integers to sort.
 * @size: The size of  array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
