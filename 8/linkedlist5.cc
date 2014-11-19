#include <iostream>
// https://github.com/agobi/cpp2014

class linkedlist
{
private:

    struct link
    {
        int value;
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

    void push_back(int value)
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

    const int &back() const
    {
        return _back->value;
    }

    int &back()
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
        const_iterator(link *p) { _p = p; }

        bool operator != (const const_iterator &rhs) const
        {
            return _p != rhs._p;
        }

        const int &
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
        iterator(link *p) { _p = p; }

        bool operator != (const iterator &rhs) const
        {
            return _p != rhs._p;
        }

        int &
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

void print_list(linkedlist::const_iterator first, linkedlist::const_iterator last)
{
    for(linkedlist::const_iterator p=first; p!=last; ++p)
        std::cout<<*p<<std::endl;
}

int main()
{
    linkedlist l;
    int i;
    while(std::cin>>i)
        l.push_back(i);

    for(linkedlist::iterator p=l.begin(); p!=l.end(); ++p)
        ++(*p);

    const linkedlist &rl = l;
    //++*(rl.begin());

    l.back() += 8;
    print_list(rl.begin(), rl.end());
}
