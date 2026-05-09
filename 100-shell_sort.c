#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth sequence (n = n * 3 + 1).
 * Prints the array each time the interval is decreased.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate initial Knuth interval: 1, 4, 13, 40... */
	gap = 1;
	while (gap < (size / 3))
		gap = gap * 3 + 1;

	/* Start sorting with decreasing gaps */
	for (; gap >= 1; gap /= 3)
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
		/* Print the array after each gap decrease */
		print_array(array, size);
	}
}
