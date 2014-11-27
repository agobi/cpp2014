#include <iostream>
#include <algorithm>
#include <iterator>

struct sum
{
    sum() { s = 0; }
    void operator () (int a)
    {
        s += a;
    }
    int s;
};

int main()
{
    sum s = std::for_each(std::istream_iterator<int>(std::cin),
                 std::istream_iterator<int>(),
                 sum());

    std::cout<<s.s<<std::endl;
}
