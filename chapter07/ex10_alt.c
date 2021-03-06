/* 
 * 10. Write a function prime() that returns 1 if its argument is a prime
 * number and returns 0 otherwise.
 *
 * NOTE: this version uses Sieve of Eratosthenes algorithm.
 *
 * The use of global variables is not ideal, for it should be avoided whenever
 * possible. However, in this case, it allows for some optimization, i.e. we
 * could use the same sieve across multiple calls to the function prime and
 * generating a new one only when necessary.
 *
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* globals */
unsigned *p; /* prime sieve pointer (array) */
size_t pSize = 1000000;

/* functions */
unsigned *generatePrimeSieve(const size_t);
bool prime(const size_t);

unsigned *generatePrimeSieve(const size_t n)
{
	unsigned *p;
	size_t i, j;

	if (!(p = calloc(sizeof(long unsigned), n + 1))) {
		fprintf(stderr, "unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	for (i = 2; i < n; ++i)
		if (!p[i])
			for (j = i * i; j <= n ; j += i)
				p[j] = 1;

	return p;
}

bool prime(const size_t n) 
{
	/* Optimization: start with a sieve of size pSize and only generate a new
	 * sieve with a larger size if n is larger than pSize */
	if (n > pSize) {
		free(p);
		p = NULL;
		pSize = n;
	}
	if (!p)
		p = generatePrimeSieve(pSize);

	if (n < 2 || p[n])
		return false;
	
	return true;
}

int main(void)
{
	int number, input;

	while (true) {
		printf("Enter a number to check for primality: ");
		if (!(input = scanf("%i", &number)) || input == EOF)
			break;
		printf(" %i %s a prime number.\n", number,
				(prime(number)) ? "is" : "is NOT");
	}

	/* clean up */
	free(p);
	p = NULL;

	return 0;
}
