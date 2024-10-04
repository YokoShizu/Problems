//	Modify the program of Programming Project 2 so that it prompts the user to enter the radius
//	of the sphere.

/*	ANSWER	*/

#include <stdio.h>

int main(void)
{
	float r;
	
	printf("Enter the radius of the sphere: ");
	
	if (scanf("%f", &r) == 1) {
		float v = (4.0f / 3.0f) * 3.141593f * r * r * r;
		printf("%.1f\n", v);
	}
	
	return 0;
}
