#include <iostream>
#include <vector>

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

// 7.3.2 Abstraction Using Templates
double sum(const std::vector<int>& v)
{
    double res = 0;
    for (const auto x : v)
        res += x;
    return res;
}
// This is one of the many ways to compute a sum of a sequence of numbers.
//      Consider what makes this code less general.
//      ints
//      vectors
//      accumulates double
//      starts at 0
//      adds
//
// If you answer the first four questions you'll basically get a basic version
// of the standard's library accumulate algorithm.
template <typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res)
{
    for (auto p = first; p != last; ++p)
        res += *p;
    return res;
}
// The data structure traversed has been abstracted to a set of iterators which
// represent the sequence.
// Type of the accumulator has been made into a param.
// The initial val is now an input. The type of the accumulator is he type of
// initial val.
//
// The process of generalizing from a concrete piece of code while preserving
// performance is called lifting. Conversely, the best way to develop a
// template is to:
//      write a concrete ver.
//      debug, test, and measure it.
//      finally replace concrete with template args.
//
// Repetition of begin() and end() is tedious, replace with:
// template <Range R, Number Val>
// Val accumulate(R r, Val res = 0)
// {
//    for (auto p = begin(r); p != end(r); ++p)
//        res += *p;
//    return res;
// }
// 7.3.2 Abstraction Using Templates

// 7.4 Variadic Templates
// Traditional implementation involves a separate first arg and recursive
// calls to the tail of the args.
void print() {} // no args.

template <typename T, typename... Tail>
void print(T head, Tail... tail)
{
    std::cout << head << ' ';
    print(tail...);
}
// "typename..." indicates Tail is a sequence of types.
// "Tail..." indicates tail is a sequence of values of the types in Tail.
// Parameters declared with ... is called a *parameter pack*.
// tail is a (function arg) parameter pack where the elements are of the
// types found in the (template arg) parameter pack Tail. So print can
// take any num of args of any type.
//
// You can also eliminate the use of a no-arg print using a compile time
// if
//      if constexpr(sizeof...(tail) > 0)
//          print(tail...);
// compile-time if avoid the potential generation of never called print
// statement.
//
// Variadics can accept any arg you give them. However, weaknesses include:
//      recursive implementation complexity
//      recursive implementation surprisingly expensive at compile
//      interface type checking is possibly an elaborate template program
// For this reason they are widely used in the std library and occasionally
// overused.
// 7.4 Variadic Templates

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
    // More complex example:
    // template <typename S>
    // concept Sequence = requires(S, a) {
    //      typename Value_type<S>; // S must have Value_type
    //      typename Iterator_type<S>; // S must have an Iterator_type
    //
    //      { begin(a) } -> Iterator_type<S>; // begin(a) must return an iterator.
    //      { end(a) } -> Iterator_type<S>;   // end(a) must return an iterator.
    //
    //      requires Same_type<Value_type<S>, Value_type<Iterator_type<S>>>;
    //      requires Input_iterator<Iterator_type<S>>;
    // }
    // For S to be a sequence it must provide a Value_type (type of its elem).
    // An Iterator_type (type of its iterators). It must also ensure begin()
    // and end() exist and that they return iterators. Finally, the
    // Iterator_type really must be an input_iterator with elements of the
    // same type as the elements of S.
    //
    // The hardest concepts to define are the ones that represent fundamental
    // language concepts. Consequently, it's best to use a set from the
    // standard library.
    // 7.2.4 Definition of Concepts

    // 7.3 Generic Programming
    // Generic programming in C++ centers on the idea of abstracting from
    // concrete, efficient algorithms to obtain generic algorithms that
    // can be combined with different data representations to produce
    // a wide variety of useful software.
    //
    // Abstractions representing the fundamental operations and data structs
    // are *concepts*; they appear as requirements for template parameters.
    // 7.3 Generic Programming

    // 7.3.1 Use of Concepts
    // Concepts are fundamental and discovered more than they are designed.
    // For example, general mathematical concepts such as integers, floating
    // point types and sequences.
    // For basic use consider the concept Regular. A type is regular when
    // it behaves much like an int or vector.
    //      They can be default constructed.
    //      Copied using a constructor or an assignment.
    //      Comparable using == and !=.
    //      Doesn't suffer technical problems from severe programming tricks.
    //
    // A string is also another example of a regular type. They are
    // StrictTotallyOrdered. That is, two strings can be compared using
    // <, <=, >, >= with the appropriate semantics.
    //
    // Concepts aren't just a syntactic notion, they are fundamentally about
    // semantics. (e.g., don't define + to divide; doesn't match requirements
    // for any reasonable number).
    // 7.3.1 Use of Concepts

    // 7.3.2 Abstraction Using Templates
    // Abstractions are grown from concrete examples. It's not a good idea to
    // prepare to abstract for every conceivable need.
    //
    // Start with one concrete example, then try to eliminate inessential
    // details.
    // 7.3.2 Abstraction Using Templates

    // 7.4 Variadic Templates
    // A template can be defined to take an arbitrary number of args.
    // Such a template is called a *variadic template*.
    //      print("first: ", 1, 2.2);
    //      print("\nsecond: ", 0.2, 'c');
    // 7.4 Variadic Templates
}
