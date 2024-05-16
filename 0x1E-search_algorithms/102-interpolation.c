#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 * Return: First index where value is located, or -1 if value is not found or
 * if array is NULL.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0;
	size_t high = size - 1;
	size_t pos;

	if (array == NULL)
		return (-1);

	while ((array[high] != array[low]) && (value >= array[low]) &&
		(value <= array[high]))
	{
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
			(value - array[low]));

		if (pos >= size)
	{
		printf("Value checked array[%lu] is out of range\n", pos);
		return (-1);
	}

		printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

		if (array[pos] < value)
			low = pos + 1;
		else if (array[pos] > value)
			high = pos - 1;
		else
			return (pos);
	}

	if (value == array[low])
		return (low);
	else
		return (-1);
}
