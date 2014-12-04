#include<iostream>

class A
{
private:
    int p;

protected:
    int pp;

public:
    virtual ~A() {}
};

class B: public A
{
public:
    int f() { return pp; }
};

int main()
{
    B b;
    A* a = new A;
    //std::cout<<b.p<<" "<<b.pp<<std::endl;

    B* bp = dynamic_cast<B*>(a);
    std::cout<<bp<<std::endl;
};
