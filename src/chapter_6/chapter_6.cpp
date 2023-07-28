#include <list>

#include "vector.hpp"

int main()
{
    // 6.2 Parameterized Types
    // template <typename T>
    // The prefix makes a T parameter of the declaration it prefixes.
    // Using class instead of typename is equivalent. (template <class t>)
    //
    // In combination with member functions definitions:
    // template <typename T>
    // Vector<T>::Vector(int s) {}
    // We gain the ability to define Vector's as follows:
    // Vector<double> vc {200};
    // 
    // Templates are a compile time mechanism, there is no runtime overhead
    // incurred when using them. In fact, the new Vector implementation
    // may result in the same machine code as the original double Vector.
    // 
    // Templates plus a set of template args is called an instantiation or
    // specialization. Code is generated for each instantiation used.
    // It's also type checked to be as safe as hand written code.
    DDB::V4::Vector<char> vec{4};
    DDB::V4::Vector<std::string> vs{17};
    DDB::V4::Vector<std::list<int>> vli{17};
    // 6.2 Parameterized Types     

    // 6.2.1 Constrained Template Arguments (C++20)
    // Often templates will only make sense for template arguments that 
    // meet certain criteria. For example, a Vector typically offers
    // a copy operation, so it must require elements that must be copyable.
    //      In other words, the template's argument is not just a typename
    //      but an "Element". Where "Element" specifies a list of requirements
    //      of a type that can be an element.
    // 
    // Code example:
    // template <Element T>
    // class Vector { \*...*\ };
    // 
    // This is C++'s version of mathematics' "for all T such that Element(T)";
    // that is, Element is a predicate that checks whether T has all properties
    // that a Vector requires. We call these concepts.
    // 
    // Template arguments with concepts are referred to as a *constrained
    // argument* and templates with constrained args are called a *constrained
    // template*.
    // 
    // It's a compile-time error to instantiate a template with a type that
    // does not meet it's requirements.
    //      Vector<thread> v2; // for example.
    // 6.2.1 Constrained Template Arguments (C++20)

    // 6.2.2 Value Template Arguments
    // In addition to to type arguments (typename T) a template can take value
    // args.
    // template <typename T, int N>
    // struct Buffer
    // {
    //      using value_type = T;
    //      constexpr int size() { return N; }
    //      T[N];
    // };
    // 
    // These can be useful in different context. For Buffer, it allows the
    // creation of arbitrarily sized and typed buffers with no use of free
    // store.
    // Buffer<char, 1024> glob;
    // 6.2.2 Value Template Arguments

    // 6.2.3 Template Argument Deduction
    // std::pair<int, double> p = {1, 5.2};
    // People can find the need to specify template args tedious.
    // The standard library offers a function, make_pair(), that deduces the
    // template arguments of the pair and it returns from its function args.
    // auto p = std::make_pair(1, 5.2);
    // 6.2.3 Template Argument Deduction
}
