#include <iostream>
#include <vector>

template <typename T>
struct value_type
{
    typedef typename T::value_type type;
};

template <typename T>
struct value_type<T*>
{
    typedef T type;
};



template<typename IT>
IT
min2(IT b, IT e)
{
    if(b!=e)
    {
        IT ret = b;
        typename value_type<IT>::type = *b;

        for(++b;b!=e;++b)
            if(v > *b)
                ret = b;

        return ret;
    }
    else
    {
        return e;
    }
}

int main()
{
    int a[] = {5,6,2,3,9};
    std::cout<<*min2(a, a+sizeof(a)/sizeof(*a))<<std::endl;

    std::vector<int> q;
    q.push_back(3); q.push_back(1); q.push_back(2);
    std::cout<<*min2(q.begin(), q.end())<<std::endl;
}
