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
    // 7.2.1 Use of Concepts
}
