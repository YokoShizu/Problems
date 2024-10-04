//Write a program that declares several int and float variables—without initializing
//them—and then prints their values. Is there any pattern to the values? (Usually there isn’t.)

/*	ANSWER	*/

#include <stdio.h>

int main(void) 
{
	int a, b, c, d;
	float e, f, g, h;

	printf("%d %d %d %d\n", a, b, c, d);
	printf("%f %f %f %f\n", e, f, g, h);

	return 0;
}