int &f()
{
    static int x;
    return x;
}

int main()
{
    f() = 2;
}
