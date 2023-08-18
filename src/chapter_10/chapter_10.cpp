#include <iostream>
#include <vector>

// 10.4 I/O State
std::vector<int> readInts(std::istream& is, const std::string& terminator)
{
	std::vector<int> result {};
	for (int i {}; is >> i;)
		result.emplace_back(i);

	// Find end of file.
    if (is.eof())
		return result;

	// Failed to read int.
	if (is.fail())
	{
		is.clear(); // reset the state to good()
		is.unget(); // put the non-digit back into the stream
		std::string s {}; 
		if (std::cin >> s && s == terminator)
			return result;
		std::cin.setstate(std::ios_base::failbit); // add fail() to cin's state
	}

	return result;
}

// 10.5 I/O of User-Defined Types
struct Entry
{
	std::string name;
	int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e)
{
	return os << "{\"" << e.name << "\", " << e.number << '}';
}

// 10.5 I/O of User-Defined Types

// 10.4 I/O State

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
	// The I/O state in general holds the information needed to read or write.
	// (i.e. formatting info, error state, type of buffering used)
	// The user can set a state to signal an error has occured and clear the
	// state if the error is not serious:
	// 10.4 I/O State

	// 10.5 I/O of User-Defined Types
	// The `iostream` library allows programmers to define I/O for their own
	// types. For example, consider type Entry.
	// We can define an output operator to write an Entry using {"name", number}:
	//		See above.
	Entry test {"hello", 5};
	std::cout << test;
	// The user-defined output operator takes it output stream (by reference) as
	// its first argument and returns it as the result.
	// 10.5 I/O of User-Defined Types
}
