//	Write a program that asks the user for a 24-hour time, then displays the time in 12-hour
//	form:

//	Enter a 24-hour time: 21:11
//	Equivalent 12-hour time: 9:11 PM

//	Be careful not to display 12:00 as 0:00.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int hours = 0, minutes = 0;

	printf("Enter a 24-hour time: ");

	if (scanf("%2d:%2d", &hours, &minutes) != 2 || hours > 24 || hours < 0 || minutes > 60 || minutes < 0)
		printf("Inappropriate data. Please, try again\n");
	else if (hours <= 12 || (hours == 24 && (hours % 12) < 12))
		printf("Equivalent 12-hour time: %d:%02d AM\n", (hours > hours % 12 && hours != 12) ? hours % 12 : hours, minutes);
	else 
		printf("Equivalent 12-hour time: %d:%02d PM\n", hours % 12, minutes);

	return 0;
}