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
	
	// 9.2 Strings
}