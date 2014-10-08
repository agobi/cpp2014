#include <iostream>

// #define NULL ((void*)0)

void f(int) {std::cout<<"int"<<std::endl;}
void f(int *) {std::cout<<"int*"<<std::endl;}

int main() {
    /* nem jo, nem kovertalodik
    int *q = NULL;
    */

    // univerzalis pointer
    int *q = 0;

    // most mit hivok?
    f(0);

    // forditasi direktiva -std=c++11
    f(nullptr);
}
