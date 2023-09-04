#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <format>

class MyException : public std::exception
{
public:
	MyException(std::string message) : m_message{ move(message) } {}
	const char* what() const noexcept override { return m_message.c_str(); }

private:
	std::string m_message;
};


void doSomething()
{
	try {
		throw std::runtime_error{ "Throwing a runtime_error exception" };
	}
	catch (const std::runtime_error& /*e*/) {
		std::cout << std::format("{} caught a runtime_error", __func__) << std::endl;
		std::cout << std::format("{} throwing MyException", __func__) << std::endl;
		throw_with_nested(MyException{ "MyException with nested runtime_error" });
	}
}

int main()
{
	try {
		doSomething();
	}
	catch (const MyException& e) {
		std::cout << std::format("{} caught MyException: {}", __func__, e.what()) << std::endl;
		/*
				const auto* nested{ dynamic_cast<const nested_exception*>(&e) };
				if (nested) {
					try {
						nested->rethrow_nested();
					} catch (const runtime_error& e) {
						// Handle nested exception.
						cout << format("  Nested exception: {}", e.what()) << endl;
					}
				}
		*/
		try {
			rethrow_if_nested(e);
		}
		catch (const std::runtime_error& e) {
			// Handle nested exception.
			std::cout << std::format("  Nested exception: {}", e.what()) << std::endl;
		}
	}
	return 0;
}
