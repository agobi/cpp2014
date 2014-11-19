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

    int back()
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

    bool empty()
    {
        return !_back;
    }
};

void
print_list(linkedlist l)
{
    while(!l.empty())
    {
        std::cout<<l.back()<<std::endl;
        l.pop_back();
    }
}

int main() {
    linkedlist l;

    int i;
    while(std::cin>>i)
    {
        l.push_back(i);
    }

    linkedlist l2(l); // l2 = l;
    print_list(l);

    l = l;
    l2 = l;
    print_list(l2);
}
