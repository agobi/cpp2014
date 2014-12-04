#include <iostream>
#include <vector>
#include <algorithm>

struct sikidom
{
    virtual double terulet() const = 0;
    virtual ~sikidom() {}
};

struct sokszog: sikidom
{
    virtual double belsoszogekosszege() const = 0;
};

struct negyzet: sokszog
{
    negyzet(double _a): a(_a) {}
    double terulet() const { return a*a; }
    double belsoszogekosszege() const { return 360.0; };
    const double a;
};

struct kor: sikidom
{
    kor(double _r): r(_r) {}
    double terulet() const { return 3.1415*r*r; }
    const double r;
};

struct tsort
{
    bool operator () (const sikidom* lhs, const sikidom* rhs)
    {
        return lhs->terulet() < rhs->terulet();
    }
};

struct sprint
{
    void operator () (const sikidom* o)
    {
        std::cout<<o->terulet()<<std::endl;
    }
};

int main()
{
    negyzet n1(2);
    kor k1(2);
    //sikidom s; // abstract class

    sikidom *s = new negyzet(3);
    //sikidom s2 = negyzet(4); // nem megy
    sikidom &s2 = n1;

    std::cout<<n1.terulet()<<" "<<
        static_cast<sikidom&>(n1).terulet()<<std::endl;

    std::vector<sikidom*> v;
    v.push_back(&n1);
    v.push_back(&k1);
    std::sort(v.begin(), v.end(), tsort());
    std::for_each(v.begin(), v.end(), sprint());

    delete s;
}
