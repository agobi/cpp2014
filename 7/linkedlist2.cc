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

    link *_front, *_back;

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

    int back()
    {
        return _back->value;
    }

    bool empty()
    {
        return !_front;
    }
};

void print_list(linkedlist l)
{
    while(!l.empty())
    {
        std::cout<<l.back()<<std::endl;
        l.pop_back();
    }
}

int main()
{
    linkedlist l, l2;

    int i;
    while(std::cin>>i)
        l.push_back(i);

    l = l;
    l2 = l;

    print_list(l);
    print_list(l2);
    print_list(l);
    print_list(l2);
}
