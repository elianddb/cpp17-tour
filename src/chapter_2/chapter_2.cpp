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

// 2.3 Classes
namespace Classes
{
    class Vector
    {
    public:
        // Constructor: constructs object of a class. States an integer
        // is necessary to construct a Vector.
        // The constructor initializes the Vector members using a member
        // initializer list: : elem {new double[s]}, sz {s}
        Vector(int s) : elem {new double[s]}, sz {s} {}
        // Provides access to elements (subscript function). Returns an
        // appropriate non-const reference to an element 
        // allowing reading and writing.
        double& operator[](int i) { return elem[i]; };
        int size() { return sz; };
    private:
        double* elem;
        int sz;
    };
}
// 2.3 Classes

int main()
{
    // 2.2 Structures
    // Generally we don't reinvent std library components, but for the sake
    // of this example we'll use vector to illustrate design and features.
    // struct -> a data structure
    Structures::Vector v;
    Structures::Vector::vector_init(v, 4);
    v.elem[0] = 10;
    v.elem[1] = 10;
    v.elem[2] = 10;
    v.elem[3] = 10;
    std::cout << read_and_sum(v) << '\n';
    std::cout << read_and_sum(4) << '\n';
    // . (dot) is used to access struct members through their name (and ref)
    // -> (arrow) to access struct members through a pointer
    Structures::Vector* pv {&v};
    int i1 {pv->sz};
    // 2.2 Structures

    // 2.3 Classes
    // To distinguish between the interface to a type and its implementation
    // we use a class. A class has a set of members, which can be data,
    // function, or type members. 
    // public: members define the interface of a class
    // private: members are accessible through the interface
    Classes::Vector cv{6}; // a vector variable of 6 elements
    // The Vector object is a "handle" containing a pointer to the elements
    // and number of elements. 
    // This shows the basic technique for handling varying amounts of
    // information in C++:
    //      a fixed-size handle referring to a variable amount of data
    //      "elsewhere"
    // handle: abstract reference to a resource
    // The fundamental different between a struct and class is that
    // structs are public by default and classes are private by default.
    // 2.3 Classes
}
