#include "vector/vector.hpp"
#include <cmath>
#include <iostream>

double sqrtSum(DDB::Vector& vec)
{
    double sum {};
    for (int i {}; i != vec.size(); ++i)
        sum += std::sqrt(vec[i]);
    return sum;
}

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
    DDB::Vector vec {4};
    for (int i {}; i != vec.size(); ++i)
        vec[i] = 4;
    std::cout << sqrtSum(vec) << '\n';
    // 3.2 Separate Compilation
}
