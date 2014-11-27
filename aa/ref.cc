#include <iostream>

static int a = 2;

int &f()
{
    int a = 2;
    return a;
}

int &g()
{
    static int a = 2;
    return a;
}

int main()
{
    int &b = f();
    int &c = g();
    {
        int a[] = {1,2,3,4,5,6,7,8,9};
    }
    std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
    g()=42;
    std::cout<<c<<std::endl;
}
