/* Take a look at the code in Chapter 9 for the spreadsheet example that includes support for move semantics using
   swap(). You can find the entire code in the downloadable source code archive in the folder 
   c09_code\07_SpreadsheetMoveSemanticsWithSwap. Add proper error handling to the code, including handling of memory
   allocation failures. Add a maximum width and height to the class and include the proper verification checks. Write
   your own exception class, InvalidCoordinate, wich stores both an invalid coordinate and the range of allowed 
   coordinates. Use it in the verifyCoordinate() method. Write a couple of tests in main() to test various error
   conditions. */

import <iostream>;
import spreadsheet;
import invalid_coordinate;

using namespace std;

int main()
{
	try {
		Spreadsheet s{ 100, 256 };
	}
	catch (const exception& caughtException) {
		cerr << caughtException.what() << endl;
	}

	try {
		Spreadsheet s{ 49, 49 };
		auto& cell = s.getCellAt(55, 55);
	}
	catch (const exception& caughtException) {
		cerr << caughtException.what() << endl;
	}

	try {
		Spreadsheet s{ 49, 49 };
		s.setCellAt(55, 55, SpreadsheetCell{ 1.2 });
	}
	catch (const exception& caughtException) {
		cerr << caughtException.what() << endl;
	}
}


