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
    // 5.1.1 Essential Operations
}
