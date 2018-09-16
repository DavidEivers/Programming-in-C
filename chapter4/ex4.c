/*
 * A program to generate and print a table of the first 10 factorials
 * by Faisal Saadatmand
 */

#include <stdio.h>

int main(void)
{
	int i, j;           /* counters for main and nested loop */
	int	factorial;      /* factorial value */

	factorial = 1;
	
	for (i = 1; i <=10; ++i) {
		for (j = 1; j <= i; ++j)
			factorial = factorial * j;
		printf("%2i! = %d \n", i, factorial);
		factorial = 1;
	}

	return 0;
}