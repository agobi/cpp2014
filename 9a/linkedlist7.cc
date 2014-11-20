#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
struct linkedlist
{
private:
    struct link
    {
        T value;
        link *prev, *next;
    };

    link *_front, *_back;

public:
    typedef T value_type;

    linkedlist()
    {
        _front = _back = 0;
    }

    linkedlist(const linkedlist& rhs)
    {
        _front = _back = 0;
        for(link *p = rhs._front; p; p = p->next)
            push_back(p->value);
    }

    ~linkedlist()
    {
        while(!empty())
            pop_back();
    }

    linkedlist &
    operator = (const linkedlist &rhs)
    {
        if(this != &rhs)
            linkedlist(rhs).swap(*this);

        return *this;
    }

    void swap(linkedlist &o)
    {
        std::swap(_front, o._front);
        std::swap(_back, o._back);
    }

    T &back()
    {
        return _back->value;
    }

    const T &back() const
    {
        return _back->value;
    }

    void push_back(T value)
    {
        link *p = new link;
        p->prev = _back;
        p->next = 0;
        p->value = value;

        if(_back)
            _back->next = p;
        else
            _front = p;
        _back = p;
    }

    void pop_back()
    {
        link *p = _back;
        _back = _back->prev;
        if(!_back) _front=0;
        delete p;
    }

    bool empty() const
    {
        return !_back;
    }

    class const_iterator
    {
    public:
        const_iterator(const link *p) { _p=p; };

        typedef T value_type;

        const T &
        operator *() const
        {
            return _p->value;
        }

        const_iterator&
        operator ++()
        {
            _p = _p -> next;
            return *this;
        }

        bool
        operator !=(const const_iterator &rhs) const
        {
            return _p != rhs._p;
        }

    private:
        const link *_p;
    };

    class iterator
    {
    public:
        typedef T value_type;

        iterator(link *p) { _p=p; };

        T &
        operator *() const
        {
            return _p->value;
        }

        iterator&
        operator ++()
        {
            _p = _p -> next;
            return *this;
        }

        bool
        operator !=(const iterator &rhs) const
        {
            return _p != rhs._p;
        }

        operator const_iterator () const
        {
            return _p;
        }

    private:
        link *_p;
    };

    iterator begin()
    {
        return _front;
    }

    const_iterator begin() const
    {
        return _front;
    }

    iterator end()
    {
        return 0;
    }

    const_iterator end() const
    {
        return 0;
    }
};

template<typename T>
void
print_list(T begin, T end)
{
    for(;begin != end; ++begin)
        std::cout<<*begin<<std::endl;
}

template<typename T>
T
min2(T begin, T end)
{
    if(begin != end)
    {
        T cmin(begin);

        typename T::value_type v;

        for(++begin; begin != end; ++begin)
            if(*begin < *cmin)
                cmin = begin;

        // for(A; B; C)
        //   ->
        // A;
        // while(B)
        // {
        //   ...
        //   C;
        // }

        return cmin;
    }
    else
        return end;
}

int main() {
    linkedlist<int> l;

    int a[] = {1,2,3,4};
    print_list(a, a+sizeof(a)/sizeof(*a));
    //std::cout<< *min2(a, a+sizeof(a)/sizeof(*a)) << std::endl;

    int i;
    while(std::cin>>i)
        l.push_back(i);

    print_list(l.begin(), l.end());
    std::cout<< *min2(l.begin(), l.end()) << std::endl;

    std::vector<int> q;
    q.push_back(4);
    q.push_back(9);
    q.push_back(2);
    q.push_back(3);

    std::cout<< *min2(q.begin(), q.end()) << std::endl;
}
