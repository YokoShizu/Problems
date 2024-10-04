//	Modify the program of Programming Project 5 so that the polynomial is evaluated using the
//	following formula:

//	((((3x + 2)x – 5)x – 1)x + 7)x – 6

//	Note that the modified program performs fewer multiplications. This technique for evaluat-
//	ing polynomials is known as Horner’s Rule.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int x;

	printf("Enter a value for x (allow only integers): ");
	scanf("%d", &x);

	int res = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;

	printf("The value of the 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 polynomial is %d\n", res);

	return 0;
}
