#include <iostream>
void g() { std::cout<<"a"; }
namespace f {
    void g() { std::cout<<"b"; }
    namespace q {
        // ::g() <- global namespace
        void h() { ::g(); g(); }
    }
}

// anonymous namespace -> translation unit local
namespace { int i; }

int main() {
//    g();
//    f::g();
    f::q::h();
}
