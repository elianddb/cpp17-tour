#include "complex.hpp"
#include "complex.hpp"

using namespace DDB;

Complex& Complex::operator*=(Complex z)
{
    re *= z.re;
    im *= z.im;
    return *this;
}

Complex& DDB::Complex::operator/=(Complex z)
{
    re /= z.re;
    im /= z.im;
    return *this;
}
