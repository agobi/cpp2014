#include "linkedlist.h"

struct link
{
    int value;
    link *prev, *next;
};

struct s_linkedlist
{
    link *first, *last;
};

void init_linkedlist(linkedlist &l)
{
    l = new s_linkedlist;
    l->prev = l->next = 0;
}

void destroy_linkedlist(linkedlist &l)
{
    while(!empty(l))
        pop_back(l);
    delete l;
}

int back(linkedlist l)
{
    // (*l).last == l->last vs.  *(l.last) == *l.last
    return l->last->value;
}

void push_back(linkedlist l, int value)
{
    link *p = new link;
    p->prev = l->last;
    p->next = 0;
    p->value = value;

    if(l->last)
        l->last->next = p;
    else
        l->first = p;
    l->last = p;
}

void pop_back(linkedlist l)
{
    link *p = l->last;
    l->last = l->last->prev;
    delete p;
}

bool empty(linkedlist l)
{
    return !l->last;
}
