#include <iostream>

// 7.2 Concepts (C++20)
// sum() from 6.3.1
template <typename Seq, typename Num>
Num sum(Seq s, Num v)
{
    for (const auto& x : s)
        v += x;
    return v;
}
// This template function can be invoked for any data structure that supports
// begin() and end() (makes for-range loop work). Some example data structures
// are vector, list and map included in the standard library.
//
// Furthermore, the data type of the structure is limited by its use: a type we
// can add to the value arg. (int, double, Matrix, etc.) sum() is generic in two
// dimensions: the type of the data struct used to store elem ("the sequence")
// and the type of elem. Such requirements are referred to as *concepts*.
// 7.2 Concepts (C++20)


int main()
{
    std::cout << "Chapter 7\n";
    // 7.2 Concepts (C++20)
    // Concept implementations are in use.
    // 7.2 Concepts (C++20)

    // 7.2.1 Use of Concepts
    // Most templates are constrained templates so generated code will work
    // properly. The type-name prefix *typename* is the least constraining,
    // requiring only an arg be a type.
    //
    // To do better use concepts.
    //      template <Sequence Seq, Number Num>
    // Once defined the compiler can reject bad calls by looking at sum's
    // interface only rather than it's implementation. In addition, we
    // should be able to add elements of a sequence to a number:
    //      template <Sequence Seq, Number Num>
    //          requires Arithmetic<ValueType<Seq>, Num>
    // The ValueType of a sequence is the type of the elem of a sequence.
    // Arithmetic<x, y> is concept that specifies we can do arithmetic
    // with numbers of type x and y. (i.e., prevents calculation for
    // vector<string> and vector<int*> but allows vector<int> and
    // vector<complex<double>>)
    //
    // Above the template arg is not constrained too tightly. Only
    // using the general concept Arithmetic for better future use.
    //
    // The "requires" portion is referred to as the *requirements-
    // clause*. The template<Sequence Seq> in fact, is a shorthand
    // for:
    //      requires Sequence<Seq>
    //
    // So, the alternative would look like:
    //      template<typename Seq, typename Num>
    //          requires Sequence<Seq>
    //          && Number<Num>
    //          && Arithmetic<Value_type<Seq>, Num>
    //      Num sum(Seq s, Num n);
    //
    // On the other hand:
    //      template<Sequence Seq, Arithmetic<Value_type<Seq>> Num>
    //      Num sum(Seq s, Num n);
    //
    // When we can't use concepts we'll default to comments.
    // 7.2.1 Use of Concepts

    // 7.2.2 Concept-based Overloading
    // Once specified, we can overload templates based on their properties.
    // Consider a concise copy of advance() from the standard-library:
    //      template <Forward_iterator Iter>
    //      void advance(Iter p, int n)
    //      {
    //          for (--n)
    //              ++p;
    //      }
    //
    //      template <Random_access_iterator Iter, int n>
    //      void advance(Iter p, int n)
    //      {
    //          p += n;
    //      }
    // The compiler will select the template with the strongest requirements
    // met by the arguments. For example a list only supplies forward iterators
    // but a vector has random-access iterators.
    //
    // These are compile-time mechanisms. If the compiler cannot find a best
    // choice, it will throw an ambiguity error.    
    // 7.2.2 Concept-based Overloading

    // 7.2.3 Valid Code
    // Whether template args offer what a template requires boils down to
    // whether some expressions are valid.
    // Using a requires-expression, we can check if a set of expressions is
    // valid.
    // template<Forward_iterator Iter>
    // void advance(Iter p, int n) // move p n elements forward
    // {
    //    for (−−n)
    //        ++p; // a forward iterator has ++, but not + or +=
    // }
    // template<Forward_iterator Iter, int n>
    //     requires requires(Iter p, int i) { p[i]; p + i; }
    //  void advance(Iter p, int n) // move p n elements
    // {
    //     p += n; // a random-access iterator has +=
    // }
    // The first requires starts the requirements-clause and the
    // second starts the requires-expression.
    //      requires requires(Iter p, int i) { p[i]; p + i; }
    // A require-expression is a predicate that is true if the statement
    // in it are valid code and false if they are not.
    //
    // Consider requires-expression the assembly code of generic programming.
    // Like ordinary assembly, requires-expressions are extremely flexible
    // and impose no programming discipline. Usually when you see
    // requires requires in your code, it's too low level.
    //
    // Prefer named concepts with well-specified comments semantics as
    // the implementation above is hackish and inelegant.
    // 7.2.3 Valid Code

    // 7.2.4 Definition of Concepts
    // A concept is a compile-time predicate specifying how one or more types
    // can be used.
    // Consider:
    // template <typename T>
    // concept Equality_comparable =
    //      requires (T a, T b) {
    //          { a == b } -> bool; // compare Ts with ==
    //          { a != b } -> bool; // compare Ts with !=
    //      };
    // Equality_comparable is concept that checks if a type is comparable using
    // += and !=. They must be comparable using the before, and the result
    // of the operation must be convertible to a bool.
    //
    // The following would fail:
    // struct S { int a; };
    // static_assert(Equality_comparable<S>);
    // This won't compile because structs do not automatically gain their ==
    // and != operations.
    //
    // For non-homogeneous operations simply add some additional requirements.
    // template <typename T, typename T2 = T>
    // concept Equality_comparable =
    //      requires (T a, T2 b) {
    //          { a == b } -> bool;
    //          { a != b } -> bool;
    //          { b == a } -> bool;
    //          { b != a } -> bool;
    //      };
    // If the second template arg T2 isn't specified, it will default to T.
    // 
    // 7.2.4 Definition of Concepts
}
