#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED
#include <stdexcept>

namespace DDB
{
    class Vector
    {
    public:
        Vector(int sz);
        double& operator[](int i) const;
        [[nodiscard]] int size() const;
    private:
        double* elem{};
        int sz;
        static constexpr int validateSize(int);
    };

    constexpr int Vector::validateSize(const int sz)
    {
        if (sz < 0)
            throw std::length_error("Vector::validateSize() negative size");
        return sz;
    }
}
#endif
