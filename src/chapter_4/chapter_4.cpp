#include <iostream>

#include "complex.hpp"
#include "vector.hpp"

// 4.3 Abstract Types
// This class represents a pure interface to containers defined later.
class Container
{
public:
    // *virtual* means "may be defined later", these are virtual functions.
    // = 0 indicates *pure virtual*; classes derived from Container must
    // define that specific function.
    virtual double& operator[](int) const = 0;
    virtual int size() const = 0;
    // Container does not have a constructor but it does have a virtual
    // destructor. Derived classes can provide an implementations for it.
    virtual ~Container() {}
};

// ": public Container" indicates VectorContainer is derived from the base
// class Container. We'd say Container is the *superclass* and VectorContainer
// is the *subclass*. This is referred to as *inheritance*
class VectorContainer : public Container
{
public:
    VectorContainer(int s) : v(s) {}
    // explicit use of *override* allows the compiler to catch mistakes.
    ~VectorContainer() override {}
    double& operator[](int i) const override { return v[i]; }
    int size() const override { return v.size(); }
private:
    DDB::V2::Vector v;
};
// 4.3 Abstract Types

// 4.2.1 An Arithmetic Type
void test(DDB::Complex z)
{
    DDB::Complex a {2.3};
    DDB::Complex b {1 / a};
    DDB::Complex c {a + z * DDB::Complex{1, 2.3}};

    if (c != b)
        c = -(b / a) + 2 * b;
}
// 4.2.1 An Arithmetic Type

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
    // An arithmetic-type defines a conventional set of operators and remains
    // efficient for inline use for those particular operator overloaded
    // functions.
    //
    // Simple operations in the complex class remain efficient so they can be
    // inline. That means the generated machine code will be implemented
    // without function calls.
    const DDB::Complex cz {1, 2};
    DDB::Complex complex {};
    double x = cz.real();
    test(cz);
    // Functions defined in a class are inline by default. It is possible to
    // explicitly request an inline by preceding a function declaration
    // with the `inline` keyword. Here DDB::Complex is carefully implemented
    // to do appropriate inlining.
    // 
    // A constructor invoked without an argument is called a *default
    // constructor*. It eliminates the possibility of uninitialized variables
    // of the user-defined type.
    //
    // Syntax for overloaded operators is fixed by the language, so you can't
    // define a unary / operator. Also, you can redefine the meaning of
    // existing operators for built-in types.
    // 4.2.1 An Arithmetic Type

    // 4.2.2 A Container
    // Our Vector type comes with set of useful features, but it has a fatal
    // flaw. It allocates elements using new but never deallocates them.
    // Although C++ defines an interface for a garbage collection, it doesn't
    // guarantee that it will make unused memory available for new objects.
    // Therefore we need a mechanism to ensure that the memory allocated by
    // the constructor is deallocated; the mechanism is a destructor.
    //
    // The technique of acquiring resources in a constructor and releasing
    // them in a destructor is known as *Resource Acquisition Is
    // Initialization* or *RAII*. It buries allocation in general code in
    // the implementation of well-behaved abstractions.
    // 4.2.2 A Container

    // 4.2.3 Initializing Containers
    // Containers exist to hold elements, so there's need to be a convenient
    // way of getting elements into them. Vector provides the ability to
    // create an appropriate number of elements and then assign to them, but
    // there are typically other more elegant ways.
    //
    // *initializer-list constructor*: Initialize with a list of elements.
    // push_back(): Add a new element at the end of the sequence.
    //
    // We'll focus on initializer lists which are defined by {}-list (e.g.,
    // {1,2,3,4}).
    DDB::V2::Vector v1 = {1, 2, 3, 4}; // contains 4 elements
    for (int i {}; i < v1.size(); ++i)
        std::cout << v1[i] << '\n';
    // 4.2.3 Initializing Containers

    // 4.3 Abstract Types
    // An abstract type insulates a user of implementation details. It gives up
    // genuine local variables and decouples the interface.
    //
    // Since the representation of an abstract type is not known, objects are
    // allocated on free store and accessed through references and pointers.
    //
    // Container c; // No objects from the abstract class.
    // // Container is an interface for VectorContainer object.
    Container* p = new VectorContainer {10};
    // Since the abstract class can take in any kind of object, a function arg
    // using the abstract type can be blind to the implementation of the 
    // subclass container and still use it the Container functions.
    //
    // A class with a pure virtual function is called an *abstract class*.
    // A class that provides the interface to a variety of other classes is
    // often a *polymorphic type*.
    // 4.3 Abstract Types
}
