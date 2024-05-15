#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: The array to be printed
 * @left: The first index of the array to be printed
 * @right: The last index of the array to be printed
 */
void print_array(int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i < right; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[i]);
}

/**
 * binary_search_rec - Recursive function that performs the binary search
 * @array: The array to be searched
 * @left: The first index of the array to be searched
 * @right: The last index of the array to be searched
 * @value: The value to be searched
 * Return: The first occurrence of the value in the array or -1 if not found
 */
int binary_search_rec(int *array, size_t left, size_t right, int value)
{
	if (right >= left)
	{
		size_t mid = left + (right - left) / 2;

		print_array(array, left, right);

		if (array[mid] == value)
		{
			if (mid == 0 || array[mid - 1] < value)
				return (mid);
			else
				return (binary_search_rec(array, left, mid, value));
		}

		if (array[mid] > value)
			return (binary_search_rec(array, left, mid, value));

		return (binary_search_rec(array, mid + 1, right, value));
	}

	return (-1);
}

/**
 * advanced_binary - Entry point for the binary search
 * @array: The array to be searched
 * @size: The size of the array
 * @value: The value to be searched
 * Return: The first occurrence of the value in the array or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary_search_rec(array, 0, size - 1, value));
}
