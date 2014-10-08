// mainben kezdodik :)

/* Semmit sem csinal */
void square1(int i) {
    i*=i;
}

/* Ronda */
void square2(int *i) {
    (*i) *= (*i);
}

int main() {
    int i = 2;
    int *pi = &i; // cimkepzes
    int j = *pi;  // dereferalas
    // 3 csillag op:
    //  - szorzas
    //  - dereferalas
    //  - tipus

    // j == 2
    i=3;
    // j == 2, *pi == 3
    *pi = 4;
    // j == 2, i == 4

    pi = &j;
    *pi = 5;
    // j == 5, i == 4

    square1(i);
    square2(&i);

    const int * cip = &i;
    cip = &j;

    int * const icp = &i;
    // int const  == const int
    *icp = j;

    int const * const cicp = &i;

}
