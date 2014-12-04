#include <iostream>

struct A
{
    A() { std::cout<<"A"<<std::endl; }
    A(const A&r) { std::cout<<"B"<<std::endl; }
};

void f(A r)
{}

int main()
{
    //A p();
    A q;
    A r(q);
    f(r);
}
