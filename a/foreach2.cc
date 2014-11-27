#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

struct sum
{
    sum(int &s): _s(s)
    {}

    void operator () (int a)
    {
        _s += a;
    }

    int &_s;
};

int main()
{
    int ss = 0;
/*    std::for_each(std::istream_iterator<int>(std::cin),
                 std::istream_iterator<int>(),
                 sum(ss));*/

    std::for_each(std::istream_iterator<int>(std::cin),
                 std::istream_iterator<int>(),
                 [&ss](int a){ ss+=a; });

    std::vector<int> v = {2,3,4,5};
    for(auto it=begin(v); it != end(v); ++it)
    {
        int &c = *it;
    }

    for(int &c : v)
    {
    }

    std::cout<<ss<<std::endl;
}
