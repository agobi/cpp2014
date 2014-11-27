#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
bool
dup(T begin, T end)
{
    for(; begin!=end; ++begin)
    {
        T j = begin;
        for(++j; j!=end; ++j)
            if(*j == *begin)
                return true;
    }
    return false;
}

int main()
{
    std::cout<<(dup(std::istream_iterator<int>(std::cin),
                    std::istream_iterator<int>()) ? "van" : "nincs"
               )<<std::endl;
}
