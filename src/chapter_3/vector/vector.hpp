#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
namespace DDB
{
    inline namespace Ch3
    {
        class Vector
        {
        public:
            Vector(int sz);
            double& operator[](int i) const;
            [[nodiscard]] int size() const;
            static int validateSize(int);
        private:
            double* elem{};
            int sz;
        };
    }

    namespace Ch4
    {
        class Vector
        {
        public:
            Vector(int s)
                : elem {new double[Ch3::Vector::validateSize(s)]}, sz {s}
            {
                for (int i {}; i != s; ++i)
                {
                    elem[i] = 0;
                }
            };
            ~Vector() { delete[] elem; } // release resources
            double operator[] (int i);
            int size() const;
        private:
            double* elem;
            int sz;
        };
    }
}
#endif
