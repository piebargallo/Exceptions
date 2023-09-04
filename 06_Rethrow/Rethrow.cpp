#include <iostream>
#include <stdexcept>

void g() { throw std::invalid_argument { "Some exception" }; }

void f()
{
	try {
		g();
	}
	catch (const std::exception& e) {
		std::cout << "caught in f: " << e.what() << std::endl;
		throw;  // rethrow
	}
}

int main()
{
	try {
		f();
	}
	catch (const std::invalid_argument& e) {
		std::cout << "invalid_argument caught in main: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "exception caught in main: " << e.what() << std::endl;
	}

	return 0;
}