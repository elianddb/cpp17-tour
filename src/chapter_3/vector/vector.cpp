// Ensure consistency with header file
#include "vector.hpp"

#include <stdexcept>
using namespace DDB;

Vector::Vector(const int sz) : elem {new double[sz]}, sz {sz} {}

double& Vector::operator[] (const int i) const
{
    if (i < 0 || size() <= i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

int Vector::size() const { return sz; }
