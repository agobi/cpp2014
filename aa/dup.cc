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
    std::vector<int> v;
    /*
    std::back_insert_iterator<std::vector<int> > ins = std::back_inserter(v);

    ++(*ins) = 2;
    ++(*ins) = 3;
    ++(*ins) = 9;
    */

    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(v));

    std::cout<<(
                 dup(v.begin(), v.end()) ? "van" : "nincs"
             )<<std::endl;

    // vvvv nem definialt!
    v.reserve(v.size()*2);
    std::copy(v.begin(), v.end(), std::back_inserter(v));
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
}
