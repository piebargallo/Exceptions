#include <iostream>
#include <stdexcept>

double SafeDivide(double num, double den)
{
	if (den == 0)
		throw std::invalid_argument{ "Divide by zero" };
	return num / den;
}

int main()
{
	try {
		std::cout << SafeDivide(5, 2) << std::endl;
		std::cout << SafeDivide(10, 0) << std::endl;
		std::cout << SafeDivide(3, 3) << std::endl;
	}
	catch (const std::invalid_argument& e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}