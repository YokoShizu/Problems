//	Create and run Kernighan and Ritchie’s famous “hello, world” program:

/*		
		#include <stdio.h>

		int main(void)
		{
			printf("hello, world\n");
		}
*/
//	Do you get a warning message from the compiler? If so, what’s needed to make it go away?

/*	ANSWER	*/

// There were no errors when running the program in the terminal, but the correct version of the program should contain the line "return 0".

#include <stdio.h>

int main(void)
{
	printf("hello, world\n");

	return 0;
}