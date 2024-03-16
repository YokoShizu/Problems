#include <iostream>

int main()
{
	int num1, num2;
	std::cout << "Enter two numbers: ";
	std::cin >> num1 >> num2;
	if (num1 > num2) {
		while (num1 >= num2) {
			std::cout << num1 << std::endl;
			num1 -= 1;
		}
	}
	else {
		while (num1 <= num2) {
			std::cout << num1 << std::endl;
			num1 += 1;
		}
	}
	return 0;
}