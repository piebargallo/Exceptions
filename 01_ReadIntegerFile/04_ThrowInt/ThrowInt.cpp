#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <exception>
#include <format>

std::vector<int> readIntegerFile(std::string_view filename)
{
	std::ifstream inputStream{ filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw 5;
	}

	// Read the integers one-by-one and add them to a vector.
	std::vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}
	return integers;
}

int main()
{
	const std::string filename{ "IntegerFile.txt" };
	std::vector<int> myInts;

	try {
		myInts = readIntegerFile(filename);
	}
	catch (int e) {
		std::cerr << format("Unable to open file {} (Error Code {})", filename, e) << std::endl;
		return 1;
	}

	for (const auto& element : myInts) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	return 0;
}