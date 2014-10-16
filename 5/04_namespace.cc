#include <iostream>

void g() { std::cout<<"a"; }
namespace f {
    void g() { std::cout<<"b"; }
    namespace q {
        // ::g() <- global namespace
        void h() { ::g(); g(); }
    }
}

using f::q::h;

// anonymous namespace -> translation unit local
namespace { int i; }

namespace std {
}

int main() {
//    g();
//    f::g();
    f::q::h();
    h();

    std::operator << (std::cout, "almafa");

    std::cout<<"almafa"<<std::endl;
}
