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

// 1.7.1 The Null Pointer
// char* assumes a C-style string which is a zero-terminated
// array of char.
// immutable characters so declare const char*
// nullptr eliminates potential confusion between integer and pointers
//      (old code used 0 and NULL instead nullptr)
int count_x(const char* p, char x)
{
    if (p == nullptr)
        return 0;
    int count {};
    while (*p != 0)
    {
        if (*p == x)
            ++count;
        ++p; // advance pointer to point to the next element
    }
    return count;
}
// 1.7.1 The Null Pointer

// 1.8 Tests
bool accept()
{
    std::cout << "Do you want to proceed (y or n)?\n";
    char answer {};
    // >> operator "get from" used for input
    // cin is the standard input stream
    std::cin >> answer;

    if (answer == 'y')
        return true;
    return false;
}
// 1.8 Tests

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

    // 1.6 Constants
    // There are two notions of immutability in C++:
    //      const meaning roughly I promise not to change this value. The
    //      compiler enforces this promise.
    //      constexpr which is evaluated at compile time.
    constexpr int dmv = 17;
    int var = 17;
    const double sqv = sqrt(var);
    // You can also create constexpr function which may evaluate at compile
    // time depending on the parameters. Some places require constant
    // expressions such as array bounds, case labels, template value arguments,
    // and constants declared using constexpr.
    // 1.6 Constants

    // 1.7 Pointers, Arrays and References
    // Fundamental collection of data contiguously allocated sequence 
    // of elements of the same type is an array. This is offered by 
    // hardware.
    char v[6] {}; // array of 6 characters
    char* p; // pointer to character
    // [] means "array of" and * means "pointer to"
    // All arrays have 0 as their lower bound so v[0] to v[5]
    // A pointer variable holds the address of an object of the appropriate
    // type.
    p = &v[3];
    char x {*p};
    // In an expression, prefix * means "contents of" and & means "address of"
    // In a declaration, the unary & means "reference to". A reference is
    // similar to a pointer, except that you don't need to use prefix * to
    // access the value referred to. Also a reference cannot be made to
    // refer to a different object after initialization.
    // References are particularly useful for specifying large function args.
    char& ref {v[3]};
    ref = 4; // changes v[3], serves more like an alias
    // When used in declarations, operators (&, *, []) are called declarator
    // operators.
    // 1.7 Pointers, Arrays and References

    // 1.7.1 The Null Pointer
    // We try to ensure that a pointer always points to an object so that
    // dereferencing it is valid.
    // Pointers that don't have an object to point to or that need to
    // represent the notion of "no object available" use nullptr.
    double* pd {nullptr};
    // For this reason it's always wise to check that pointer arg
    // actually points to something.
    // 1.7.1 The Null Pointer

    // 1.8 Tests
    // Set of statements for expressing selection and looping:
    //      if-statements
    //      switch-statements
    //      while-loops
    //      for-loops
    accept();
    // You can declare a name in the condition of an if-statement and
    // for-statement to keep the score of the variable limited to
    // improve readability and minimize errors.
    //      if (auto n = v.size(); n != 0)
    //          // do something ...
    // 1.8 Tests
}
