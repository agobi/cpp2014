#include <iostream>

void f(int x[][2]) // int (*x)[2]
{ }

void g(int **)
{ }

int main()
{
    int i;
    int aoa[][2] = { {1, 2}, {3, 4}, {5, 6} };
    int *aop[] = { &i, nullptr };

    int *x[2];   // array of pointers
    int (*y)[2]; // pointer to array
    y=aoa;
    int *p = aoa[1];
    int **pp = new int *[3];
    for (int i=0; i<3; ++i)
        pp[i] = aoa[i];

}
