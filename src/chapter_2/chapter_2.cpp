#include <iostream>
#include <variant>

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

// 2.4 Unions
// Imagine a symbol table entry that holds a name and a value.
// The value can be either a Node* or an int.
//
// Nodes are basic units of a data structure.
// They contain data and also may link to other Nodes.
struct Node
{
    int val {};
    Node* link {};
};

// can hold values ptr and num
enum Type { ptr, num };

namespace V1
{
    struct Entry
    {
        std::string name;
        Type t;
        Node* p;
        int i;
    };

    // Since p and i are never used at the same time space is wasted.
    // Recover that space by specifying both should be members of a union.
    // (check V2 below)
    void f(Entry* pe)
    {
        if (pe->t == num)
            std::cout << pe->i;
        // ...
    }
}

namespace V2
{
    union Value
    {
        Node* p;
        int i;
    };

    struct Entry
    {
        std::string name;
        Type t;
        Value v;
    };

    // The problem left is maintaining correspondence between a type field
    // and the type held in the union. It's error-prone, and instead we
    // can enforce the correspondence by encapsulating the union and the type
    // field in a class and offer access through member functions that
    // guarantee correct access.
    // So, the use of "naked" unions is best minimized. (check V3)
    void f(Entry* pe)
    {
        if (pe->t == num)
            std::cout << pe->v.i;
    }
}

inline namespace V3
{
    // std::variant can be used to eliminate most direct uses of unions.
    // It stores a value of one of a set of alternative types.
    // (e.g., variant<Node*, int> can hold either but only one)
    struct Entry
    {
        std::string name;
        std::variant<Node*, int> v;
    };

    void f(Entry* pe)
    {
        if (std::holds_alternative<int>(pe->v))
            std::cout << std::get<int>(pe->v) << '\n';
        else
            std::cout << "{Node}\n";
    }
}
// 2.4 Unions

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

    // 2.4 Unions
    // A struct in which all members are allocated at the same address.
    // A union occupies only as much space as its largest member.
    // Naturally it can only hold a value for one member at a time.
    Entry myEntry {"num0", 0};
    f(&myEntry);

    Node test {0, nullptr};
    myEntry.v = &test;
    f(&myEntry);
    // 2.4 Unions
}
