#include <iostream>
#include <vector>
#include <algorithm>

struct sikidom
{
    virtual double terulet() const = 0;
    virtual ~sikidom() {}
};

struct negyzet: sikidom
{
    negyzet(double _a): a(_a) {}
    double terulet() const { return a*a; }
    const double a;
};

struct kor: sikidom
{
    kor(double _r): r(_r) {}
    double terulet() const { return 3.1415*r*r; }
    const double r;
};

/*
void pterulet(sikidom s)
{
    std::cout<<s.terulet()<<std::endl;
}
*/

void pterulet2(const sikidom &s)
{
    std::cout<<s.terulet()<<std::endl;
}

struct tsort
{
    bool operator () (const sikidom* lhs, const sikidom* rhs)
    {
        return lhs->terulet() < rhs->terulet();
    }
};

int main()
{
    negyzet n1(2);
    kor k1(2);
 //   sikidom s2(n1);
    sikidom &s = n1;

    std::cout<<n1.terulet()<<" "
        <<s.terulet()<<" "
//        <<s2.terulet()<<" "
        <<std::endl;

//    pterulet(n1);
    pterulet2(n1);

    std::vector<sikidom*> v;
    v.push_back(&n1);
    v.push_back(&k1);

    std::sort(v.begin(), v.end(), tsort());
}
