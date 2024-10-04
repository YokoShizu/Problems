// Extend the program in Programming Project 1 to handle three-digit numbers.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int num = 0;

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	if (num < 100 || num > 999)
		printf("You have entered inappropriate number. Please, try again.\n");
	else
		printf("The reversal is: %d\n", num % 10 * 100 + num % 100 / 10 * 10 + num / 100);

	return 0;
}
