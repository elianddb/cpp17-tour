// #include instructs the compiler to include declarations (std stream 
// I/O facilities in this case)
#include <iostream>

// 1.3 Functions
// Elem* next_elem();   no-arg; return a pointer to
// void exit(int);      int arg; return nothing
// double sqrt(double); double arg; return a double
// The semantincs of argument passing are identical to the semantics
// of initialization. (args are checked and implicit conversion takes
// place when necessary)
// For functions that are members of a class. The name of its class
// is also part of the function type:
//      char& String::operator[] const (int index);
// If two alternative functions could be called and they are similar,
// the call is deemed ambiguous and the compiler gives an error.
//      void print(int, double);
//      void print(double, int);
// Defining multiple functions with the same name is known as function
// overloading. An essential part of generic programming.
//      The compiler will choose the appropriate function to invoke the call.
// 1.3 Functions

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
