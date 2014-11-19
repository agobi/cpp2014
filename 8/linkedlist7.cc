#include <iostream>
#include <vector>

template<typename T>
class linkedlist
{
private:

    struct link
    {
        T value;
        link *prev, *next;
    };

    link * _front, *_back;

public:
    linkedlist()
    {
        this->_front = this->_back = nullptr;
    }

    linkedlist(const linkedlist &o)
    {
        this->_front = this->_back = nullptr;

        for(link *p = o._front; p != 0; p = p->next)
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
        {
            linkedlist tmp(rhs);
            tmp.swap(*this);
        }

        return *this;
    }

    void swap(linkedlist &rhs)
    {
        std::swap(_front, rhs._front);
        std::swap(_back, rhs._back);
    }

    void push_back(const T& value)
    {
        link *p = new link;
        p->prev = this->_back;
        p->next = 0;
        p->value = value;

        if(this->_back)
            this->_back->next = p;
        else
            this->_front = p;
        this->_back = p;
    }

    void pop_back()
    {
        link *p = _back;
        _back = _back->prev;
        delete p;

        if(_back)
            _back->next=0;
        else
            _front=0;
    }

    const T &back() const
    {
        return _back->value;
    }

    T &back()
    {
        return _back->value;
    }

    bool empty() const
    {
        return !_front;
    }

    class const_iterator
    {
    public:
        typedef T value_type;

        const_iterator(link *p) { _p = p; }

        bool operator != (const const_iterator &rhs) const
        {
            return _p != rhs._p;
        }

        const T &
        operator * () const
        {
            return _p -> value;
        }

        const_iterator &
        operator ++ ()
        {
            _p = _p -> next;
            return *this;
        }

    private:
        const link *_p;
    };

    class iterator
    {
    public:
        typedef T value_type;

        iterator(link *p) { _p = p; }

        bool operator != (const iterator &rhs) const
        {
            return _p != rhs._p;
        }

        T &
        operator * () const
        {
            return _p -> value;
        }

        iterator & operator ++ ()
        {
            _p = _p -> next;
            return *this;
        }

        operator const_iterator () const
        {
            return _p;
        }

    private:
        link *_p;
    };

    typedef T value_type;

    iterator
    begin()
    {
        return _front;
    }

    const_iterator
    begin() const
    {
        return _front;
    }

    iterator
    end()
    {
        return 0;
    }

    const_iterator
    end() const
    {
        return 0;
    }
};

void
print_list(linkedlist<int>::const_iterator first,
           linkedlist<int>::const_iterator last)
{
    for(linkedlist<int>::const_iterator p=first; p!=last; ++p)
        std::cout<<*p<<std::endl;
}

//linkedlist<int>::iterator
template<typename IT>
IT
min2(IT b, IT e)
{
    if(b!=e)
    {
        IT ret = b;
        typename IT::value_type v = *b;

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
    linkedlist<int> l;
    int i;
    while(std::cin>>i)
        l.push_back(i);
    std::cout<<*min2(l.begin(), l.end())<<std::endl;

//    int a[] = {5,6,2,3,9};
//    std::cout<<*min2(a, a+sizeof(a)/sizeof(*a))<<std::endl;

    std::vector<int> q;
    q.push_back(3); q.push_back(1); q.push_back(2);
    std::cout<<*min2(q.begin(), q.end())<<std::endl;
}
