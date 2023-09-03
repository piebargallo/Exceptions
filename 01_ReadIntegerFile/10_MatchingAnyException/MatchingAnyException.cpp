#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>

std::vector<int> readIntegerFile(std::string_view filename)
{
	std::ifstream inputStream{ filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw std::invalid_argument{ "Unable to open the file." };
	}

	// Read the integers one-by-one and add them to a vector.
	std::vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// We did not reach the end-of-file.
		// This means that some error occurred while reading the file.
		// Throw an exception.
		throw std::runtime_error{ "Error reading the file." };
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
	catch (...) {
		std::cerr << "Error reading or opening file " << filename << std::endl;
		return 1;
	}

	for (const auto& element : myInts) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	return 0;
}