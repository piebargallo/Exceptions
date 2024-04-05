/* Without compiling and executing, find and the correct the errors in the fowolling code. */

#include <vector>
#include <stdexcept>
#include <iostream>
using std::vector;
using std::cerr;
using std::endl;

// Throws a logic error exception if the number of elements
// in the given database is not even.
void verifyDataSize(const vector<int>& data)
{
	if (data.size() % 2 != 0)
		throw std::logic_error { "Number of data points must be even." };
}

// Throws a logic_error exception if the number of elements
// in the given dataset is not even.
// Throws a domain_error exception if one of the data points is negative
void processData(const vector<int>& data)
{
	// Verify the size of the given dataset.
	try {
		verifyDataSize(data);
	}
	catch (const std::logic_error& caughtException) {
		// Write message on standard error output
		cerr << "Invalid number of data points in dataset. Aborting." << endl;
		// And rethrow the exception.
		throw caughtException;
	}
	// Process data...
}

int main()
{
	try {
		vector data{ 1, 2, 3, -5, 6, 9 };
		processData(data);
	}
	catch (const std::logic_error& caughtException) {
		cerr << "logic_error: " << caughtException.what() << endl;
	}
	catch (const std::domain_error& caughtException) {
		cerr << "domain_erroe: " << caughtException.what() << endl;
	}
}