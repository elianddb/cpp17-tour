int main()
{
    // 5.1.1 Essential Operations
    // The construction of objects play a key role in many designs.
    //
    // Constructors, destructors, and copy and move operators for a type are
    // not logically separate. We must define them as a matched set or suffer
    // logical or performance problems.
    //
    // For example take a class X. It has a destructor that a performs
    // nontrivial task such as free-store deallocation or lock release (mutex).
    // The class is likely to need a full complement of functions.
    //      X(Sometype); // "ordinary constructor"
    //      X(); // default constructor
    //      X(const X&); // copy constructor
    //      X(X&&); // move constructor
    //      // copy assignment: clean up target and copy arg
    //      X& operator=(const X&);
    //      // move assignment: clean up target and move arg
    //      X& operator=(X&&);
    //      ~X(); // destructor: clean up
    //
    // There are five situations in which an object can be copied or moved:
    //      As a source of assignment.
    //      As an object initializer.
    //      As a function argument.
    //      As a function return value.
    //      As an exception.
    //
    // An assignment uses either a copy or move assignment operator. The other
    // cases use a copy or move constructor. Often, however, copy or move
    // constructor invocations are often optimized away by constructing the
    // object used to initialize right in the target object.
    //      X make(SomeType);
    //      X x {make(val)};
    // The compiler here will directly construct the object in x from make();
    // thus eliminating ("eliding") a copy.
    //
    // In addition to the initialization of named objects/objects on the free
    // free store. Constructors are also used to initialize temporary objects
    // and to implement an explicit type conversion.
    // Except for the "ordinary constructor", these special member functions
    // will be generated by the compiler as needed. To be explicit about
    // generating default implementation use:
    //      Y(const Y&) = default; // default copy constructor
    //      Y(Y&&) = default; // default move
    // If you are explicit about some defaults, other default implementations
    // will not be generated
    //
    // When a class has a pointer member, it's a good idea to be explicit about
    // copy and move operations.
    //
    // A good rule of thumb (sometimes called the "rule of zero") is to either
    // define all essential operations or none (using default for all).
    //      struct Z
    //      {
    //          Vector v;
    //          std::string s;
    //      };
    //
    //      Z z1 {}; // default initialize z1.v and z1.s
    //      Z z2 {z1}; // default copy z1.v and z1.s
    // The compiler synthesizes the correct memberwise construction,
    // destructor, and copy and move as needed.
    //
    // To complement =default we have =delete which indicates an operation
    // should not be generated.
    //      Shape(const Shape&) = delete;
    //      Shape& operator=(const Shape&) = delete;
    // Now any assignment operation would have an error since copy is deleted.
    // 5.1.1 Essential Operations

    // 5.1.2 Conversions
    // 
    // 5.1.2 Conversions
}
