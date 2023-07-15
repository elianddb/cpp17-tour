// Ensure consistency with header file
#include "vector.hpp"

#include <stdexcept>
using namespace DDB;

Vector::Vector(const int sz)
: elem {new double[sz]}, sz {sz} {}

double& Vector::operator[] (const int i) const
{
    // throw transfers control to a handler for exceptions of type out_of_range
    // in some function that directly or indirectly called this function. The
    // implementation will unwind the function call stack as need to get back
    // to the context of the caller.
    if (i < 0 || size() <= i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size() const { return sz; }
