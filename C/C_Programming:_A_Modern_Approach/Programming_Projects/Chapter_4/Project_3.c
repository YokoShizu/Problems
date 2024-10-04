//	Rewrite the program in Programming Project 2 so that it prints the reversal of a three-digit
//	number without using arithmetic to split the number into digits. Hint: See the upc.c pro-
//	gram of Section 4.1.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	char first, second, third, fourth;

	printf("Enter a two-digit number: ");
	scanf("%c%c%c", &first, &second, &third);
	
	if (third != '\n') {
		scanf("%c", &fourth);
		
		if (first < 49 || first > 57 || second > 57 || second < 48 || third < 48 || third > 57 || fourth != '\n')
			printf("You have entered inappropriate data. Please, try again.\n");
		else
			printf("The reversal is: %c%c%c\n", third, second, first);
	}
	else
		printf("You have entered inappropriate data. Please, try again.\n");
	return 0;
}
