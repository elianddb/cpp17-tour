#include <iostream>
#include <list>

#include "vector.hpp"

// 6.3.1 Function Templates
// Calculate the sum of the element values of any sequence
// that a range-for can traverse (a container).
template <typename Sequence, typename Value>
Value sum(const Sequence& s, Value v)
{
    for (const auto& x : s)
        v += x;
    return v;
}
// 6.3.1 Function Templates

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
    const DDB::V4::Vector<int> vec {4};
    vec[0] = 'h';
    vec[1] = 'a';
    vec[2] = 'i';
    vec[3] = 'r';
    for (const auto& r : vec)
    {
        std::cout << r;
        if (&r != vec.end() - 1)
            std::cout << ' ';
    }
    std::cout << '\n';

    DDB::V4::Vector<std::string> vs {17};
    DDB::V4::Vector<std::list<int>> vli {71};
    DDB::V4::Vector<int> vi {4};
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
    //
    // Since C++ does not officially support concepts before C++20, older code
    // uses unconstrained template arguments and leaves requirements to
    // documentation.
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
    //      Buffer<char, 1024> glob;
    // 6.2.2 Value Template Arguments

    // 6.2.3 Template Argument Deduction
    // std::pair<int, double> p = {1, 5.2};
    // People can find the need to specify template args tedious.
    // The standard library offers a function, make_pair(), that deduces the
    // template arguments of the pair and it returns from its function args.
    //      auto p = std::make_pair(1, 5.2);
    //
    // C++17 provides the ability to deduce these template parameters from
    // constructor args.
    //      std::pair p {1, 5.2};
    //
    // Vector vs{"Hello", "World"};
    // Vector vs2{"Hello"s, "World"s};
    // The first statement creates a vector of const char*, however, using
    // the s suffix we can get std::string.
    //
    // When a template arg cannot be deduced from the constructor args, we
    // can help by providing a deduction guide.
    // Consider the following:
    //      template <typename T>
    //      class Vector2
    //      {
    //          using value_type = T;
    //          public:
    //          template <typename Iter>
    //          Vector2(Iter b, Iter e); // [b:e) range constructor
    //      }
    // If we use the range constructor by using the iterators of another
    // vector let's say vector<int>. The compiler has no idea how to deduce
    // this new vector will be int.
    //
    // So we use a "deduction guide" after the declaration of Vector:
    //      template <typename Iter>
    //      Vector2(Iter, Iter) -> Vector2<typename Iter::value_type>;
    // This basically translates to: if we initialize Vec2 with a pair of
    // iterators, deduce Vec2::value_type to be the iterators' value type.
    //
    // It's best to design class templates so that deduction guides
    // are not needed. However, the std library is full of classes that still
    // don't use concepts and have such ambiguities.
    // 6.2.3 Template Argument Deduction

    // 6.3 Parameterized Operations
    // Templates have more uses than just parameterizing the element type of a
    // container. They are also used for the paramaterization of algorithms
    // and types in the standard library.
    // 
    // Three ways of expressing an operation parameterized by types of values:
    // A function template
    // A function object: an object that can carry data and can be called like
    // a function.
    // A lambda expression: a shorthand notation for a function object.
    // 6.3 Parameterized Operations

    // 6.3.1 Function Templates
    // void user(Vector<int>& vi, list<double>& ld, vector<complex<double>>& vc)
    // {
    //      int x = sum(vi, 0);
    //      double d = sum(vi, 0.0);
    //      double dd = sum(ld, 0.0);
    //      auto z = sum(vc, complex{0.0, 0.0});
    // }
    // In this case we add ints to a double to handle sums larger than what 
    // int can handle. Sequence and Value are deduced from the function 
    // arguments.
    // 
    // This sum() is a simplified version of standard library accumulate().
    // 
    // A function template can be a member function but not a virtual 
    // member. The compiler would not know all instatiations of such a template
    // in a program, so it could not generate a vtbl.
    // 6.3.1 Function Templates

    // 6.3.2 Function Objects
    // A particularly useful function template is function objects (often called
    // functors). These define objects that can be called like functions.
    // template <typename T>
    // class LessThan
    // {
    // public:
    //      LessThan(const T& v) : val {v} {}
    //      bool operator()(const T& x) const { return x < val; }
    // private:
    //      const T val;
    // };
    // The function called operator() implements the "function call", "call",
    // or "application" operator ().
    //      LessThan lti {42};
    //      bool = lti(n);
    // We call the lti object as if it were a function. It compares if n < its
    // representation.
    // 
    // We can define named variables of type LessThan for some arg type.
    // 6.3.2 Function Objects
}
