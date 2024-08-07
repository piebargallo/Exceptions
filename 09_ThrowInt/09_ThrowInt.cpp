/* The most likely problem to occur is for the file open to fail. */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <exception>
#include <format>

using namespace std;

vector<int> readIntegerFile(string_view filename)
{
	ifstream inputStream{ filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw 5;
	}

	// Read the integers one-by-one and add them to a vector.
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

int main()
{
	const string filename{ "IntegerFile.txt" };
	vector<int> myInts;

	try {
		myInts = readIntegerFile(filename);
	}
	catch (int e) {
		cerr << format("Unable to open file {} (Error Code {})", filename, e) << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;
}
