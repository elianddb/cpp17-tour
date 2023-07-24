int main()
{
   // 6.2 Parameterized Types
   // template <typename T>
   // The prefix makes a T parameter of the declaration it prefixes.
   // Using class instead of typename is equivalent. (template <typename t>
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
   // 6.2 Parameterized Types     
}
