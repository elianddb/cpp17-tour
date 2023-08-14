#include <iostream>
#include <string>

// 9.2 Strings
// e.g. Concatenation Example
std::string compose(const std::string& name, const std::string& domain)
{
	// Addition of strings mean concatenation. The standard string has a move
	// constructor, so returning even long strings by value is efficient.
	return name + '@' + domain;
}
// 9.2 Strings

int main()
{
	std::cout << "Chapter 9\n";

	// 9.2 Strings
	// The standard library provides a string type to complement string 
	// literals. It provides a Regular type for owning and manipulating
	// a sequence of characters from various character types.
	// 
	// Initialized to the character sequence "dmr@bell-labs.com"
	std::string addr {compose("dmr", "bell-labs.com")};
	std::cout << addr << '\n';
	// Alternativately += is available to concatenate items to the end
	// of a string.
	// 
	// In addition to = and +=, subscripting (using []) and substring
	// operations are supported. 
	// e.g. Subscripting
	std::string name {"Niels Stroustrup"};
	auto m3 = [&]()
	{
		std::string s {name.substr(6, 10)}; // s = Stroustrop
		name.replace(0, 5, "nicholas");
		name[0] = std::toupper(name[0]);
	};
	// In the lambda substr and replace take two main paramaters in terms
	// of positioning. The starting index and length. Replace has the
	// additional value argument to replace the substring. (does not need
	// to match length).
	m3();
	std::cout << name << '\n';
	// Naturally, strings can be compared against each other, against C-style
	// strings, and against string literals. 
	// In addition, strings support lexographical ordering (<, >, <=, >=),
	// iteration (using iterators as for vector), input, and streaming.
	// 
	// If a C-style string is necssary (a zero-terminated array of char), string
	// offers read-only access to its contained characters.
	std::string s {"c-string"};
	auto print = [&s]()
	{
		printf("For people who like printf: %s\n", s.c_str());
	};
	print();
	// A string literal is by definition a const char*. To get a literal type
	// of std::string use s suffix.
	// auto s = "Cat"s;
	// auto c = "Dog";
	// The s suffix is contained in the std::literals::string_literals namespace.
	// 9.2 Strings
}
