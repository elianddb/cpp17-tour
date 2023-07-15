import Vector;
#include "vector.hpp"
#include <cmath>
#include <iostream>

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
    // 
    // 3.4 Namespaces
}