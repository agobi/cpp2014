#include <iostream>
#include <iomanip>

int main() {
    std::cout<<std::setfill('0')<<std::setw(4)<<std::setbase(16)<<255;
}
