#include <iostream>
#include <exception>
#include <stdexcept>
#include <format>

class SubObject
{
public:
	SubObject(int i)
	{
		throw std::runtime_error{ "Exception by SubObject ctor" };
	}
};

class MyClass
{
public:
	MyClass();
private:
	int* m_data{ nullptr };
	SubObject m_subObject;
};

MyClass::MyClass()
try
	: m_data{ new int[42] { 1, 2, 3 } }, m_subObject{ 42 }
{
	/* ... constructor body ... */
}
catch (const std::exception& e)
{
	// Cleanup memory.
	delete[] m_data;
	m_data = nullptr;
	std::cout << std::format("function-try-block caught: '{}'", e.what()) << std::endl;
}

int main()
{
	try {
		MyClass m;
	}
	catch (const std::exception& e) {
		std::cout << std::format("main() caught: '{}'", e.what()) << std::endl;
	}
	return 0;
}
