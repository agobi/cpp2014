#include <iostream>

typedef int vector[3];

void f(vector x) // int x[6] // int x[] // int *x
{
    x[2] = 3;
    std::cout<<sizeof(x)<<std::endl;
}

void g(int (&x)[3]) // vector &
{
    std::cout<<sizeof(x)<<std::endl;
}

int main()
{
    vector t = {1, 2, 3};
    int s[] = {1,2};
    f(t); f(s);
    g(t); // g(s);
    for(int i=0; i<sizeof(t)/sizeof(*t); ++i)
        std::cout<<t[i]<<std::endl;
}
