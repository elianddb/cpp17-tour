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
    //      template <ForwardIterator Iter>
    //      void advance(Iter p, int n)
    //      {
    //          for (--n)
    //              ++p;
    //      }
    //
    //      template <RandomAccessIterator Iter, int n>
    //      void advance(Iter p, int n)
    //      {
    //          p += n;
    //      }
    // 7.2.2 Concept-based Overloading
}
