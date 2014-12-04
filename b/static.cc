struct A {
    static int a;
};

struct singleton
{
private:
    static singleton * instance;
    singleton() {}

public:
    void f() {}
    static singleton* create()
    {
        if(instance==0)
            instance = new singelton;
        return instance;
    }
};
singleton * singleton::instance = 0;

int main()
{
    A a,b;
    a.a=2;
    std::cout<<b.a<<std::endl;
    std::cout<<A::a<<std::endl;
    singleton::create()->f();
};
