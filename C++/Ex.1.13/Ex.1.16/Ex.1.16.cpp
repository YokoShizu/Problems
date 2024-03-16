#include <iostream>

int main()
{
	std::cout << "Enter your numbers! Don't be afraid! Just write it down!" << std::endl;
	int sum = 0, num;
	while (std::cin >> num)
		sum += num;
	std::cout << "Well done! So enjoy your own job, the sum of your numbers is: " << sum << std::endl;
	return 0;
}
