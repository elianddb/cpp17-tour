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
    // Sometimes implicit conversions is not ideal.
    //      Vector v1 = 7; // v1 has 7 elements
    // The way to avoid this problem is to say that only explicit conversion is
    // allowed.
    //      explicit Vector(int s);
    // Now the former errors out because of the use of implicit conversion.
    // Instead we'll use:
    //      Vector v1(7); // v1 has 7 elements
    // When it comes to conversions more types are like Vector. So use explicit
    // on single-arg constructors.
    // 5.1.2 Conversions

    // 5.1.3 Member Initializers
    // We can supply a default initializer called a *default member
    // initializer*.
    //      double m_re {};
    //      double m_im {}; // representation two doubles with default val 0
    // The default value is now used whenever a constructor does not provide a
    // value.
    //      Complex(double r) : re {r} {} // construct from one scalar
    // It helps us avoid leaving a member uninitialized.
    // 5.1.3 Member Initializers

    // 5.2 Copy and Move
    // By default user-defined/built-in objects can be copied. The default
    // meaning of copy is *memberwise copy*; copy each member.
    //      Complex z2 {z1};
    //      Complex z3;
    //      z2 = z3;
    // Now each variable holds the same value because both assignment and
    // initialization copied both members. For simple concrete types,
    // memberwise copy is often exactly the right semantics for copy.
    // For more sophisticated types however, memberwise copy is not
    // the right semantics for copy; for abstracts it almost never is.
    // 5.2 Copy and Move

    // 5.2.1 Copying Containers
    // When a class is a *resource handle* - responsible for an object accessed
    // through a pointer - the default memberwise copy function falls apart.
    // Default copy would leave a copy of a Vector referring to the same
    // elements as the original.
    //      Vector v2 {v1};
    //      v1[0] = 2; // v2[0] also equals 2 now!
    // Fortunately Vector's implementation of a destructor should provide a
    // hint to the compiler something is wrong. (Create V3 Implementation).
    //
    // A suitable definition of a copy constructor for Vector allocates
    // the space for the required number of elements and then copies the
    // elements of the param into it (same goes for copy assignment).
    // 5.2.1 Copying Containers

    // 5.2.2 Moving Containers
    // Copying can be costly for larger containers. We can avoid the cost
    // of copying using references, but we can't return a reference to
    // a local object as the result (local object prematurely gets destroyed).
    // So you can expect the result of a local variable to be copied.
    // This can get difficult with very large objects, involving the
    // initialization and copying of a very large object.
    //
    // We just want to get the result out of the function not a copy! (move)
    // You can state that intent in a move constructor/assignment:
    //      Vector(Vector&& a); // move constructor
    //      Vector& operator=(Vector&& a); // move assignment
    // The compiler will now choose the move constructor to implement faster
    // transfer of the return val of a function. (modify V3::Vector)
    //
    // The double ampersands represent *r-value reference*, which can bind to
    // an r-value. r-values are - to a first approximation - values you can't
    // assign to, like an integer returned from a function call.
    // Thus an r-value reference is is a reference to something that nobody
    // else can assign to. So, we can "safely" steal it's value.
    //
    // A move operation is used when an r-value reference is used as an
    // initializer or as the right-hand side of an assignment. After a move,
    // a moved-from object should be a in a state that allows a destructor
    // to be run.
    //
    // Where the programmer knows a value won't be used again, but the compiler
    // can't figure that out, std::move can be used.
    //      y = std::move(z);
    // std::move doesn't actually move anything. It returns a reference to its
    // arg from which we may move an r-value reference; kind of a cast.
    //
    // *Copy elision* - a zero-copy pass-by-value semantic, omits copy and move
    // constructors. So, move constructors are not invoked as much as one
    // would expect. On the other hand, in assignment it's not possible to
    // eliminate implicit copy or move operations from assignments. The use
    // of explicit move assignment can be critical for performance.
    // 5.2.2 Moving Containers

    // 5.3 Resource Management
    // Defining a constructor, copy operations, move operations, and a
    // destructor can provide a programmer full lifetime control of a
    // contained resource and cheap moves between scopes.
    //
    // Resource handles like Vector are superior alternative to direct
    // use of built-in pointers in many cases. unique_ptr in fact are
    // resource handles. In very much the same way we make new and
    // delete disappear from general code. Resource handles make pointers
    // disappear.
    //
    // A good resource management system handles all kinds of resources.
    // Leaks must be avoided in any long-running system, but excessive
    // resource retention can be almost as bad as a leak. Use resource
    // handles: let each resource have an owner in some scope and by
    // default be released at the end of its owners scope (RAII
    // [Resource Acquisition is Initialization]). This is integrated
    // with error handling in the form of exceptions.
    //
    // Smart pointer or move semantics can move resources from scope to scope.
    // Shared ownership can be represented with shared pointers. RAII is
    // pervasive in the C++ STL and the result is implicit resource management
    // that is invisible and in common use leads to lower resource retention
    // durations.
    // 5.3 Resource Management

    // 5.4 Conventional Operations
    // Good idea to conform to these.
    // Conventional meaning for operations assumed by programmers and
    // libraries:
    //      Comparisons: ==, !=, <, <=, >, and >=
    //      Container operations: size(), begin(), and end()
    //      Input and output operations: >> and <<
    //      swap()
    //      Hash functions: hash<>
    // 5.4 Conventional Operations

    // 5.4.1 Comparisons
    // The meaning of == and != is closely related to copying. After a copy,
    // copies should remain equal:
    //      X a = something;
    //      X b = a;
    //      assert(a == b);
    // When defining == also define != and make equal to !(a == b).
    // Same goes for > and >=, and < and <=.
    // 5.4.1 Comparisons

    // 5.4.2 Operations
    // Design containers with RAII in mind and model after standard-library
    // containers:
    //      size() -> number of elements.
    //      notion of sequences delimited by a pair of iterators
    // The iterator thing adds ability to use range for loops!
    // 5.4.2 Operations

    // 5.4.3 Input and Output Operations
    // For pairs of integers << means left-shift and >> means right-shift.
    // iostreams however use these as output and input operators. 
    // 5.4.3 Input and Output Operations

    // 5.4.4 User-Defined Literals
    //
    // 5.4.4 User-Defined Literals
}
