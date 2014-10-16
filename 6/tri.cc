int main() {
    int **tri = new int *[3];
    for(int i=0; i<3; ++i)
        tri[i] = new int [i+1];

    for(int i=0; i<3; ++i)
        delete[] tri[i];
    delete[] tri;
}
