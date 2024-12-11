#include "sort.h"

/**
 * swap - a fonction to swap value inside the array
 *
 * @i: value that has to swap her place with j
 * @j: value that has to swap her place with i
 * @arr: pointer to the array we need to swap value
 */

void swap(int *arr, size_t i, size_t j)
{
	size_t temp = arr[i];

	arr[i] = arr[j];
	arr[j] = temp;
}

/**
 * bubble_sort - function that bubble sort an array of value calling
 * the function swap
 *
 * @array: pointer to the array of integer we need to sort
 * @size: number of byte size of the entire array
 * i is the num of elem at the end of the arr that been sorted
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}
