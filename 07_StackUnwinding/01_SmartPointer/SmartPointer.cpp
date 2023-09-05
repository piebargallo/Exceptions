#include <fstream>
#include <iostream>
#include <stdexcept>
#include <memory>

void funcOne();
void funcTwo();

int main()
{
	try {
		funcOne();
	}
	catch (const std::exception& /* e */) {
		std::cerr << "Exception caught!" << std::endl;
		return 1;
	}
}

void funcOne()
{
	std::string str1;
	auto str2{ std::make_unique<std::string>("hello") };
	funcTwo();
}

void funcTwo()
{
	std::ifstream fileStream;
	fileStream.open("filename");
	throw std::exception {};
	fileStream.close();
}
