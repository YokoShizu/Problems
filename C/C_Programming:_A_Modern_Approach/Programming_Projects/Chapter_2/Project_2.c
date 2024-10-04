//	Write a program that computes the volume of a sphere with a 10-meter radius, using the for-
//	mula v = 4/3πr3. Write the fraction 4/3 as 4.0f/3.0f. (Try writing it as 4/3. What hap-
//	pens?) Hint: C doesn’t have an exponentiation operator, so you’ll need to multiply r by itself
//	twice to compute r3.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	int r = 10;
	
	float v_incorrect = 4 / 3 * 3.141593f * r * r * r;
	float v = (4.0f / 3.0f) * 3.141593f * r * r * r;

	printf("%.1f\n", v_incorrect);
	printf("%.1f\n", v);

	return 0;
}
