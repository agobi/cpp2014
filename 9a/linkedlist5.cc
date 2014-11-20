#include <iostream>

struct linkedlist
{
private:
    struct link
    {
        int value;
        link *prev, *next;
    };

    link *_front, *_back;
public:

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

    int &back()
    {
        return _back->value;
    }

    const int &back() const
    {
        return _back->value;
    }

    void push_back(int value)
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

    class iterator
    {
    public:
        iterator(link *p) { _p=p; };

        int &
        operator *()
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
        operator !=(const iterator &rhs)
        {
            return _p != rhs._p;
        }

    private:
        link *_p;
    };

    class const_iterator
    {
    public:
        const_iterator(const link *p) { _p=p; };

        const int &
        operator *()
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
        operator !=(const const_iterator &rhs)
        {
            return _p != rhs._p;
        }

    private:
        const link *_p;
    };

    iterator begin()
    {
        return iterator(_front);
    }

    const_iterator begin() const
    {
        return const_iterator(_front);
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

void
print_list(const linkedlist &l)
{
    for(linkedlist::const_iterator p = l.begin(); p != l.end(); ++p)
    {
        // *p = 42; // YES!
        std::cout<<*p<<std::endl;
    }
}

int main() {
    linkedlist l;

    int a[] = {1,2,3,4};
    for(int *p = a; p != a+sizeof(a)/sizeof(*a); ++p)
        std::cout<<*p<<std::endl;

    int i;
    while(std::cin>>i)
        l.push_back(i);

    for(linkedlist::iterator p = l.begin(); p != l.end(); ++p)
        *p = 42;

    const linkedlist::iterator p=l.begin();
    //*p = 42;
    //++p;


    l.back() += 6;
    print_list(l);
}
