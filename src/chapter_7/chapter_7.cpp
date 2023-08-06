#include <iostream>

// 7.2 Concepts (C++20)
// sum() from 6.3.1
template <typename Seq, typename Num>
Num sum(Seq s, Num v)
{
    for (const auto& x : s)
        v += x;
    return v;
}
// 7.2 Concepts (C++20)


int main()
{
    std::cout << "Chapter 7\n";
    // 7.2 Concepts (C++20)
    // 7.2 Concepts (C++20)
}
