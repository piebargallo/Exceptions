/* Division-by-zero 

The try/catch
try {
	// ... code which my result in an exception beging throw
} catch (exception-type1 exception-name) {
	// ... code which responde to the exception of tipe 1
}
// ... remaining code */

#include <iostream>
#include <stdexcept>
using std::cout;
using std::invalid_argument;
using std::endl;

auto safeDivide(auto num, auto den)
{
	if (den == 0)
		throw invalid_argument{ "Divide by zero" };
	return num / den;
}

int main()
{
	try {
		cout << safeDivide(5, 2) << endl;
		cout << safeDivide(10, 0) << endl;
		cout << safeDivide(3, 3) << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Caught exception: " << e.what() << endl;
	}
}