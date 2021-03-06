/* 
 * 4. Define a macro MAX3 that gives the maximum of three values. Write a
 * program to test the definition.
 * By Faisal Saadatmand
 */

#include <stdio.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))  
#define MAX3(a,b,c) ((MAX(a,b) > (c)) ? (MAX(a,b)) : (c))

int main(void) 
{
	int x = 5, y = 7, z = 20;

	printf("Maximum value for %i, %i, %i is %i\n", x, y, z, MAX3(x, y, z));

	return 0;
}
