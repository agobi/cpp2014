#include <iostream>

typedef int vector[3];

void f(vector t) // int * // int [3] // int [666] // int []
{
    t[2] = 4;
    std::cout<<sizeof(t)<<std::endl;
}

void g(int (&t)[3]) // vector &t
{
    std::cout<<sizeof(t)<<std::endl;
}

int main()
{
    vector t = {1,2,3};
    int s[] = {1,2};
    f(t); f(s);
    g(t); //g(s);
}
