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
    // 11.2 `vector`
    return 0;
}
