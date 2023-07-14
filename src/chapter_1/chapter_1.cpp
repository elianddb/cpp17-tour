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

    // 1.4 Types, Variables, and Arithmetic
    // Every name and every expression has a type that determines the operation
    // that may be performed on it.
    // 
    // Declaration: a statement that introduces an entity to the program.
    // Type: defines a set of possible value and operations for an object.
    // Object: some memory that holds a value of some type.
    // Value: a set of bits interpreted according to a type.
    // Variable: a named object.'
    // 
    // The list of fundamental types can be found:
    // https://en.cppreference.com/w/cpp/language/types
    // Each fundamental type corresponds directly to hardware and have
    // a fixed size that determines a range of values.
    // The size can vary among different machines, use the sizeof() operator
    // to obtain the size in bytes. (byte = 8 bits)
    int inch;
    // 
    // Floating-point literals can be expressed as: 3.14 or 3e-2
    // Integer literals can change base using the following:
    //      default decimal -> 42
    //      0b prefix -> base 2 (e.g., 0b10101010)
    //      0x prefix -> base 16 (e.g., 0xBAD1234)
    //      0 prefix  -> base 8 (e.g., 0334)
    // Single quotes can be used to make long literals more readable:
    //      1'000'000
    //      0x3.243F'6A88'85A3'08D3
    // 1.4 Types, Variables, and Arithmetic

    // 1.4.1 Arithmetic
    // Arithmetic operators can be used for appropriate combination of 
    // fundamental types: +, -, *, /, % (unary: -, +)
    // Same goes for other operators:
    // Comparison Operators: ==, !=, <, >, <=, >=
    // Logical Operators: &, |, ^, &&, ||, (unary ~ [invert bits], !)
    // 
    // Basic types can be mixed freely:
    double d {2.2};
    int i {7};
    d = d + i;
    i = d * i; // Beware of truncation.
    // 1.4.1 Arithmetic

    // 1.4.2 Initialization
    // Before an object can be used, it needs to be given a value. There's a
    // variety of notations to do this:
    double d1 = 2.3;
    double d2 {2.3};
    double d3 = {2.3}; // = is optional with {...}
    // = form is traditional dates back to C, but if in doubt use general {}
    // list form. Saves from loss of information from conversions.
    //      int i1 = 7.8; // i1 would only hold 7
    // 
    // When defining a variable you don't need to state its type explicitly
    // when it can be deduced from the initializer:
    auto b = true;
    auto ch = 'x';
    // We use = because there is no potential for troublesome type conversion.
    // Use auto when there is no reason to mention the type explicitly.
    //      auto allows us to avoid redundancy and writing long type names.
    //      Usually helpful in generic programming where the exact type is hard
    //      to know.
    // 1.4.2 Initialization

    // 1.5 Scope and Lifetime
    // A declaration introduces its name into a scope:
    //      Local scope: function or lambda declaration, the scope extends
    //      from the point of declaration to the end of the block in which
    //      it occurs. block = {}
    //      Class scope: member name if defined in a class, outside any func,
    //      lambda, or enum class.
    //      Namespace scope: namespace member name if it is defined in a
    //      namespace outside any func, lambda, class, or enum class.
    // 
    // A name not declared inside any other construct is called a global name
    // and said to be in a global namespace.
    // 
    // In addition, we can have objects without names, such as temporaries and
    // objects created using new.
    // 1.5 Scope and Lifetime
}
