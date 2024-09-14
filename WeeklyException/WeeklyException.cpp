// please don´t over use exceptions
// don´t "return by exception" (ie normal control flow)
// aim for "exceptional cases"
// compilers are very bad at optimizing around exceptions
// you can have many catch blocks
// ... is a catch all (possibly a code smell)
// generally speaking, catch by const &
// 'catch' bloks are handled in the order Ithey are declared
// exception catch bloks work with polymorphism to choose the most
// correct derived type of handler
// deduplicate your exception handling code

#include <stdexcept>
#include <iostream>

void function_that_throws(bool do_throw) {
	if (do_throw) {
		throw std::runtime_error("boo");
	}
}

void do_work(bool do_throw) {
	function_that_throws(do_throw);
}

// Lippincott function for centralized exception handling

void handler()
{
	try {
		throw;
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what();
	}
	catch (const std::exception& e) {
		// unknown exception derived from std::exception
		std::cout << "std::exception: " << e.what();
	}
}

int main()
{
	try {
		do_work(true);
	}
	catch (...) {
		handler();
	}
}