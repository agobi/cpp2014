#include <iostream>

int succ(const int &i) { return i+1; }
// callzero :: (Int -> Int) -> Int
// callzero f = f 0
int callzero(int (*f)(const int &)) { return f(0); }

int main() {
    int *p;
    int **pp = &p;
    p = new int;
    delete p; // vagy delete *pp
    // itt a p "dangling", *p nem definialt
    p = 0;
    delete p; // ezt szabad



    int (*f)(const int &) = succ; // fvpointer
    std::cout<<f(2)<<std::endl;
    std::cout<<callzero(f)<<std::endl;

    // pl qsort a libc-ben (quicksort implementacio
    //   void
    //   qsort(void *base, size_t nel, size_t width,
    //         int (*compar)(const void *, const void *));


    return 0;
}
