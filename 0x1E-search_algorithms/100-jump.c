#include <stdio.h>
#include <math.h>

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in array.
 * @value: Value to search for.
 *
 * Return: First index where value is located, or -1 if value is not present
 *         in array or if array is NULL.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev;

	if (array == NULL)
		return (-1);

	step = sqrt(size);
	prev = 0;

	/* Jump ahead in blocks of size sqrt(size) */
	while (array[step < size ? step : size] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", step, array[step]);
		prev = step;
		step += sqrt(size);
		if (prev >= size)
			return (-1);
	}

	/* Perform linear search in the block */
	while (array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev++;
		if (prev == step + 1)
			return (-1);
	}

	/* Check if value is found */
	if (array[prev] == value)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			   prev - (size_t)sqrt(size), prev);
		return ((int) prev);
	}

	return (-1);
}
