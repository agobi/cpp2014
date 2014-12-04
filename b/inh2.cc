#include <iostream>

class A
{
public:
    void f() {std::cout<<"A::f"<<std::endl;}
    virtual void g(A*) {std::cout<<"A::A"<<std::endl;}

};

class B: public A
{
public:
    void f() {std::cout<<"B::f"<<std::endl;}
    void g(A*) {std::cout<<"B::A"<<std::endl;}
    void g(B*) {std::cout<<"B::B"<<std::endl;}
};

int main()
{
    A * aa = new A;
    A * ab = new B;
    B * bb = new B;
    aa->f(); ab->f(); bb->f();

    aa->g(aa); aa->g(ab); aa->g(bb);
    ab->g(aa); ab->g(ab); ab->g(bb);
    bb->g(aa); bb->g(ab); bb->g(bb);
}
