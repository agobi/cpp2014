#include <iostream>

#include "linkedlist.h"

struct rlinkedlist
{
    int value;
    rlinkedlist &next;
};

int main()
{
    rlinkedlist a = {2, a};

    linkedlist list;
    init_linkedlist(list);

    int i;
    while(std::cin>>i)
    {
        push_back(list, i);
    }

    while(!empty(list))
    {
        std::cout<<back(list)<<std::endl;
        pop_back(list);
    }

    destroy_linkedlist(list);
}
