#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED
namespace DDB
{
    // 4.2.1 "classical user-defined arithmetic type"
    class Complex
    {
        double re;
        double im;
    public:
        Complex(double r, double i)
            : re{r}, im{i} {}
        Complex(double r)
            : re {r}, im {} {}
        Complex() : re {} : im {} {}
    };
}
#endif
