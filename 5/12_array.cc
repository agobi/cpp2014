#include <iostream>

int strlen2(const char *str) {
    const char *start = str;
    while(*(str++));
    return str - start - 1;
}

int main() {
    int a[] = {1,2,3,4};
    // u.a. int a[4] = {1,2,3,4};
    // a 4-et kikovetkezteti a fordito

    std::cout<<sizeof(a)<<" "<<4*sizeof(int)<<std::endl;
    for(int i=0; i<sizeof(a)/sizeof(a[0]); ++i)
        std::cout<<a[i]<<std::endl;

    // tombre mutato pointer? Automatikusan konvertalodik! int[] -> int *
    // vissza nem
    int *pa = a;
    std::cout<<pa[2]<<" "<<a[2]<<std::endl;

    // tomb elso elemere mutato pointer?
    std::cout<<a+1<<" "<<&(a[1])<<std::endl; // egesz pontosan: a[1] == *(a+1); a[1] szintaktikus cukor

    // tomb nulladik elemere mutato pointer?
    std::cout<<a<<" "<<pa<<std::endl;
    // *a == a[0] == *pa == pa[0]

    //  sizeof?
    std::cout<<sizeof(a)<<" "<<sizeof(pa)<<std::endl;

    std::cout<<strlen2("almafa")<<std::endl;
}
