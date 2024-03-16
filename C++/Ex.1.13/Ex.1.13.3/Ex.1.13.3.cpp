#include <iostream>

int main()
{
	int num1, num2;
	std::cout << "Enter two numbers: ";
	std::cin >> num1 >> num2;
	if (num1 < num2) {
		for (int i = num1; i <= num2; i++)
			std::cout << i << std::endl;
	}
	else {
		for (int i = num1; i >= num2; i--)
			std::cout << i << std::endl;
	}
	return 0;
}
