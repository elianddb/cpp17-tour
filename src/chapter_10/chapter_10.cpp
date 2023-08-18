#include <iostream>

int main()
{
	std::cout << "Chapter 10\n";

	// 10.2 Output
	// In <ostream>, the I/O stream library defines output for every built-in
	// type.
	//
	// The operator << ("put to") is used as an output operator on obj
	// of type ostream; cout is the standard output stream and cerr is the
	// standard for reporting errors. By default, values written to cout are
	// converted to a sequence of characters.
	//
	// Places the characters 1 and 0 on the standard output stream.
	//		std::cout << 10;
	// The same can be done equivalently through a variable.
	// 
	// When outputting several items you could do it in separate lines. But most
	// prefer to chain the items using <<
	//		std::cout << "the value is " << 10 << '\n';
	//
	// A character constant is a character enclosed in single quotes.
	// Note: char is ouputted as a character rather than a numerical value.
	//		char c = 'c';
	// 10.2 Output

	// 10.3 Input
	// In <istream>, the std library offers istreams for input. istreams deal
	// with character string representations of built-in types and can easily be
	// extended to cope with user-defined types.
	//
	// The >> ("get from") operator is used as in input operator; `cin` is the
	// std input stream. The type on the right-hand of the operator >> determines
	// what input is accepted and what is the target of the input operation.
	//
	auto f = []()
	{
		int i {};
		std::cin >> i;

		double d {};
		std::cin >> d;
	};
	// Floating-point number reads a floating point value and integer an integer.
	// Just like output operations these can be chained.
	//
	// To read a sequence of characters read into a string.
	//		std::string a {};
	//		std::cin >> a;
	// By default, a \n character or space terminates the read.
	//
	// To read a whole line use std::getline() function:
	//		std::getline(std::cin, a);
	// The \n character that terminated the line will be discarded.
	//
	// Instead of manipulating characters one-by-one, using formatted I/O
	// operations is much faster and efficient. In particular, istreams
	// take care of memory management and range checking.
	// std::string have the nice property of expanding for what needs to
	// be held. No need to allocate memory manually.
	// 10.3 Input

	// 10.4 I/O State
	// An iostream has a state that we can examine to determine if an operation
	// has succeeded:
	//		if (int i; is >> i) // do something
	// If something that is not an integer is encountered, the if statement will
	// not execute. The operation returns a reference to `is` and testing an
	// iostream yields `true` if the stream is ready for another operation.
	//
	// 
	// 10.4 I/O State
}
