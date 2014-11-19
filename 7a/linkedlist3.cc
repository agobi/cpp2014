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
        while(!empty())
            pop_back();
    }

    int back()
    {
        return last->value;
    }

    void push_back(int value)
    {
        link *p = new link;
        p->prev = last;
        p->next = 0;
        p->value = value;

        if(last)
            last->next = p;
        else
            first = p;
        last = p;
    }

    void pop_back()
    {
        link *p = last;
        last = last->prev;
        if(!last) first=0;
        delete p;
    }

    bool empty()
    {
        return !last;
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

    print_list(l);
    print_list(l);
}
