#include "complex.hpp"

int main()
{
    // When we refer to the representation, we're talking about the data
    // members of a class.

    // 4.2 Concrete Types
    // Concrete types behave just like built-in types but have their own
    // semantics and sets of operations.
    // For example, vectors and strings are much like built-in arrays, except
    // they are better behaved.
    // The defining characteristic of a concrete type is that its
    // representation is part of its definition. In other words, the way the
    // object is represented in memory is fixed.
    // Therefore, if the representation changes, a user must recompile.
    // To increase flexibility, a concrete type can keep major parts of its
    // representation on free store (dynamic memory, heap) and access them
    // through the part stored in the class object itself.
    // Unlike abstract types concrete types can be instantiated.
    // 4.2 Concrete Types

    // 4.2.1 An Arithmetic Type
    // Simple operations in the complex class remain efficient so they can be
    // inline. That means the generated machine code will be implemented
    // without function calls.
    const DDB::Complex cz {1, 2};
    DDB::Complex complex {};
    double x = cz.real();
    // Functions defined in a class are inline by default. It is possible to
    // explicitly request an inline by preceding a function declaration
    // with the `inline` keyword. Here DDB::Complex is carefully implemented
    // to do appropriate inlining.
    // 
    // A constructor invoked without an argument is called a *default 
    // constructor*. It eliminates the possibility of uninitialized variables
    // of the user-defined type.
    // 4.2.1 An Arithmetic Type
}
