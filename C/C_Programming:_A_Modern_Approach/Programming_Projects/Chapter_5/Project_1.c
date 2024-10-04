//	Write a program that calculates how many digits a number contains:

//	Enter a number: 374
//	The number 374 has 3 digits

//	You may assume that the number has no more than four digits. Hint: Use if statements to
//	test the number. For example, if the number is between 0 and 9, it has one digit. If the num-
//	ber is between 10 and 99, it has two digits.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int value = 0, digits_num = 1, sign = 1;

	printf("Enter a number: ");
	scanf("%d", &value);

	if (value < 0)
		sign = -1;

	if(sign * value > 9)
		++digits_num;
	if(sign * value > 99)
		++digits_num;
	if(sign * value > 999)
		++digits_num;
	if(sign * value > 9999)
		++digits_num;

	if(digits_num > 0 && digits_num <= 4)
		printf("The number %d has %d digits\n", value, digits_num);
	else
		printf("The number %d has more than 4 digits\n", value);
	
	return 0;
}