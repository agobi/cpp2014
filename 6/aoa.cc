void f(int (*t)[2])
{
}

int main()
{
    int aoa[][2] = { {1, 2}, {3, 4}, {5, 6} };

    int (*t)[2] = aoa;
    //int *t[2] // (int *) t[2]

    int *p = aoa[2];
    int **t = new int *[3];
    for(int i=0; i<3; ++i)
        t[i] = aoa[i];
}
