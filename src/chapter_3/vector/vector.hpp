#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <initializer_list>

namespace DDB
{
    inline namespace V1
    {
        class Vector
        {
        public:
            Vector(int sz);
            double& operator[](int i) const;
            [[nodiscard]] int size() const;
            static int validateSize(int);
        private:
            double* elem {};
            int sz {};
        };
    }

    namespace V2
    {
        class Vector
        {
        public:
            Vector(int s) : elem {new double[s]}, sz {s}
            {
                for (int i {}; i != s; ++i)
                {
                    elem[i] = 0;
                }
            }
            Vector(std::initializer_list<double> list);

            // plain *delete* removes an individual object from memory
            // *delete[]* removes an entire array
            ~Vector() { delete[] elem; } // release resources

            double& operator[] (int i) const;
            int size() const;
        private:
            double* elem;
            int sz;
        };
    }

    namespace V3
    {
        class Vector
        {
        public:
            explicit Vector(const int s) : elem {new double[s]}, sz {s} {}
            ~Vector() { delete[] elem; }
            Vector(const Vector& a);
            Vector& operator=(const Vector& a);
            Vector(Vector&& a) noexcept;
            Vector& operator=(Vector&& a) noexcept;
            double& operator[](const int i) { return elem[i]; }
            const double& operator[](const int i) const { return elem[i]; }
            [[nodiscard]] int size() const { return sz; }
        private:
            double* elem {};
            int sz {};
        };
    }

    namespace V4
    {
        template <typename T> // type parameterized class
        class Vector
        {
        public:
            explicit Vector(int s);
            Vector(Vector& v);
            Vector(Vector&& v) noexcept;
            ~Vector() { delete[] elem; }
            Vector& operator=(Vector& v);
            Vector& operator=(Vector&& v) noexcept;
            T& operator[](int i) const;
            int size();
        private:
            T* elem {};
            int sz {};
        };
    }
}
#endif
