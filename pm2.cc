#include <iostream>

void f(int (*a)[2]) {
    std::cout<<(*a)[1]<<std::endl;
}

int main() {
    int a[][2] = {{1,2},{3,4},{5,6}};
    f(a+1);
}
