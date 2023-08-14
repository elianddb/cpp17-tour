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
	// 9.2 Strings
}
