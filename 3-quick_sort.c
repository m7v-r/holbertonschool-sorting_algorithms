#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array and prints the array.
 * @array: The array to print after swapping.
 * @size: The size of the array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_ints(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for quick_sort.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, i, j;

	pivot = array + right;
	for (i = j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			swap_ints(array, size, array + i, array + j);
			i++;
		}
	}

	swap_ints(array, size, array + i, pivot);

	return (i);
}

/**
 * lomuto_sort - Recursive implementation of the Quick Sort algorithm.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto scheme).
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
