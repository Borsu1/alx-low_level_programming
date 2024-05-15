#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
int binary_search(int *array, size_t left, size_t right, int value);
int min(size_t a, size_t b);

/**
 * exponential_search - Searches for a value in a sorted array of integers
 *                      using the Exponential search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if the array is NULL
 *         or if the value is not present in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 1;

	if (array == NULL)
		return (-1);

	while (i < size && array[i] <= value)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		i *= 2;
	}

	printf("Value found between indexes [%lu] and [%u]\n",
		i / 2, min(i, size - 1));
	return (binary_search(array, i / 2, min(i, size - 1), value));
}

/**
 * binary_search - Searches for a value in a sorted array of integers
 *                 using the Binary search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @left: The first index of the array/subarray to search in.
 * @right: The last index of the array/subarray to search in.
 * @value: The value to search for.
 *
 * Return: The first index where value is located, or -1 if the array is NULL
 *         or if the value is not present in the array.
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		size_t mid = left + (right - left) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
			printf("%d%s", array[i], i < right ? ", " : "\n");

		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

/**
 * min - Returns the minimum of two values.
 * @a: The first value to compare.
 * @b: The second value to compare.
 *
 * Return: The minimum of a and b.
 */
int min(size_t a, size_t b)
{
	return (a < b ? a : b);
}
