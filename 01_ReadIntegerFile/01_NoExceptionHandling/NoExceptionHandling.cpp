#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>

std::vector<int> readIntegerFile(std::string_view filename)
{
	std::ifstream inputStream{ filename.data() };

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
	std::vector<int> myInts{ readIntegerFile(filename) };

	for (const auto& element : myInts) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
	return 0;
}
