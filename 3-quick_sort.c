#include "sort.h"

void swap(int *a, int *b);

/**
 * partition - choose a pivot and move all smaller elements
 * to the left side of the pivot
 *
 * @low: begining of the array
 * @high: end of the array
 * @size: size in byte of the array
 * @array: pointer to the mem adress of the array
 *
 * Return: final position of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int j, pivot = array[high], i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);

	if (array[i + 1] != array[high])
		print_array(array, size);

	return (i + 1);
}

/**
 * swap - swap a with b using a tmp variable
 *
 * @a: first value to swap
 * @b: second value to swap
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quicksort - sort array using quicksort algorithm
 *
 * @array: pointer to mem adress to the array
 * @low: begining of the array
 * @high: end of the array
 * @size: size in bytes of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pidx;

	if (low < high)
	{
		pidx = partition(array, low, high, size);
		quicksort(array, low, pidx - 1, size);
		quicksort(array, pidx + 1, high, size);
	}
}

/**
 * quick_sort - function that check if there's and array of a size > 2
 *
 * @array: pointer to mem adress of the array
 * @size: size in bytes of the array
 *
 * Return: the function quiksort if condition is meet
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
