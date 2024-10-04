//	Write a program that asks the user to enter a two-digit number, then prints the number with
//	its digits reversed. A session with the program should have the following appearance:

//	Enter a two-digit number: 28
//	The reversal is: 82

//	Read the number using %d, then break it into two digits. Hint: If n is an integer, then n % 10
//	is the last digit in n and n / 10 is n with the last digit removed.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int num = 0;

	printf("Enter a two-digit number: ");
	scanf("%d", &num);

	if (num < 10 || num > 99)
		printf("You have entered inappropriate number. Please, try again.\n");
	else
		printf("The reversal is: %d\n", num % 10 * 10 + num / 10);

	return 0;
}
