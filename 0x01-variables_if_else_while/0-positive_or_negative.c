#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Determines if a number is positive, negative or zero.
 * Return: Always 0 (success)
 */

int main(void)

{
	int n;

	srand(0);
	n = rand() - RAND_MAX / 2;
	if (n > 0)
	{
		printf("%d is positive\n");
	}
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	else
	{
		printf("%d is negative\n");
	}
	return (0);
}

