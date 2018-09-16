/* 
 * Program that copies one file to another, replacing all 
 * lowercase characters with their uppercase equivalents. 
 * By Faisal Saadatmand
 */

#include <stdio.h>
#include <ctype.h>

int main(void) 
{
	char inName[64], outName[64];
	FILE *in, *out;
	int  c;

	/* Get file name from user */
	printf("Enter name of the file to be copied: ");
	scanf("%64s", inName);

	printf("Enter name of the output file: ");
	scanf("%64s", outName);

	/* Open input and output files */
	in = fopen(inName, "r");
	if (in == NULL) {
		printf("Can't open %s for reading.\n", inName);
		return 1;
	}

	out = fopen(outName, "w");
	if (out == NULL) {
		printf("Can't open %s for writing.\n", outName);
		return 2;
	}

	/* Copy in to out */
	while ((c = getc(in)) != EOF) {
		if (islower(c))
			c = toupper(c);        /* Convert to uppercase */
		putc(c, out);
	}

	/* close open files */
	fclose(in);
	fclose(out);

	return 0;
}