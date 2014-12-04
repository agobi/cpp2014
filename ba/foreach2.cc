#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

struct sum
{
    sum(int &s): ss(s)
    {}

    void operator () (int a)
    {
        ss += a;
    }

    int &ss;
};

int main()
{
    int ss = 0;

    std::for_each(std::istream_iterator<int>(std::cin),
                 std::istream_iterator<int>(),
                 sum(ss));

    /*
    std::for_each(std::istream_iterator<int>(std::cin),
                 std::istream_iterator<int>(),
                 [&ss](int a){ ss += a; });

    vector<int> v;
    for(int &a : v)
        ++a;

    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
    {
        int &a = *it;
        ...
    }
                 */

    std::cout<<ss<<std::endl;
}
