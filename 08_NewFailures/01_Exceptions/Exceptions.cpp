#include <cstddef>
#include <iostream>
#include <limits>
#include <format>
#include <source_location>

int main()
{
	int* ptr{ nullptr };
	size_t integerCount{ std::numeric_limits<size_t>::max() };
	std::cout << std::format("Trying to allocate memory for {} integers.", integerCount) << std::endl;

	try {
		ptr = new int[integerCount];
	}
	catch (const std::bad_alloc& e) {
		auto location{ std::source_location::current() };
		std::cerr << std::format("{}({}): Unable to allocate memory: {}",
			location.file_name(), location.line(), e.what()) << std::endl;
		// Handle memory allocation failure.
		return 1;
	}
	// Proceed with function that assumes memory has been allocated.
}
