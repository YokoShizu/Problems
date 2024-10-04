//	Write a program that asks the user to enter a dollars-and-cents amount, then displays the
//	amount with 5% tax added:

//	Enter an amount: 100.00
//	With tax added: $105.00

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	float amount;
	
	printf("Enter an amount: ");
	scanf("%f", &amount);
	
	printf("With tax added: $%.2f\n", amount * 1.05f);

	return 0;
}
