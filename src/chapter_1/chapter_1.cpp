// #include instructs the compiler to include declarations (std stream 
// I/O facilities in this case)
#include <iostream>

// Comments: these are ignored by the compiler, primarily for humans
// {} express grouping of statements
// main() global function every C++ program has
// int (integer) return value of main()
//      no-value returned -> system received successful completion
//      nonzero value returned -> indicates failure
// Windows based systems rarely make use of this value, but Linux systems do

int main()
{
    std::cout << "Hello, world!\n";
    // << "put to" writes second arg into first
    // \ in a string denotes a special character
    // \n newline character
    // std:: specifies that cout is from the std library namespace
}
