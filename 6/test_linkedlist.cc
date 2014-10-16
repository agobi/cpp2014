#include "linkedlist.h"
#include <iostream>

struct rlinkedlist
{
    int value;
    rlinkedlist &next;
};

int main()
{
    rlinkedlist a = {0, a};

    linkedlist l;
    linkedlist_init(l);

    int i;
    while(std::cin>>i)
        linkedlist_push_back(l, i);

    while(!linkedlist_empty(l))
    {
        std::cout<<linkedlist_back(l)<<std::endl;
        linkedlist_pop_back(l);
    }

    linkedlist_destroy(l);
}
