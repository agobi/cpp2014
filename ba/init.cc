#include <iostream>

struct init
{
    init(): b(a), a(2) {}
    int a, b;
};

int main()
{
    init i;
    std::cout<<i.a<<" "<<i.b<<std::endl;
}
