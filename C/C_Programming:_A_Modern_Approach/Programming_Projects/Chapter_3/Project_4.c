//	Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-
//	xxxx and then displays the number in the form xxx.xxx.xxx:

//	Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
//	You entered 404.817.6900

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int first = 0, second = 0, third = 0;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");
	scanf("(%d) %d-%d", &first, &second, &third);

	printf("You entered %d.%d.%d\n", first, second, third);

	return 0;
}
