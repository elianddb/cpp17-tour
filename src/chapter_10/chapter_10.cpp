#include <fstream>
#include <iostream>
#include <sstream>
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
// 10.4 I/O State

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
// Input operator implementation (formatted with {"",int}):
std::istream& operator>>(std::istream& is, Entry& e)
{
	char c1 {};
    char c2 {};
    // starts with "{"
	if (is >> c1 && c1 == '{' && is >> c2 && c2 == '"')
	{
		std::string name {}; // default val is empty but might as well.
		// anything before the next " is part of the name
		while (is.get(c1) && c1 != '"') 
			name += c1;

		// after " there should be a quotation mark and we read the num
		if (is >> c1 && c1 == ',')
		{
			int number {};
			if (is >> number >> c1 && c1 == '}') // should end with }
			{
				e = {name, number};
				return is;
			}
		}
	}

	// failed to get input.
    is.setstate(std::ios_base::failbit);
    return is;
}
// 10.5 I/O of User-Defined Types

// 10.8 String Streams
template <typename Target = std::string, typename Source = std::string>
Target to(Source arg) // convert source to target.
{
	std::stringstream interpreter {};
	Target result {};
	// write arg into stream
	if (!(interpreter << arg) // write arg into stream 
		|| !(interpreter >> result) // read result from stream
		|| !(interpreter >> std::ws).eof()) // is stuff left in stream?
		throw std::runtime_error {"to<>() failed"};
	return result;
}
// 10.8 String Streams

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
	std::cout << R"(Use the {"",int} format to create an Entry object.)" << '\n';
	Entry test {};
	std::cin >> test;
	std::cout << test << '\n';
	// A user-defined output operator takes it output stream (by reference) as
	// its first argument and returns it as the result.
	//
	// An input operation returns a reference to its istream that can be used to
	// test if the operation succeeded. is.get() does not space whitespace while
	// is>>c does (c = char type). This allows us to read weirdly formatted
	// inputs, but that overall have the correct syntax.
	// 10.5 I/O of User-Defined Types

	// 10.6 Formatting
	// The `iostream` library provides a large set of operations for controlling
	// the format of input and output. Simplest formatting controls are called
	// *manipulators*. They are found in <ios>, <istream>, <ostream>, and
	// <iomanip>.
	//
	// One example is outputting types in different formats:
	std::cout << 1234 << " "
    << std::hex << 1234 << " "
    << std::oct << 1234 << '\n';
	// There's also output formats for floating point types.
	// std::scientific, std::hexfloat, std::fixed, std::defaultfloat
	//
	// Precision is an integer that determines the number of digits used
	// to display a floating-point number:
	//		`defaultfloat` lets the implementation choose a format that
	//		presents a value in the style that best preserves the value in the
	//		space available. Precisions sets the max num of digits.
	//		`scientific` presents in the scientific notation. Precision sets
	//		the max num of digits after the decimal point.
	//		`fixed` presents the value as an integer part followed by a decimal
	//		point and a fractional part. Use precision to specify max num of digits
	//		after the decimal point.
	//
	// `precision()` does not affect integer output. These floating-point
	// manipulators are "sticky"; that is, their effects persist for subsequent
	// floating-point operations.
	// 10.6 Formatting

	// 10.7 File Streams
	// In <fstream> the standard library provides streams to and from a file:
	//		ifstream for reading from the file
	//		ofstream for writing to a file
	//		fstream to do both
	// One example:
	std::ofstream ofs {"target"};
	if (!ofs)
		std::cerr << "Couldn't open 'source' for reading\n";
	// The ofs and ifs streams can be used just as ordinary istreams and ostreams.
	// 10.7 File Streams

	// 10.8 String Streams
	// <sstream>, the std lib provides streams to and from a string.
	//		istringstream for reading from a string
	//		ostringstream for writing to a string
	//		stringstream for both.
	// Example:
	auto sstreamTest = []()
	{
		std::ostringstream oss {};
		oss << "{temperature, " << std::scientific << 123.4567890 << '}';
		std::cout << oss.str() << '\n';
	};
	sstreamTest();
	// The result from an istringstream can be read using str(). One common
	// use of an ostringstream is to format before giving the resulting string
	// to a GUI. Similarly, a string received from a GUI can be read using
	// formatted input operations (10.3) by putting it into an istringstream.
	auto x1 = to<std::string, double>(1.2); // explicit and verbose
	auto x2 = to<std::string>(1.2); // src is deduced to double
	auto x3 = to<>(1.2); // target defaults to std::string, src deduced double
	auto x4 = to(1.2); // <> is redundant
	std::cout << x4 << '\n';
	// 10.8 String Streams
}
