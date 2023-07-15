import Vector;
#include "vector.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>

// 3.2 Separate Compilation
double sqrtSum(DDB::Vector& vec)
{
    double sum {};
    for (int i {}; i != vec.size(); ++i)
        sum += std::sqrt(vec[i]);
    return sum;
}
// 3.2 Separate Compilation

// 3.3 Modules (C++20)
double sqrtSum(Modules::Vector& vec)
{
    double sum {};
    for (int i {}; i != vec.size(); ++i)
        sum += std::sqrt(vec[i]);
    return sum;
}
// 3.3 Modules (C++20)

int main()
{
    // 3.2 Separate Compilation
    // C++ supports the notion of separate compilation where user code
    // sees only declarations of the types and functions used.
    //
    // Definitions of those types are held in separate source files and
    // are compiled separately.
    //
    // These features can be used to organize a program into a set of
    // semi-independent code fragments. A library is often a collection
    // of separately compiled code fragments (e.g., functions).
    DDB::Vector vec1 {4};
    for (int i {}; i != vec1.size(); ++i)
        vec1[i] = 4;
    std::cout << sqrtSum(vec1) << '\n';
    // vector.cpp and chapter_3.cpp are sharing the vector interface (header)
    // but are otherwise independent.
    // A .cpp file that is compiled by itself (including the header files it
    // includes) is called a translation unit. A program can consist of
    // thousands of translation units.
    // 3.2 Separate Compilation

    // 3.3 Modules (C++20)
    // The use of #includes is very old, error-prone, and a rather expensive
    // way of composing programs out of parts.
    //
    // Including the same header in many different translation units will have
    // that header file's text processed by the compiler that many times.
    // How about if you include one header file before another. That header
    // might affect the declarations in the next header file.
    //
    // This is not ideal, and in fact is a major source of cost and bugs.
    //
    // A better way of expressing physical modules is the use of the C++
    // language feature, modules.
    Modules::Vector vec2 {4};
    for (int i {}; i != vec2.size(); ++i)
        vec2[i] = 9;
    std::cout << sqrtSum(vec2) << '\n';
    // The difference between headers and modules is not just syntactic.
    //      A module is compiled once only.
    //      Two modules can be imported in either order without changing
    //      their meaning.
    //      If you import something into a module, users of the module
    //      do not implicitly gain access to what is imported.
    // 3.3 Modules (C++20)

    // 3.4 Namespaces
    // C++ offers namespaces as a mechanism for expressing that declarations
    // belong together and their names shouldn't clash with other names.
    //
    // For example:
    // You might want to create experiments emulating types in the std library.
    // The problem is using the names from the std library will create
    // collisions. A namespace dodges this problem by requiring a name to be
    // qualified with the namespace name.
    //      MyCode::main();
    //
    // If this ever becomes tedious, a name can be brought to scope with a
    // using-declaration.
    //      using std::swap;
    // It makes the name appear as if it was declared in the scope in which the
    // using-declaration appears.
    //
    // To gain access to a whole namespace append namespace to the 
    // using-directive.
    //      using namespace std;
    // This should be used carefully as it removes the ability to selectively
    // use names.
    //
    // Namespace definition:
    //      namespace MyCode
    //      {
    //      }
    // 3.4 Namespaces

    // 3.5 Error Handling
    // Large and complex topic, but C++ provides a few features to help.
    // Instead of painstakingly building up applications from built-in types,
    // build types and algorithms that are appropriate (e.g., sort(), regex).
    //
    // These higher-level constructs simplify programming and limit opportunity
    // for mistakes, and increase compiler's chances of catching errors.
    // 3.5 Error Handling

    // 3.5.1 Exceptions
    // What if the user tries to read a vector out-of-bounds?
    //      The writer of Vector doesn't know what the user wants.
    //      The user cannot consistently detect this problem.
    //
    // Let's assume we want to recover from this error. The solution is to
    // have the Vector implementation detect the out-of-range access.
    try
    {
        vec1[123] = 0; // will cause std::out_of_range exception
    }
    catch (std::out_of_range& err)
    {
        std::cerr << "EXCEPTION: " << err.what() << '\n';
    }
    // try-block will encompass the potential exception and the catch-block
    // will provide a handler for exceptions of type out_of_range. Standard
    // library containers also use <stdexcept> classes.
    //
    // Do not overuse try-statements.
    //
    // A function that should never throw an exception can be declared noexcept
    //      void user(int sz) noexcept {}
    // If all planning fails, std::terminate() is called to immediately
    // to terminate the program.
    // 3.5.1 Exceptions
}
