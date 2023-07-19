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
        Complex() : re {}, im {} {}

        double real() const { return re; }
        void real(double d) { re = d; }
        double imag() const { return im; }
        void imag(double d) { im = d; }

        Complex& operator+=(Complex z)
        {
            re += z.re;
            im += z.im;
            return *this;
        }

        Complex& operator-=(Complex z)
        {
            re -= z.re;
            im -= z.im;
            return *this;
        }

        // 4.2.1 defined out-of-class
        Complex& operator*=(Complex);
        Complex& operator/=(Complex);
    };
}
#endif
