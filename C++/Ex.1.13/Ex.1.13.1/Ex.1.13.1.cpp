#include <iostream>

int main() 
{
	int sum = 0;
	for (int num = 50; num <= 100; ++num)
		sum += num;
	std::cout << "The sum from 50 to 100 inclusive is " << sum << std::endl;
	return 0;
}
