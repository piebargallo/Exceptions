#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <exception>

using namespace std;

vector<int> readIntegerFile(string_view filename)
{
	ifstream inputStream{ filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw "Unable to open file";
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
	catch (const char* e) {
		cerr << e << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;
}
