#include <iostream>

struct linkedlist
{
private:
    struct link
    {
        int value;
        link *prev, *next;
    };

    link *first, *last;


public:
    linkedlist()
    {
        first = last = 0;
    }

    ~linkedlist()
    {
        while(!this->empty())
            this->pop_back();
    }

    int back()
    {
        return this->last->value;
    }

    void push_back(int value)
    {
        link *p = new link;
        p->prev = this->last;
        p->next = 0;
        p->value = value;

        if(this->last)
            this->last->next = p;
        else
            this->first = p;
        this->last = p;
    }

    void pop_back()
    {
        link *p = this->last;
        this->last = this->last->prev;
        delete p;
    }

    bool empty()
    {
        return !this->last;
    }
};

int main() {
    linkedlist l;

    int i;
    while(std::cin>>i)
    {
        l.push_back(i);
    }

    while(!l.empty())
    {
        std::cout<<l.back()<<std::endl;
        l.pop_back();
    }
}
