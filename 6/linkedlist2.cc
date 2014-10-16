#include <iostream>

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
        this->_front = this->_back = 0;
    }

    ~linkedlist()
    {
        while(!empty())
            pop_back();
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

int main()
{
    linkedlist l;
    //l.init(); //linkedlist_init(l);

    int i;
    while(std::cin>>i)
        l.push_back(i);

    while(!l.empty())
    {
        std::cout<<l.back()<<std::endl;
        l.pop_back();
    }
    //l.destroy();
}
