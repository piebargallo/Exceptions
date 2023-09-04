#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <format>

std::vector<int> readIntegerFile(std::string_view filename)
{
	std::ifstream inputStream{ filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		const std::string error{ std::format("Unable to open file {}.", filename.data()) };
		throw std::invalid_argument{ error };
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
		const std::string error{ std::format("Unable to read file {}.", filename.data()) };
		throw std::runtime_error{ error };
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
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
		return 2;
	}

	for (const auto& element : myInts) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}
