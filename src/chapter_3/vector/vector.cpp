// Ensure consistency with header file
#include "vector.hpp"
using namespace DDB;

Vector::Vector(int sz) : elem {new double[sz]}, sz {sz} {}

double& Vector::operator[] (int i) { return elem[i]; }

int Vector::size() { return sz; }