//	Write a program that asks the user to enter a U.S. dollar amount and then shows how to pay
//	that amount using the smallest number of $20, $10, $5, and $1 bills:

//	Enter a dollar amount: 93

//	$20 bills: 4
//	$10 bills: 1
//	$5 bills: 0
//	$1 bills: 3

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int amount;

	printf("Enter a dollar amount: ");
	scanf("%d", &amount);

	printf("\n$20 bills: %d", amount / 20);
	amount = amount - amount / 20 * 20;

	printf("\n$10 bills: %d", amount / 10);
	amount = amount - amount / 10 * 10;

	printf("\n $5 bills: %d", amount / 5);
	amount = amount - amount / 5 * 5;

	printf("\n $1 bills: %d\n", amount);

	return 0;
}
