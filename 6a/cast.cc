int main() {
    const long x=2;

    (const double)x; static_cast<double>(x);
    (long)x; const_cast<long&>(x);
    (const int *)x; reinterpret_cast<const int *>(x);
}
