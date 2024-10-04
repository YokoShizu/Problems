//	Write a program that asks the user to enter a value for x and then displays the value of the
//	following polynomial:

//	3x5 + 2x4 – 5x3 – x2 + 7x – 6

//	Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply x by itself
//	repeatedly in order to compute the powers of x. (For example, x * x * x is x cubed.)

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int x;

	printf("Enter a value for x (allow only integers): ");
	scanf("%d", &x);

	int res = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
	
	printf("The value of the 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 polynomial is %d\n", res);

	return 0;
}
