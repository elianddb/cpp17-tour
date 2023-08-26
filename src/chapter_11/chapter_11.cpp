#include "shape.hpp"

#include <iostream>
#include <string>
#include <vector>

// 11.2 `vector`
struct Entry
{
    std::string name {};
    int number {};
};

std::ostream& operator<<(std::ostream& out, const Entry& e)
{
    out << '(' << e.name << ", " << e.number << ')';
    return out;
}

std::istream& operator>>(std::istream& in, Entry& e)
{
    char buf;
    if (std::cin >> buf && buf == '{' && std::cin >> buf && buf == '"')
    {
        std::string name {};
        while (in.get(buf) && buf != '"')
            name += buf;

        if (std::cin >> buf && buf == ',')
        {
            int num {};
            if (std::cin >> num >> buf && buf == '}')
            {
                e = {name, num};
                return in;
            }
        }
    }

    in.setstate(std::ios_base::failbit);
    return in;
}
// 11.2 `vector`

int main()
{
    // 11.2 `vector`
    // std::vector is one of the most useful std lib containers.
    // A sequence of elem of a given type, contiguously stored in mem.
    // Typical implementations of std::vector involve a handle holding 
    // ptrs to the first elem, one-past-the-last elem, and one-past-the-last
    // allocated space. It also holds an allocator from which std::vector
    // can acquire and release mem.
    //      The default alloc uses new and delete to acquire and release elem.
    //
    // We can initialize std::vector with a set of vals of its elem type.
    std::vector<Entry> phoneBook {
        {"David Hume", 123456},
        {"Karl Hopper", 234567},
        {"Bertrand Arthur William Russell", 345678},
    };
    // Access the elem through subscripts `phoneBook[]`
    auto printBook = [](const std::vector<Entry>& book)
    {
        for (const auto& entry : book)
            std::cout << entry << '\n';
    };
    printBook(phoneBook);
    // The usual applies when it comes to these types of containers. Index
    // starts at 0. Use the member func size() to get the given num of elem.
    //
    // Giving an initialization:
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<std::string> v2;
    // size of 23, init all elem with default val
    std::vector<DDB::Shape*> v3(23);
    std::vector<double> v4(32, 9.9); // size 32, init all elem 9.9
    // The initial size of std::vector can be changed with using `push_back()`
    // member func.
    v1.push_back(4);
    // To read continuous input into phone_book until eof is reached or error
    // do:
    for (Entry e; std::cin >> e;)
        phoneBook.push_back(e);
    // The std lib has members capacity(), reserve(), and push_back(). reserve()
    // makes room for more elem. It may have to allocate new mem when it does.
    // capacity() refers to allocated available spaces for elem.
    // With these funcs the implementation of push_back() is made trivial:
    // template <typaname T>
    // void Vector<T>::push_back(const T& t)
    // {
    //      if (capacity() < size() + 1)
    //          reserve(size()==0?8:2*size());
    //      new(space) T{t};
    //      ++space;
    // }
    // You can also copy vectors using the assignment operator
    //      std::vector v1 = v2;
    // 11.2 `vector`

    // 11.2.1 Elements
    // Just about any type qualifies as an elem type for std::vector. When
    // you insert a new elem, its value is copied into the container. When
    // dealing with class hierarchies that rely on `virtual` funcs for
    // polymorphic behavior make sure to use pointers.
    //      std::vector<Shape*> vs {};
    //      std::vector<std::unique_ptr<Shape>> vsu {};
    // 11.2.1 Elements
    return 0;
}
