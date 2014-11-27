#include <iterator>
#include <iostream>
#include <algorithm>

bool even(int i)
{
    return !(i%2);
}

struct modulo
{
    modulo(int q, int r)
    { _q = q; _r = r; }

    bool operator () (int a) const
    {
        return (a%_q)==_r;
    }

private:
    int _q, _r;
};

int main()
{
    modulo m(2,0);
    m(1);

    std::cout<<std::count_if(
                  std::istream_iterator<int>(std::cin),
                  std::istream_iterator<int>(),
                  modulo(2,0))<<std::endl;
}
