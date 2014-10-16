int & inc(int &i) { i+=1; return i; }
int succ(const int &i) { return i+1; }
void safe_delete(int *&p) { delete p; p = 0; }

int /*&*/ inc2(int &i) { // & -> dangling
    int j = i;
    i+=1;
    return j;
}

int main() {
    int i;
    int *pi = &i;
    int &ri = i;

    int j=42;
    *pi = j; ri = j; // kb. u.a.
    pi = &j; pi = 0; // Ilyen nincs referencian

    inc(i);
    //inc(2); l-value kell referencianak

    succ(2); // const ref lehet temporary

    int *p = new int;
    delete p;
    p=0;

    int **pd;
    {
        int *p = new int;
        pd = &p;
    }
    //pd dangling

    // pointert referencia szerint adunk at
    // ha nem referencia, akkor nem tudjuk atallitani, hogy hova mutat
    safe_delete(p);

    return 0;
}
