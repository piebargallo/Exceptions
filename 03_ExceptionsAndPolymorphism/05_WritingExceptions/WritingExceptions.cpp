#include <cstddef>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <sstream>
#include <format>

class FileError : public std::exception
{
public:
	FileError(std::string filename) : m_filename{ move(filename) } {}
	const char* what() const noexcept override { return m_message.c_str(); }
	virtual const std::string& getFilename() const noexcept { return m_filename; }

protected:
	virtual void setMessage(std::string message) { m_message = move(message); }

private:
	std::string m_filename;
	std::string m_message;
};



class FileOpenError : public FileError
{
public:
	FileOpenError(std::string filename) : FileError{ move(filename) }
	{
		setMessage(std::format("Unable to open {}.", getFilename()));
	}
};



class FileReadError : public FileError
{
public:
	FileReadError(std::string filename, size_t lineNumber)
		: FileError{ move(filename) }, m_lineNumber{ lineNumber }
	{
		setMessage(std::format("Error reading {}, line {}.", getFilename(), lineNumber));
	}

	virtual size_t getLineNumber() const noexcept { return m_lineNumber; }

private:
	size_t m_lineNumber{ 0 };
};



std::vector<int> readIntegerFiles(std::string_view filename)
{
	std::ifstream inputStream{ filename.data() };
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception.
		throw FileOpenError { filename.data() };
	}

	std::vector<int> integers;
	size_t lineNumber{ 0 };
	while (!inputStream.eof()) {
		// Read one line from the file.
		std::string line;
		getline(inputStream, line);
		++lineNumber;

		// Create a string stream out of the line.
		std::istringstream lineStream{ line };

		// Read the integers one-by-one and add them to the vector.
		int temp;
		while (lineStream >> temp) {
			integers.push_back(temp);
		}

		if (!lineStream.eof()) {
			// We did not reach the end of the string stream.
			// This means that some error occurred while reading this line.
			// Throw an exception.
			throw FileReadError { filename.data(), lineNumber };
		}
	}

	return integers;
}

int main()
{
	const std::string filename{ "IntegerFile.txt" };
	std::vector<int> myInts;

	try {
		myInts = readIntegerFiles(filename);
	}
	catch (const FileError& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	for (const auto& element : myInts) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}
