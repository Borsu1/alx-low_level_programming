#include <stdio.h>

/**
 * linear_search - Searches for a value in an array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Description: This function searches for a value in an array
 * using the Linear search algorithm. It returns the first index
 * where the value is located. If the value is not present in the
 * array or if the array is NULL, the function returns -1.
 *
 * Return: The first index where value is located, or -1
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
