#include <iostream>
// 2.2 Structures
namespace Structures
{
    struct Vector
    {
        int sz {};       // num of elems
        double* elem {}; // pointer ot elems

        static void vector_init(Vector& v, int s);
    };

    void Vector::vector_init(Vector& v, int s)
    {
        // The new operator allocates memory from an area called the free store
        // (also known as dynamic memory and heap). These objects are 
        // independent of scope and live until they are destroyed using the
        // delete operator.
        v.elem = new double[s];
        v.sz = s;
    }
}

double read_and_sum(int s)
{
    using namespace Structures;
    Vector v;
    Vector::vector_init(v, s);

    for (int i {}; i != s; ++i)
        std::cin >> v.elem[i];

    double sum {};
    for (int i {}; i != s; ++i)
        sum += v.elem[i];

    return sum;
}

double read_and_sum(Structures::Vector& vec)
{
    double sum {};
    for (int i {}; i != vec.sz; ++i)
        sum += vec.elem[i];
    return sum;
}
// 2.2 Structures

int main()
{
    // 2.2 Structures
    // Generally we don't reinvent std library components, but for the sake
    // of example we'll use vector to illustrate design and features.
    Structures::Vector v;
    Structures::Vector::vector_init(v, 4);
    v.elem[0] = 10;
    v.elem[1] = 10;
    v.elem[2] = 10;
    v.elem[3] = 10;
    std::cout << read_and_sum(v) << '\n';
    std::cout << read_and_sum(4) << '\n';
    // 2.2 Structures
}
