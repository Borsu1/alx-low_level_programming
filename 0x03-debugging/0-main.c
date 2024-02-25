#include "main.h"
/**
* main - Test function for positive or negative
* Return: 0
*/
int main(void)
{
    int i;

    i = 0;
    positive_or_negative(i);

    return (0);
}

/**
* positive_or_negative - checks if a number is positive, negative or zero
* @i: the number to check
* Return: void
*/
void positive_or_negative(int i)
{
    if (i > 0)
        printf("%d is positive\n", i);
    else if (i < 0)
        printf("%d is negative\n", i);
    else
        printf("%d is zero\n", i);
}
